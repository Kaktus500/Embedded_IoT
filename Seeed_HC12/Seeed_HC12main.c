// Seeed_HC12main.c
// Runs on MSP432
// Lab 1 start project for ECE382V, Technology for Embedded IoT
// Use the SysTick timer to request interrupts at a particular period.
// Jonathan Valvano
// August 12, 2022

/* This example accompanies the book
   "Embedded Systems: Introduction to Robotics,
   Jonathan W. Valvano, ISBN: 9781074544300, copyright (c) 2020
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


// built-in LED1 connected to P1.0
// P1.0, P2.0 are an output to profiling scope/logic analyzer
// UART output to PC for debugging
//   UCA2RXD (VCP receive) connected to P3.2
//   UCA2TXD (VCP transmit) connected to P3.3
// HC12 pin connections
//   5 SET to GPIO      J2.18 from LaunchPad to HC12  (GPIO output){MSP432 P3.0}
//   4 SO to serial RxD J1.3 from HC12 to LaunchPad (UCA2TXD RxD){MSP432 P3.2}
//   3 SI to serial TxD J1.4 from LaunchPad to HC12  (UCA2TXD TxD){MSP432 P3.3}
//   2 GND
//   1 VCC 1N4004 diode to +5V Vin (plus side of diode on +5V)
//   Power pin, the requirements of 3.2V to 5.5V
//   DC power supply, the supply current is not less
//   than 200mA. Note: If the module is to work
//   for a long time in the transmit state, it is
//   recommended that the power supply voltage
//   of more than 4.5V when connected to a
//   1N4007/1N4004 diode, to avoid the module built-in
//   LDO fever.
// SSD1306 LCD connections to I2CB1
//   GND    ground
//   VIN    3.3V
//   SDA    SSD1306 SDA <> P6.4 I2C data SDA_S
//   SCL    SSD1306 SCL <- P6.5 I2C clock SCL_S with 1.5k pullup to 3.3V

#include <stdint.h>
#include <stdio.h>
#include "msp.h"
#include "..\inc\CortexM.h"
#include "..\inc\SysTickInts.h"
#include "..\inc\LaunchPad.h"
#include "..\inc\Clock.h"
#include "..\inc\UART0.h"
#include "..\inc\UART1.h"
#include "..\inc\SSD1306_I2C.h"
volatile uint32_t Time,MainCount;
#define LEDOUT (*((volatile uint8_t *)(0x42098040)))
// P3->OUT is 8-bit port at 0x4000.4C22
// I/O address be 0x4000.0000+n, and let b represent the bit 0 to 7.
// n=0x4C22, b=0
// bit banded address is 0x4200.0000 + 32*n + 4*b
#define SET (*((volatile uint8_t *)(0x42098440)))
char HC12data;
uint32_t Message;
int Flag; // semaphore
uint8_t seqInd = 0;
uint8_t btnLatch = 0;
uint8_t sendFlg = 0;
uint8_t waitFlg = 0;
uint8_t waitCnt = 0;
uint8_t oldInput = 0;
// every 10ms

void simple_delay(uint32_t max){
    for(uint32_t i=0; i<max; i++){}
}

struct msgTemplate{
    uint16_t dst_address;
    uint16_t src_address;
    uint8_t  header; //length(0x1~0x8), acknowledge(0xff), broadcast(0xaa) response(0xfd, 0xfe)
    uint8_t  crc; // sum % 19
    char*    msg;
};
const struct msgTemplate defaultMsg = {0,0,0,0,0};
//const struct msgTemplate msgSend = {0xbead, 0xfeed, 5, 5, "seeed"}; // 's' = 115, 'e' = 101, 'd' = 100
//const struct msgTemplate msgSend2 = {0xcafe, 0xfeed, 5, 11, "deeef"}; // 'f' = 102
const struct msgTemplate msgDebug = {0xbeaf, 0xfeed, 5, 5, "seeed"}; // for debug
const struct msgTemplate msgAck  = {0xfeed, 0xbead, 0xff, 5, "seeed"}; // acknowledgment
const struct msgTemplate msgBroadcast = {0xfeed, 0xfeed, 0xaa, 5, "seeed"}; // broadcast message
const struct msgTemplate msgRespond1 = {0xfeed, 0xfeed, 0xfd, 5, "seeed"}; // broadcast respond for the second device
const struct msgTemplate msgRespond2 = {0xfeed, 0xfeed, 0xfe, 5, "seeed"}; // broadcast respond for the third device
struct msgTemplate msgReceived, msgSendCpy;
struct msgTemplate msgSend, msgSend2;
char* receiveBuffer;
int   validMsg;
const uint16_t idx[3] = {0xfeed, 0xbead, 0xcafe};

uint16_t thisID = 0xfeed;
int thisIDptr = 0;
int deviceCnt = 1;

/*msgSend.src_address = 0; // source = board 0
msgSend.dst_address = 1; // destination = board 1
msgSend.crc = 76; // valid
msgSend.header = 5; //length = 5
msgSend.msg = "seeed";
msgSend.termination = '1'; //terminating

msgAck.src_address = 1;
msgAck.dst_address = 0;
msgAck.crc = 76; //valid
msgAck.header = 255; //acknowledge*/

void Send_Msg(struct msgTemplate msgSend){
  HC12data = (msgSend.dst_address & 0xFF);
  UART1_OutChar(HC12data);
  HC12data = (msgSend.dst_address & 0xFF00) >> 8;
  UART1_OutChar(HC12data);
  HC12data = (msgSend.src_address & 0xFF);
  UART1_OutChar(HC12data);
  HC12data = (msgSend.src_address & 0xFF00) >> 8;
  UART1_OutChar(HC12data);
  HC12data = msgSend.header;
  UART1_OutChar(HC12data);
  HC12data = msgSend.crc;
  UART1_OutChar(HC12data);
  UART1_OutString(msgSend.msg);
};

void Read_Msg(char* msgRead){
    uint8_t in;
    //uint32_t test;
    //test = UART1_InStatus();
    //in = UART1_InCharNonBlock();
    uint8_t cnt = 0;
    //if(test > 10){
        in = UART1_InCharNonBlock();
     while(in){
       if(cnt < 256){
           *msgRead = in;
           msgRead++;
       }
       in = UART1_InCharNonBlock();
       cnt++;
       simple_delay(5000);
     }
    //}
}

int Parse_Check_Msg(char* msgRead){
    //1 = receiving normal message
    //2 = receiving acknowledgment
    //3 = receiving broadcast (only device 1)
    //4 = receiving response to broadcast for assigning idx[1]
    //5 = receiving response to broadcast for assigning idx[2]
    //0 = not receiving valid message
    msgReceived.dst_address = 0;
    msgReceived.dst_address = msgRead[1];
    msgReceived.dst_address = msgReceived.dst_address << 8;
    msgReceived.dst_address += msgRead[0];

    //if(msgReceived.dst_address != idx[0] && msgReceived.dst_address != idx[1] && msgReceived.dst_address != idx[2])
    //    return 0;
    if(msgReceived.dst_address != thisID)
        return 0;

    msgReceived.src_address = 0;
    msgReceived.src_address = msgRead[3];
    msgReceived.src_address = msgReceived.src_address << 8;
    msgReceived.src_address += msgRead[2];

    msgReceived.header = msgRead[4];
    msgReceived.crc = msgRead[5];

    if(msgReceived.header == 0xff){
        if(msgReceived.crc == msgSendCpy.crc)
            return 2;
        else
            return 0;
    }
    else if(msgReceived.header == 0xaa){
        if(thisID == idx[0])
            return 3;
        else
            return 0;
    }
    else if(msgReceived.header == 0xfd){
        return 4;
    }
    else if(msgReceived.header == 0xfe){
        return 5;
    }

    uint8_t cnt = msgReceived.header;
    uint8_t cnt_inv = 0;
    int msgSum = 0;

    while(cnt > 0){
        *(msgReceived.msg + cnt_inv) = msgRead[6 + cnt_inv];
        msgSum += msgRead[6 + cnt_inv];
        cnt--;
        cnt_inv++;
    }
    //crc check
    msgSum = msgSum % 19;
    if(msgSum != msgReceived.crc)
        return 0;

    return 1;
}

void SysTick_Handler(void){
  uint8_t in;
  Time = Time + 1;
  uint8_t ThisInput = LaunchPad_Input();   // either button
  if(ThisInput && (!btnLatch)){
      btnLatch = 1;
  }

  if(ThisInput && !oldInput && !sendFlg)
      sendFlg = 1;
  else if(ThisInput && !oldInput && sendFlg)
      sendFlg = 0;

  /*if(sendFlg){
    if((Time%100) == 0){ // 1 Hz
        //LaunchPad_Output(0);
      if(seqInd == 0){
          HC12data = '0';
          Message = 0;
          LaunchPad_Output(4);
          UART1_OutChar(HC12data);
          seqInd++;
          Flag = 1;
      }else if(seqInd == 1){
          HC12data = '1';
          Message = 1;
          LaunchPad_Output(4);
          UART1_OutChar(HC12data);
          seqInd++;
          Flag = 1;
      }else if(seqInd == 2){
          HC12data = '2';
          Message = 2;
          LaunchPad_Output(4);
          UART1_OutChar(HC12data);
          seqInd = 0;
          Flag = 1;
      }else{
          seqInd = 0;
          btnLatch = 0;
      }
    }
  }*/
  if(sendFlg){
      if((Time%100) == 0){ // 3 Hz
        if(seqInd == 0){
            if(!waitFlg)
                Send_Msg(msgSend);
            msgSendCpy = msgSend;
            Message = 0;
            LaunchPad_Output(4);
            //UART1_OutChar(HC12data);
            seqInd++;
            Flag = 1;
            waitFlg = 1;
        }else if(seqInd == 1){
            //HC12data = '1';
            if(!waitFlg)
                Send_Msg(msgSend2);
            msgSendCpy = msgSend2;
            Message = 1;
            LaunchPad_Output(4);
            //UART1_OutChar(HC12data);
            seqInd++;
            Flag = 1;
            waitFlg = 1;
        }else if(seqInd == 2){
            //HC12data = '2';
            if(!waitFlg)
                Send_Msg(msgDebug);
            msgSendCpy = msgDebug;
            Message = 2;
            LaunchPad_Output(4);
            //UART1_OutChar(HC12data);
            seqInd = 0;
            Flag = 1;
            waitFlg = 1;
        }else{
            seqInd = 0;
            btnLatch = 0;
        }
      }
    }
  msgReceived = defaultMsg;
  Read_Msg(receiveBuffer);
  if(*receiveBuffer)
      printf("%s", receiveBuffer);

  validMsg = Parse_Check_Msg(receiveBuffer);
  for(int ii = 0; ii < 256; ii++)
      *(receiveBuffer+ii) = 0;
  if(validMsg == 1){
      //if((Time/100)%2)
          //msgReceived.dst_address = 0xffff;
      msgReceived.header = 0xff;
      msgReceived.dst_address = msgReceived.src_address;
      msgReceived.src_address = thisID;
      Send_Msg(msgReceived);
      Message = 3;
      Flag = 1;
      //LaunchPad_Output(1);
  }
  else if(validMsg == 2){
      Message = 6;
      Flag = 1;
      LaunchPad_Output(1);
      waitFlg = 0;
      waitCnt = 0;
  }
  else if(validMsg == 3){
      simple_delay(1000000);
      if(deviceCnt == 1){
          Send_Msg(msgRespond1);
          deviceCnt++;
      }
      else if(deviceCnt == 2){
          Send_Msg(msgRespond2);
          deviceCnt++;
      }
      Message = 7;
      Flag = 1;
      LaunchPad_Output(1);
  }
  else if(validMsg == 4){
      thisID = idx[1];
      thisIDptr = 1;
      Message = 8;
      Flag = 1;
      LaunchPad_Output(1);
  }
  else if(validMsg == 5){
      thisID = idx[2];
      thisIDptr = 2;
      Message = 9;
      Flag = 1;
      LaunchPad_Output(1);
  }
  validMsg = 0;

  if(waitFlg){
      waitCnt++;
      if(waitCnt >= 50){//wait acknowledgment for 150 ms
          Message = 10;
          Flag = 1;
          LaunchPad_Output(1);
          waitCnt = 0;
          waitFlg = 0;
      }
  }
  /*else{
      Message = 4;
      Flag = 1;
      LaunchPad_Output(2);
  }*/
  //in = UART1_InCharNonBlock();
  /*if(in){
    switch(in){
      case '0':
        Message = 3; // R0
        Flag = 1;    // signal
        LaunchPad_Output(1); // off
        break;
      case '1':
        Message = 4; // R1
        Flag = 1;    // signal
        LaunchPad_Output(1);
        break;
      case '2':
        Message = 5; // R1
        Flag = 1;    // signal
        LaunchPad_Output(1);
        break;
      default:
        printf(in);
    }
  }*/
  LEDOUT ^= 0x01;       // toggle P1.0
  oldInput = ThisInput;
}

void HC12_ReadAllInput(void){uint8_t in;
// flush receiver buffer
  in = UART1_InCharNonBlock();
  while(in){
    UART0_OutChar(in);
    in = UART1_InCharNonBlock();
  }
}

void HC12_Init(uint32_t baud){
  P3->SEL0 &= ~0x01;
  P3->SEL1 &= ~0x01;    // configure P3.0 as GPIO
  P3->DIR |= 0x01;      // make P3.0 out
  UART1_InitB(baud);    // serial port to HC12
  HC12data = '1';
  //************ configure the HC12 module**********************
  SET = 0;       // enter AT command mode
  Clock_Delay1ms(40);
  UART1_OutString("AT+B9600\n");  // UART baud rate set to 9600
  Clock_Delay1ms(50);
  HC12_ReadAllInput();
  UART1_OutString("AT+C007\n");   // channel 7 selected (001 to 100 valid)
  Clock_Delay1ms(50);
  HC12_ReadAllInput();
  UART1_OutString("AT+P8\n");    // highest power level (1 to 8)
  Clock_Delay1ms(50);
  HC12_ReadAllInput();
  UART1_OutString("AT+RF\n");    // read FU transmission mode (FU3)
  Clock_Delay1ms(50);
  HC12_ReadAllInput();
  UART1_OutString("AT+V\n");    // read firmware
  Clock_Delay1ms(50);
  HC12_ReadAllInput();
  SET = 1;  // exit AT command mode
  Clock_Delay1ms(200);
  HC12_ReadAllInput(); // remove any buffered input
  //************ configuration ended***********************
  printf("\nRF_XMT initialization done\n");
}
/**
 * main.c
 */
void main(void){int num=0;
  Clock_Init48MHz();        // running on crystal
  Time = MainCount = 0;
  receiveBuffer = (char *) malloc(256);
  *receiveBuffer = 0;
  SysTick_Init(480000,2);   // set up SysTick for 100 Hz interrupts
  LaunchPad_Init();         // P1.0 is red LED on LaunchPad
  UART0_Initprintf();       // serial port to PC for debugging
  SSD1306_Init(SSD1306_SWITCHCAPVCC);
  SSD1306_OutClear();
  SSD1306_SetCursor(0,0);
  SSD1306_OutString("----- ECE382V ------\n");
  SSD1306_OutString(" Lab 1\n");
  SSD1306_OutString(" Seeed_HC12 example\n");
  SSD1306_OutString(" Valvano\n");
  EnableInterrupts();
  printf("\nSeeed_HC12 example -Valvano\n");
  HC12_Init(UART1_BAUD_9600);
  //broadcast, setting idx
  Send_Msg(msgBroadcast);
  for(int ii = 0; ii < 8000000; ii++){
      if(Flag){
          Flag = 0;
          if(Message == 8){
              SSD1306_OutClear();
              SSD1306_OutString("idx[1] assigned\n");
          }
          else if(Message == 9){
              SSD1306_OutClear();
              SSD1306_OutString("idx[2] assigned\n");
          }
          break;
      }
  }
  msgSend.src_address  = thisID;
  msgSend2.src_address = thisID;
  if(thisIDptr == 0){
      msgSend.dst_address  = idx[1];
      msgSend.header       = 5;
      msgSend.crc          = 5;
      msgSend.msg          = "seeed";
      msgSend2.dst_address = idx[2];
      msgSend2.header      = 5;
      msgSend2.crc         = 11;
      msgSend2.msg         = "deeef";
  }
  else if(thisIDptr == 1){
      msgSend.dst_address  = idx[0];
      msgSend.header       = 5;
      msgSend.crc          = 4;
      msgSend.msg          = "aarrr";
      msgSend2.dst_address = idx[2];
      msgSend2.header      = 5;
      msgSend2.crc         = 6;
      msgSend2.msg         = "aarrt";
  }
  else if(thisIDptr == 2){
      msgSend.dst_address  = idx[0];
      msgSend.header       = 5;
      msgSend.crc          = 8;
      msgSend.msg          = "ccrrr";
      msgSend2.dst_address = idx[1];
      msgSend2.header      = 5;
      msgSend2.crc         = 10;
      msgSend2.msg         = "ddrrr";
  }
  else{
      msgSend  = defaultMsg;
      msgSend2 = defaultMsg;
  }
  //
  SSD1306_OutString(" RF_XMT init done\n");
  SSD1306_OutString("\nHold switch for 1s\n");

  /*struct msgTemplate msgSend = defaultMsg;
  struct msgTemplate msgAck  = defaultMsg;

  msgSend.src_address = 0; // source = board 0
  msgSend.dst_address = 1; // destination = board 1
  msgSend.crc = 76; // valid
  msgSend.header = 5; //length = 5
  msgSend.msg = "seeed";
  msgSend.termination = '1'; //terminating

  msgAck.src_address = 1;
  msgAck.dst_address = 0;
  msgAck.crc = 76; //valid
  msgAck.header = 255; //acknowledge*/

  while(1){ // USER Output in main (not ISR)
    WaitForInterrupt();

     // foreground thread
    MainCount++;
    if(Flag){ // wait on semaphore
      num++;
      if(num%8 == 1){
        SSD1306_OutClear();
      }
      SSD1306_OutUDec16(num);
      SSD1306_OutChar(' ');
      Flag = 0; //
      switch(Message){
        case 0:
          printf("S0\n");
          SSD1306_OutString("S0\n");
          LaunchPad_Output(0);
          break;
        case 1:
            printf("S1\n");
            SSD1306_OutString("S1\n");
            LaunchPad_Output(0);
            break;
        case 2:
            printf("S2\n");
            SSD1306_OutString("S2\n");
            LaunchPad_Output(0);
            break;
        case 3:
          printf("R0\n");
          SSD1306_OutString("R0\n");
          LaunchPad_Output(0);
          break;
        case 4:
          printf("R1\n");
          SSD1306_OutString("R1\n");
          LaunchPad_Output(0);
          break;
        case 5:
            printf("R2\n");
            SSD1306_OutString("R2\n");
            LaunchPad_Output(0);
            break;
        case 6:
            printf("A0\n");
            SSD1306_OutString("A0\n");
            LaunchPad_Output(0);
            break;
        case 7:
            printf("New device\n");
            SSD1306_OutString("New device\n");
            LaunchPad_Output(0);
            break;
        case 10:
            printf("F0\n");
            SSD1306_OutString("F0\n");
            LaunchPad_Output(0);
            break;
      }
    }
  }
}

