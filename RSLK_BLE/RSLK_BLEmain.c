//*****************************************************************************
// RSLK-MAX test main with CC2650 BoosterPack
// MSP432 with RSLK-MAX
// Starter code for Lab2 ECE382V Technology for IoT
// Daniel and Jonathan Valvano
// August 18, 2022
/* This example accompanies the book
   "Embedded Systems: Introduction to Robotics,
   Jonathan W. Valvano, ISBN: 9781074544300, copyright (c) 2022
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/

Simplified BSD License (FreeBSD License)
Copyright (c) 2022, Jonathan Valvano, All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are
those of the authors and should not be interpreted as representing official
policies, either expressed or implied, of the FreeBSD Project.
*/
/* Hardware requirements
    1- CC2650 BoosterPack, BOOSTXL-CC2650MA (this lab 2)
    1- CC3100 BoosterPack, CC3100BOOST (for Lab 3)
    1- RSLK robot with MSP432, TIRSLK-EVM
    1- Some robots have OPT3101 time of flight sensor, some do not
    6- 1.2V AA NiMH batteries and charger
 */
// ******************************************************************************************
// NOTE: For MSP432+CC2560BP+RSLK, change 153 in GPIO.h to leave in #define DEFAULT 1       *
// ******************************************************************************************

#include <stdint.h>
#include "msp.h"
#include "../inc/Clock.h"
#include "../inc/CortexM.h"
#include "../inc/PWM.h"
#include "../inc/LaunchPad.h"
#include "../inc/AP.h"
#include "../inc/UART0.h"
#include "../inc/Motor.h"
#include "../inc/Bump.h"
#include "../inc/LPF.h"
#include "../inc/TimerA1.h"
#include "../inc/blinker.h"
#include "../inc/TExaS.h"
#include "../inc/Reflectance.h"
#include "../inc/Tachometer.h"
#include "../inc/TA3InputCapture.h"
#include "../inc/SysTickInts.h"
#include "../inc/SSD1306.h"
#include "../inc/I2CB1.h"
#include "../inc/opt3101.h"
// OPT3101=0 if no OPT3101, OPT3101=1 if robot has OPT3101
#define OPT3101 1
#define ROBOT 2
uint16_t JackiCommand=0;

// ******************OPT3101************************
uint32_t Distances[3];
uint32_t FilteredDistances[3];
uint32_t Amplitudes[3];
uint32_t Noises[3];
uint32_t TxChannel;
uint32_t StartTime;
uint32_t TimeToConvert; // in msec
uint32_t StartChannel;
uint32_t LeftDistance,CenterDistance,RightDistance; // IR distances
uint16_t SensorData19[4];   // 3 distances and the bumper
void OPT3101_Start(void){
  I2CB1_Init(30); // baud rate = 12MHz/30=400kHz
  OPT3101_Init();
  OPT3101_Setup();
  OPT3101_CalibrateInternalCrosstalk();
  OPT3101_ArmInterrupts(&TxChannel, Distances, Amplitudes);
//  StartTime = SysTick->VAL;
  TxChannel = 3;
  StartChannel = 1;
  OPT3101_StartMeasurementChannel(StartChannel);
  LPF_Init(100,8);
  LPF_Init2(100,8);
  LPF_Init3(100,8);
}
// calibrated for 500mm track
// right is raw sensor data from right sensor
// return calibrated distance from center of Robot to right wall
int32_t OPT3101_RightDistance(int32_t right){
  return  (right*(59*right + 7305) + 2348974)/32768;
}
// left is raw sensor data from left sensor
// return calibrated distance from center of Robot to left wall
int32_t OPT3101_LeftDistance(int32_t left){
  return (1247*left)/2048 + 22;
}
void OPT3101_Process(void){ // called at 60 Hz
  if(TxChannel <= 2){ // 0,1,2 means new data
    if(TxChannel==0){
      FilteredDistances[0] = OPT3101_LeftDistance(LPF_Calc(Distances[0]));
    }else if(TxChannel==1){
      FilteredDistances[1] = LPF_Calc2(Distances[1]);
    }else {
      FilteredDistances[2] = OPT3101_RightDistance(LPF_Calc3(Distances[2]));
    }
    TxChannel = 3; // 3 means no data
    StartChannel = (StartChannel+1)%3;
  //  DisableInterrupts();
    OPT3101_StartMeasurementChannel(StartChannel);
  //  EnableInterrupts();
    LeftDistance   = SensorData19[0] = FilteredDistances[0];   // 16 bit versions
    CenterDistance = SensorData19[1] = FilteredDistances[1];
    RightDistance  = SensorData19[2] = FilteredDistances[2];
    SensorData19[3] = Bump_Read()+256*JackiCommand;

  }
}
// end of OPT3101 variables


// **********************BLE ************************************
uint16_t JackiBumpSensor=0;
uint16_t JackiDirection; // steering control
uint16_t JackiPower;     // overall power
//uint16_t JackiSpeed[2]={1000,1000}; // steering control, and overall speed
uint16_t Switch1;       // 16-bit notify data from Button 1
uint32_t Switch2;       // 32-bit notify data from Button 2
uint32_t time=0;

int32_t Right,Left;
uint8_t NPI_GATTSetDeviceNameJacki19[] = {
  SOF,15,0x00,    // length = 15
//  SOF,18,0x00,    // length = 18
  0x35,0x8C,      // SNP Set GATT Parameter (0x8C)
  0x01,           // Generic Access Service
  0x00,0x00,      // Device Name
//  'J','a','c','k','i',' ','A','S','E','E',' ','0',
  'J','a','c','k','i',' ','R','S','L','K',' ','0',
//    'R','S','L','K',' ','E','x','p','l','o','r','e','r',' ','0',
  0x77};          // FCS (calculated by AP_SendMessageResponse)
uint8_t NPI_SetAdvertisementDataJacki19[] = {
  SOF,24,0x00,    // length = 24
//  SOF,27,0x00,    // length = 27
  0x55,0x43,      // SNP Set Advertisement Data
  0x00,           // Scan Response Data
  13,0x09,        // length, type=LOCAL_NAME_COMPLETE
//  'J','a','c','k','i',' ','A','S','E','E',' ','0',
  'J','a','c','k','i',' ','R','S','L','K',' ','0',
//    'R','S','L','K',' ','E','x','p','l','o','r','e','r',' ','0',

// connection interval range
  0x05,           // length of this data
  0x12,           // GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE
  0x50,0x00,      // DEFAULT_DESIRED_MIN_CONN_INTERVAL
  0x20,0x03,      // DEFAULT_DESIRED_MAX_CONN_INTERVAL
// Tx power level
  0x02,           // length of this data
  0x0A,           // GAP_ADTYPE_POWER_LEVEL
  0x00,           // 0dBm
  0x77};          // FCS (calculated by AP_SendMessageResponse)
#define RECVSIZE 128
extern uint8_t RecvBuf[RECVSIZE];
extern const uint8_t NPI_SetAdvertisement1[];
extern const uint8_t NPI_StartAdvertisement[];
//*************AP_StartAdvertisementJacki**************
// Start advertisement for Jacki
// Input:  num is robot number 0 to 99
// Output: APOK if successful,
//         APFAIL if notification not configured, or if SNP failure
int AP_StartAdvertisementJacki19(uint8_t num){volatile int r;
  if(num<10){
    NPI_GATTSetDeviceNameJacki19[18] = ' ';
    NPI_GATTSetDeviceNameJacki19[19] = '0'+num%10;
    NPI_SetAdvertisementDataJacki19[18] = ' ';
    NPI_SetAdvertisementDataJacki19[19] = '0'+num%10;
//    NPI_GATTSetDeviceNameJacki19[21] = ' ';
//    NPI_GATTSetDeviceNameJacki19[22] = '0'+num%10;
//    NPI_SetAdvertisementDataJacki19[21] = ' ';
//    NPI_SetAdvertisementDataJacki19[22] = '0'+num%10;
  }else{
    num = num%100; // 0 to 99
    NPI_GATTSetDeviceNameJacki19[18] = '0'+num/10;
    NPI_GATTSetDeviceNameJacki19[19] = '0'+num%10;
    NPI_SetAdvertisementDataJacki19[18] = '0'+num/10;
    NPI_SetAdvertisementDataJacki19[19] = '0'+num%10;
//    NPI_GATTSetDeviceNameJacki19[21] = '0'+num/10;
//    NPI_GATTSetDeviceNameJacki19[22] = '0'+num%10;
//    NPI_SetAdvertisementDataJacki19[21] = '0'+num/10;
//    NPI_SetAdvertisementDataJacki19[22] = '0'+num%10;
  }
  r =AP_SendMessageResponse((uint8_t*)NPI_GATTSetDeviceNameJacki19,RecvBuf,RECVSIZE);
  r =AP_SendMessageResponse((uint8_t*)NPI_SetAdvertisement1,RecvBuf,RECVSIZE);
  r =AP_SendMessageResponse((uint8_t*)NPI_SetAdvertisementDataJacki19,RecvBuf,RECVSIZE);
  r =AP_SendMessageResponse((uint8_t*)NPI_StartAdvertisement,RecvBuf,RECVSIZE);
  return r;
}

// ********OutValue**********
// Debugging dump of a data value to virtual serial port to PC
// data shown as 1 to 8 hexadecimal characters
// Inputs:  response (number returned by last AP call)
// Outputs: none
void OutValue(char *label,uint32_t value){
  UART0_OutString(label);
  UART0_OutUHex(value);
}
void ReadCommand(void){ // called on a SNP Characteristic Read Indication for characteristic JackiCommand
  OutValue("\n\rRead JackiCommand=",JackiCommand);
}
void ReadJackiBumpSensor(void){ // called on a SNP Characteristic Read Indication for characteristic JackiSensor
  JackiBumpSensor = Bump_Read();
  OutValue("\n\rRead JackiBumpSensor=",JackiBumpSensor);
}
void RunJacki(void){
  if((JackiCommand==0)||(JackiCommand>6)||(Bump_Read()&&(JackiCommand!=2))){
    JackiCommand = 0;
    UART0_OutString(" Stop");
    Blinker_Output(BK_RGHT+BK_LEFT);
    Motor_Stop();
  }
  if(JackiDirection>4000){
      JackiDirection = 4000; // direction
  }
  if(JackiPower>14000){
      JackiPower = 14000; // overall speed
  }
  if(JackiCommand==1){
    UART0_OutString(" Go");
    Blinker_Output(FR_RGHT+FR_LEFT);
    // steering control, and overall speed
    Right = JackiPower+(JackiPower*(2000-JackiDirection))/2000;
    Left = JackiPower+(JackiPower*(JackiDirection-2000))/2000;
    if(Left>14000){
      Left = 14000;
    }
    if(Right>14000){
      Right = 14000;
    }
    Motor_Forward(Left,Right);
  }
  if(JackiCommand==2){
    UART0_OutString(" Back");
    Blinker_Output(BK_RGHT+BK_LEFT);
    Motor_Backward(JackiPower,JackiPower);
    time=0;
  }
  if(JackiCommand==3){
    UART0_OutString(" Right");
    Blinker_Output(FR_RGHT);
    Motor_Right(JackiPower,JackiPower);
    time=0;
  }
  if(JackiCommand==4){
    UART0_OutString(" Left");
    Blinker_Output(FR_LEFT);
    Motor_Left(JackiPower,JackiPower);
    time=0;
  }
  if(JackiCommand==5){
    UART0_OutString(" Gentle Right");
    Blinker_Output(FR_RGHT);
    Motor_Forward(JackiPower,(3*JackiPower)/4);
  }
  if(JackiCommand==6){
    UART0_OutString(" Gentle Left");
    Blinker_Output(FR_LEFT);
    Motor_Forward((3*JackiPower)/4,JackiPower);
  }
}
void WriteCommand(void){ // called on a SNP Characteristic Write Indication on characteristic JackiCommand
  OutValue("\n\rWrite JackiCommand=",JackiCommand);
  RunJacki();
}
void ReadJackiPower(void){ // called on a SNP Characteristic Read Indication for characteristic JackiPower
  OutValue("\n\rRead JackiPower=",JackiPower);
}
void WriteJackiPower(void){  // called on a SNP Characteristic Write Indication on characteristic JackiPower
  OutValue("\n\rWrite JackiPower=",JackiPower);
  RunJacki();
}
void ReadJackiDirection(void){ // called on a SNP Characteristic Read Indication for characteristic JackiDirection
  OutValue("\n\rRead JackiDirection=",JackiDirection);
}
void WriteJackiDirection(void){  // called on a SNP Characteristic Write Indication on characteristic JackiDirection
  OutValue("\n\rWrite JackiDirection=",JackiDirection);
  RunJacki();
}
void ReadDistance(void){
  OutValue("\n\rRead Left Distance=",SensorData19[0]);
  OutValue("\n\rRead Center Distance=",SensorData19[1]);
  OutValue("\n\rRead Right Distance=",SensorData19[2]);
  OutValue("\n\rBump Sensors=",0xff&SensorData19[3]);
}

void Bumper(void){ // called on SNP CCCD Updated Indication
  JackiBumpSensor = Bump_Read();
  OutValue("\n\rCCCD=",AP_GetNotifyCCCD(0));
}
void BLE_Init(uint8_t num){volatile int r;
  UART0_Init();
  EnableInterrupts();
  UART0_OutString("\n\rJacki test project - MSP432-CC2650\n\r");
  r = AP_Init();
  AP_GetStatus();  // optional
  AP_GetVersion(); // optional
  AP_AddService(0xFFF0);
  //------------------------
  JackiCommand = 0;  // read/write parameter
  AP_AddCharacteristic(0xFFF1,2,&JackiCommand,0x03,0x0A,"JackiCommand",&ReadCommand,&WriteCommand);
  //------------------------
  JackiBumpSensor = Bump_Read(); // read only parameter (get from bump sensors)
  AP_AddCharacteristic(0xFFF2,2,&JackiBumpSensor,0x01,0x02,"JackiBumpSensor",&ReadJackiBumpSensor,0);
  //------------------------
  JackiDirection = 2000;   // read/write parameter
  AP_AddCharacteristic(0xFFF3,2,&JackiDirection,0x03,0x0A,"JackiDirection",&ReadJackiDirection,&WriteJackiDirection);
  //------------------------
  JackiPower = 2000;   // read/write parameter
  AP_AddCharacteristic(0xFFF4,2,&JackiPower,0x03,0x0A,"JackiPower",&ReadJackiPower,&WriteJackiPower);
  //------------------------
#if OPT3101
  // four 16-bit read only parameters (get from OPT3101 distance sensor)
  AP_AddCharacteristic(0xFFF5,8,SensorData19,0x01,0x02,"JackSensors",&ReadDistance,0);
#endif
  //------------------------
  AP_AddNotifyCharacteristic(0xFFF6,2,&JackiBumpSensor,"Bumper",&Bumper);
  AP_RegisterService();
  AP_StartAdvertisementJacki19(num);
  AP_GetStatus(); // optional
}


// #define OPT3101=0 if no OPT3101, OPT3101=1 if robot has OPT3101
int main(void){
uint32_t time2 = 0;    // incremented with every pass through main loop
int i=0;
uint8_t last;
  Clock_Init48MHz();
  LaunchPad_Init();   // built-in switches and LEDs
#if OPT3101
  OPT3101_Start();
#endif
  Bump_Init();        // bump switches
  Blinker_Init();     // blinker LEDs

  SSD1306_Init(SSD1306_SWITCHCAPVCC);
  SSD1306_Clear();
  SSD1306_SetCursor(0,0); SSD1306_OutString("RSLK 1.1, Valvano");
#if OPT3101
  SSD1306_SetCursor(0,1); SSD1306_OutString("BLE with OPT3101");
#else
  SSD1306_SetCursor(0,1); SSD1306_OutString("BLE, no OPT3101");
#endif
  SSD1306_SetCursor(0,2); SSD1306_OutString("Robot ");SSD1306_OutUDec16(ROBOT);
  SSD1306_SetCursor(0,3); SSD1306_OutString("Bumper to start");
  do{ // wait for touch
    Clock_Delay1ms(250);
    LaunchPad_Output(0); // off
    Blinker_Output(FR_RGHT+BK_LEFT);
    Clock_Delay1ms(250);
    if(i<=ROBOT){
      LaunchPad_Output(3); // red/green
      Blinker_Output(BK_RGHT+FR_LEFT);
    }
    i = (i+1)%(ROBOT+4);
    JackiBumpSensor = Bump_Read();
  }while (JackiBumpSensor == 0);

  i = 0;
  JackiBumpSensor = Bump_Read();
  Motor_Stop();
  Blinker_Output(BK_RGHT+BK_LEFT);

  SSD1306_Clear();
  SSD1306_SetCursor(0, 0);           // zero leading spaces, first row
  SSD1306_OutString("RSLK BLE"); SSD1306_OutUDec2(ROBOT);
#if OPT3101
  SSD1306_SetCursor(0, 1); SSD1306_OutString("left      mm");
  SSD1306_SetCursor(0, 2); SSD1306_OutString("center    mm");
  SSD1306_SetCursor(0, 3); SSD1306_OutString("right     mm");
#endif
  SSD1306_SetCursor(0, 5); SSD1306_OutString("Bump        ");
  BLE_Init(ROBOT);
  EnableInterrupts();
  last = LaunchPad_Input();
  while(1){
    time++;
    AP_BackgroundProcess();  // handle incoming SNP frames

    // if bump sensor, then stop
    if(((JackiCommand>1)&&(JackiCommand<5)&&(time>250000))||(JackiCommand>6)||(Bump_Read()&&(JackiCommand!=2))){
      JackiCommand=0;
      Motor_Stop();
    }

    JackiBumpSensor = LaunchPad_Input();
    if(((last&0x01)==0)&&(JackiBumpSensor&0x01)){
      Clock_Delay1ms(2);  // debounce
      if(JackiCommand==0){
        JackiCommand = 1;
        RunJacki();
      }
    }
    if(((last&0x02)==0)&&(JackiBumpSensor&0x02)){
      Clock_Delay1ms(2);  // debounce
      if(JackiPower<12000){
          JackiPower += 2000;

      }else{
          JackiPower = 1000;
      }
      RunJacki();
    }
    if(((last&0x03))&&(JackiBumpSensor&0x03)!=0x03){
      Clock_Delay1ms(2);  // debounce
    }
    last = JackiBumpSensor;
    time2 = time2 + 1;
    // the constant 177770 determines the period between notifications
    if(time2 >= 177770){         // calibration value is basically a guess to get about 1 Hz
      time2 = 0;
      if(AP_GetNotifyCCCD(0)){
        JackiBumpSensor = Bump_Read(); // get from bump sensors
        OutValue("\n\rNotify Bumpers=",JackiBumpSensor);
        AP_SendNotification(0);
      }
      // take IR distance measurements
      LaunchPad_Output((i&0x01)<<2);     // toggle the blue LED
      // print distance average
#if OPT3101
      SSD1306_SetCursor(5, 1);       // five leading spaces, second row
      SSD1306_OutUDec(LeftDistance);
      SSD1306_SetCursor(5, 2);       // five leading spaces, third row
      SSD1306_OutUDec(CenterDistance);
      SSD1306_SetCursor(5, 3);       // five leading spaces, fourth row
      SSD1306_OutUDec(RightDistance);
#endif
      // print the status of the bump sensors
      JackiBumpSensor = Bump_Read();
      SSD1306_SetCursor(5, 5);       // five leading spaces, sixth row
      if((JackiBumpSensor&0x01) == 0){
        SSD1306_OutChar('0');
      }else{
        SSD1306_OutChar(' ');
      }
      if((JackiBumpSensor&0x02) == 0){
        SSD1306_OutChar('1');
      }else{
        SSD1306_OutChar(' ');
      }
      if((JackiBumpSensor&0x04) == 0){
        SSD1306_OutChar('2');
      }else{
        SSD1306_OutChar(' ');
      }
      if((JackiBumpSensor&0x08) == 0){
        SSD1306_OutChar('3');
      }else{
        SSD1306_OutChar(' ');
      }
      if((JackiBumpSensor&0x10) == 0){
        SSD1306_OutChar('4');
      }else{
        SSD1306_OutChar(' ');
      }
      if((JackiBumpSensor&0x20) == 0){
        SSD1306_OutChar('5');
      }else{
        SSD1306_OutChar(' ');
      }
    }
#if OPT3101
    OPT3101_Process();
#endif
  }
}









