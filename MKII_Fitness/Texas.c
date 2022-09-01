// *****************Texas.c**************
// grading engine for Lab 1
//
// Runs on MSP432
// Uses the general board support package on the MSP432.

// Daniel and Jonathan Valvano
// July 19, 2016

/* This example accompanies the books
   "Embedded Systems: Real Time Interfacing to ARM Cortex M Microcontrollers",
   ISBN: 978-1463590154, Jonathan Valvano, copyright (c) 2016

   "Embedded Systems: Real-Time Operating Systems for ARM Cortex-M Microcontrollers",
   ISBN: 978-1466468863, Jonathan Valvano, copyright (c) 2016

 Copyright 2016 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

//  J1   J3               J4   J2
// [ 1] [21]             [40] [20]
// [ 2] [22]             [39] [19]
// [ 3] [23]             [38] [18]
// [ 4] [24]             [37] [17]
// [ 5] [25]             [36] [16]
// [ 6] [26]             [35] [15]
// [ 7] [27]             [34] [14]
// [ 8] [28]             [33] [13]
// [ 9] [29]             [32] [12]
// [10] [30]             [31] [11]

// +3.3V connected to J1.1 (power)
// joystick horizontal (X) connected to J1.2 (analog)
// UART from BoosterPack to LaunchPad connected to J1.3 (UART)
// UART from LaunchPad to BoosterPack connected to J1.4 (UART)
// joystick Select button connected to J1.5 (digital)
// microphone connected to J1.6 (analog)
// LCD SPI clock connected to J1.7 (SPI)
// ambient light (OPT3001) interrupt connected to J1.8 (digital)
// ambient light (OPT3001) and temperature sensor (TMP006) I2C SCL connected to J1.9 (I2C)
// ambient light (OPT3001) and temperature sensor (TMP006) I2C SDA connected to J1.10 (I2C)

// temperature sensor (TMP006) interrupt connected to J2.11 (digital)
// nothing connected to J2.12 (SPI CS_Other)
// LCD SPI CS connected to J2.13 (SPI)
// nothing connected to J2.14 (SPI MISO)
// LCD SPI data connected to J2.15 (SPI)
// nothing connected to J2.16 (reset)
// LCD !RST connected to J2.17 (digital)
// nothing connected to J2.18 (SPI CS_Wireless)
// servo PWM connected to J2.19 (PWM)
// GND connected to J2.20 (ground)

// +5V connected to J3.21 (power)
// GND connected to J3.22 (ground)
// accelerometer X connected to J3.23 (analog)
// accelerometer Y connected to J3.24 (analog)
// accelerometer Z connected to J3.25 (analog)
// joystick vertical (Y) connected to J3.26 (analog)
// nothing connected to J3.27 (I2S WS)
// nothing connected to J3.28 (I2S SCLK)
// nothing connected to J3.29 (I2S SDout)
// nothing connected to J3.30 (I2S SDin)

// LCD RS connected to J4.31 (digital)
// user Button2 (bottom) connected to J4.32 (digital)
// user Button1 (top) connected to J4.33 (digital)
// gator hole switch connected to J4.34 (digital)
// nothing connected to J4.35
// nothing connected to J4.36
// RGB LED blue connected to J4.37 (PWM)
// RGB LED green connected to J4.38 (PWM)
// RGB LED red (jumper up) or LCD backlight (jumper down) connected to J4.39 (PWM)
// buzzer connected to J4.40 (PWM)

#include <stdint.h>
#include "../inc/BSP.h"
#include "../inc/CortexM.h"
#include "msp.h"
#include "TExaS.h"

void UART_Init(void);
void UART_OutChar(char data);
void UART_OutUDec(uint32_t n);
void UART_OutString(char *pt);
void UART_OutUDec4(uint32_t n);
void UART_OutUDec5(uint32_t n);
void UART_OutUDec7(uint32_t n);
void UART_OutUFix1(uint32_t n);
void static SetGrade(unsigned long lab, unsigned long grade, unsigned long id);

// standard ASCII symbols
#define CR   0x0D
#define LF   0x0A
#define BS   0x08
#define ESC  0x1B
#define SP   0x20
#define DEL  0x7F
char volatile LogicData;
uint32_t Id;
char MagicCode[10];
char EncriptedMagicCode[10];
//---------------- execution profile of tasks  ----------------
#define TOLERANCE 50   // 5.0%
#define PROFILESIZE0 9900
#define PROFILESIZE1 99
#define PROFILESIZE2 10
#define PROFILESIZE3 99
#define PROFILESIZE4 99
#define PROFILESIZE5 10
#define GRADETIME 10   // seconds
uint32_t TimeBuffer0[PROFILESIZE0];  // time started Task0
uint32_t Index0;
uint32_t TimeBuffer1[PROFILESIZE1];  // time started Task1
uint32_t Index1;
uint32_t TimeBuffer2[PROFILESIZE2];  // time started Task2
uint32_t Index2;
uint32_t TimeBuffer3[PROFILESIZE3];  // time started Task3
uint32_t Index3;
uint32_t TimeBuffer4[PROFILESIZE4];  // time started Task4
uint32_t Index4;
uint32_t TimeBuffer5[PROFILESIZE5];  // time started Task5
uint32_t Index5;
#define EXPECTED0 1000
#define EXPECTED1 100000
#define EXPECTED2 1000000
#define EXPECTED3 100000
#define EXPECTED4 100000
#define EXPECTED5 1000000
//uint32_t DumpNumber;
uint32_t Sum0,Sum1,Sum2,Sum3,Sum4,Sum5;
uint32_t Max0,Max1,Max2,Max3,Max4,Max5;
uint32_t Min0,Min1,Min2,Min3,Min4,Min5;
uint32_t Last0,Last1,Last2,Last3,Last4,Last5;
void LogicAnalyzer(void){ // called 10k/sec
  UCA0TXBUF = LogicData;  // send data to PC
}
void Grader(void){        // called once a second
//  uint32_t dt,sum,min,max,i;
  uint32_t ave,err,jitter;
  uint32_t grade=0;
  uint32_t static count=0; // grading time in seconds
  if(count>GRADETIME){ // done
    // run scoring
    TExaS_Stop();
    UART_OutString("\n\r**Done**\n\r");
    // Task 0
    ave = Sum0/(Index0-1);
    if(ave>=EXPECTED0){
      err = (1000*(ave-EXPECTED0))/EXPECTED0;
    }else{
      err = (1000*(EXPECTED0-ave))/EXPECTED0;
    }
    if(err < TOLERANCE) grade += 10;
    jitter = Max0-Min0;
    UART_OutString("\n\rTask0: Expected=");UART_OutUDec7(EXPECTED0);
    UART_OutString(", min="); UART_OutUDec7(Min0);
    UART_OutString(", max="); UART_OutUDec7(Max0);
    UART_OutString(", jitter="); UART_OutUDec5(jitter);
    UART_OutString(", ave="); UART_OutUDec7(ave);
    UART_OutString(" usec, error="); UART_OutUFix1(err);


    // Task 1
    ave = Sum1/(Index1-1);
    if(ave>=EXPECTED1){
      err = (1000*(ave-EXPECTED1))/EXPECTED1;
    }else{
      err = (1000*(EXPECTED1-ave))/EXPECTED1;
    }
    if(err < TOLERANCE) grade += 10;
    jitter = Max1-Min1;
    UART_OutString("\n\rTask1: Expected=");UART_OutUDec7(EXPECTED1);
    UART_OutString(", min="); UART_OutUDec7(Min1);
    UART_OutString(", max="); UART_OutUDec7(Max1);
    UART_OutString(", jitter="); UART_OutUDec5(jitter);
    UART_OutString(", ave="); UART_OutUDec7(ave);
    UART_OutString(" usec, error="); UART_OutUFix1(err);

    // Task 2
    ave = Sum2/(Index2-1);
    if(ave>=EXPECTED2){
      err = (1000*(ave-EXPECTED2))/EXPECTED2;
    }else{
      err = (1000*(EXPECTED2-ave))/EXPECTED2;
    }
    if(err < TOLERANCE) grade += 10;
    jitter = Max2-Min2;
    UART_OutString("\n\rTask2: Expected=");UART_OutUDec7(EXPECTED2);
    UART_OutString(", min="); UART_OutUDec7(Min2);
    UART_OutString(", max="); UART_OutUDec7(Max2);
    UART_OutString(", jitter="); UART_OutUDec5(jitter);
    UART_OutString(", ave="); UART_OutUDec7(ave);
    UART_OutString(" usec, error="); UART_OutUFix1(err);

    // Task 3
    ave = Sum3/(Index3-1);
    if(ave>=EXPECTED3){
      err = (1000*(ave-EXPECTED3))/EXPECTED3;
    }else{
      err = (1000*(EXPECTED3-ave))/EXPECTED3;
    }
    if(err < TOLERANCE) grade += 10;
    jitter = Max3-Min3;
    UART_OutString("\n\rTask3: Expected=");UART_OutUDec7(EXPECTED3);
    UART_OutString(", min="); UART_OutUDec7(Min3);
    UART_OutString(", max="); UART_OutUDec7(Max3);
    UART_OutString(", jitter="); UART_OutUDec5(jitter);
    UART_OutString(", ave="); UART_OutUDec7(ave);
    UART_OutString(" usec, error="); UART_OutUFix1(err);


    // Task 4
    ave = Sum4/(Index4-1);
    if(ave>=EXPECTED4){
      err = (1000*(ave-EXPECTED4))/EXPECTED4;
    }else{
      err = (1000*(EXPECTED4-ave))/EXPECTED4;
    }
    if(err < TOLERANCE) grade += 10;
    jitter = Max4-Min4;
    UART_OutString("\n\rTask4: Expected=");UART_OutUDec7(EXPECTED4);
    UART_OutString(", min="); UART_OutUDec7(Min4);
    UART_OutString(", max="); UART_OutUDec7(Max4);
    UART_OutString(", jitter="); UART_OutUDec5(jitter);
    UART_OutString(", ave="); UART_OutUDec7(ave);
    UART_OutString(" usec, error="); UART_OutUFix1(err);


    // Task 5
    ave = Sum5/(Index5-1);
    if(ave>=EXPECTED5){
      err = (1000*(ave-EXPECTED5))/EXPECTED5;
    }else{
      err = (1000*(EXPECTED5-ave))/EXPECTED5;
    }
    if(err < TOLERANCE) grade += 10;
    jitter = Max5-Min5;
    UART_OutString("\n\rTask5: Expected=");UART_OutUDec7(EXPECTED5);
    UART_OutString(", min="); UART_OutUDec7(Min5);
    UART_OutString(", max="); UART_OutUDec7(Max5);
    UART_OutString(", jitter="); UART_OutUDec5(jitter);
    UART_OutString(", ave="); UART_OutUDec7(ave);
    UART_OutString(" usec, error="); UART_OutUFix1(err);

    if(grade>=60)grade=100;
    UART_OutString("\n\rGrade= "); UART_OutUDec(grade);
    SetGrade(1,grade,Id);
    UART_OutString("\n\redX code= "); UART_OutString(EncriptedMagicCode);
    UART_OutString("\n\r");
//    if(DumpNumber){
//      UART_OutString("\n\r*******Profile Dump*******\n");
//      uint32_t time=0;
//      uint32_t i=0,i0=0,i1=0,i2=0,i3=0,i4=0,i5=0;
//      LogicData = 0x80; // bit 7 means logic data

//      while(i<DumpNumber){
//        if(TimeBuffer0[i0]==time){
//          UART_OutString("Task0: \t");
//          UART_OutUDec(time);
//          UART_OutString("\t us\n");
//          if(i0<PROFILESIZE0-1){
//            i0++; i++; LogicData^=0x01;
//          }else{
//            i=DumpNumber;// no more data
//          }
//        }
//        if(TimeBuffer1[i1]==time){
//          UART_OutString("Task1: \t");
//          UART_OutUDec(time);
//          UART_OutString("\t us\n");
//          if(i1<PROFILESIZE1-1){
//            i1++; i++; LogicData^=0x02;
//          }else{
//            i=DumpNumber;// no more data
//          }
//        }
//        if(TimeBuffer2[i2]==time){
//          UART_OutString("Task2: \t");
//          UART_OutUDec(time);
//          UART_OutString("\t us\n");
//          if(i2<PROFILESIZE2-1){
//            i2++; i++; LogicData^=0x04;
//          }else{
//            i=DumpNumber;// no more data
//          }
//        }
//        if(TimeBuffer3[i3]==time){
//          UART_OutString("Task3: \t");
//          UART_OutUDec(time);
//          UART_OutString("\t us\n");
//          if(i3<PROFILESIZE3-1){
//            i3++; i++;  LogicData^=0x08;
//          }else{
//            i=DumpNumber;// no more data
//          }
//        }
//        if(TimeBuffer4[i4]==time){
//          UART_OutString("Task4: \t");
//          UART_OutUDec(time);
//          UART_OutString("\t us\n");
//          if(i4<PROFILESIZE4-1){
//            i4++; i++;  LogicData^=0x10;
//          }else{
//            i=DumpNumber;// no more data
//          }
//        }
//        if(TimeBuffer5[i5]==time){
//          UART_OutString("Task5: \t");
//          UART_OutUDec(time);
//          UART_OutString("\t us\n");
//          if(i5<PROFILESIZE5-1){
//            i5++; i++;  LogicData^=0x20;
//          }else{
//            i=DumpNumber;// no more data
//          }
//        }
//        time++;
//        if((time%100)==0){
//          UART_OutChar(LogicData);
//        }
//      }
//    }
  }else{
//    UART_OutChar('0'+count%10);
    count++;
//    UART_OutString("\n\rTasks: ");
//    UART_OutUDec(Index0); UART_OutString(", ");
//    UART_OutUDec(Index1); UART_OutString(", ");
//    UART_OutUDec(Index2); UART_OutString(", ");
//    UART_OutUDec(Index3); UART_OutString(", ");
//    UART_OutUDec(Index4); UART_OutString(", ");
//    UART_OutUDec(Index5);
  }
}

// ------------PeriodicTask2_Init------------
// Activate an interrupt to run a user task periodically.
// Give it a priority 0 to 6 with lower numbers
// signifying higher priority.  Equal priority is
// handled sequentially.
// Input:  task is a pointer to a user function
//         freq is number of interrupts per second
//           1 Hz to 10 kHz
//         priority is a number 0 to 6
// Output: none
void (*PeriodicTask2)(void);   // user function
void PeriodicTask2_Init(void(*task)(void), uint32_t freq, uint8_t priority){//long sr;
  if((freq == 0) || (freq > 10000)){
    return;                        // invalid input
  }
  if(priority > 6){
    priority = 6;
  }
//  sr = StartCritical();
  PeriodicTask2 = task;            // user function
  // ***************** TimerA3 initialization *****************
  TIMER_A3->CTL &= ~0x0030;               // halt Timer A3
  // bits15-10=XXXXXX, reserved
  // bits9-8=01,       clock source to ACLK (32,768 Hz REFOCLK after BSP_Clock_InitFastest() called)
  // bits7-6=00,       input clock divider /1
  // bits5-4=00,       stop mode
  // bit3=X,           reserved
  // bit2=0,           set this bit to clear
  // bit1=0,           no interrupt on timer
  // bit0=0,           clear interrupt pending
  TIMER_A3->CTL = 0x0100;
  TIMER_A3->EX0 &= ~0x0007;               // configure for input clock divider /1
  // bits15-14=00,     no capture mode
  // bits13-12=XX,     capture/compare input select
  // bit11=X,          synchronize capture source
  // bit10=X,          synchronized capture/compare input
  // bit9=X,           reserved
  // bit8=0,           compare mode
  // bits7-5=XXX,      output mode
  // bit4=1,           enable capture/compare interrupt on CCIFG
  // bit3=X,           read capture/compare input from here
  // bit2=0,           output this value in output mode 0
  // bit1=X,           capture overflow status
  // bit0=0,           clear capture/compare interrupt pending
  TIMER_A3->CCTL[0] = 0x0010;
  TIMER_A3->CCR[0] = (32768/freq - 1);      // compare match value
// interrupts enabled in the main program after all devices initialized
  NVIC->IP[3] = (NVIC->IP[3]&0xFF00FFFF)|(priority<<21); // priority
  NVIC->ISER[0] = 0x00004000;         // enable interrupt 14 in NVIC
  TIMER_A3->CTL |= 0x0014;                // reset and start Timer A3 in up mode
//  EndCritical(sr);
}

void TA3_0_IRQHandler(void){
  TIMER_A3->CCTL[0] &= ~0x0001;             // acknowledge capture/compare interrupt 0
  (*PeriodicTask2)();              // execute user task
}

// ------------PeriodicTask2_Stop------------
// Deactivate the interrupt running a user task
// periodically.
// Input: none
// Output: none
void PeriodicTask2_Stop(void){
  TIMER_A3->CCTL[0] &= ~0x0001;             // clear capture/compare interrupt pending
  NVIC->ICER[0] = 0x00004000;         // disable interrupt 14 in NVIC
}

// ************TExaS_Init*****************
// Initialize grader, triggered by periodic timer
// This needs to be called once
// Inputs: Grading or Logic analyzer
// Outputs: none
void TExaS_Init(enum TExaSmode mode, uint32_t edXcode){
  // 32 bit free running timer
  // 10 kHz periodic interrupt
  // edge triggered interrupt on Profile bits
  // grade mode will collect 10 seconds of profile (4 arrays)
  // logic analyzer will 10 kHz output to serial port (pack 4 bits): 8 bit bit7 set then LA, but 7 ASCII
  Id = edXcode;
//  DumpNumber = dump;  // number of profile points to dump
  BSP_Time_Init();  // system timer in usec
  UART_Init();
  Index0 = Index1 = Index2 = Index3 = Index4 = Index5 = 0;
  Sum0   = Sum1   = Sum2   = Sum3   = Sum4   = Sum5   = 0;
  Min0   = Min1   = Min2   = Min3   = Min4   = Min5   = 0xFFFFFFFF;
  Max0   = Max1   = Max2   = Max3   = Max4   = Max5   = 0;

  LogicData |= 0x80; // bit 7 means logic data
  if(mode == LOGICANALYZER){
  // enable 10k periodic interrupt if logic analyzer mode
    PeriodicTask2_Init(&LogicAnalyzer,10000,5); // run grader
  }
  if(mode == GRADER){
    UART_OutString("\n\r**Start Lab 1 Grader**Version 1.00**10-sec run**\n\r");
    PeriodicTask2_Init(&Grader,1,5); // run grader
  }
}

// ************TExaS_Stop*****************
// Stop the transfer
// Inputs:  none
// Outputs: none
void TExaS_Stop(void){
  PeriodicTask2_Stop();
}

//------------UART_Init------------
// Initialize the UART for 115,200 baud rate
// SMCLK = 12 MHz
// 8 bit word length, no parity bits, one stop bit
// Input: none
// Output: none
void UART_Init(void){
  if(((P1->SEL0&0x0C)==0x0C)&&(EUSCI_A0->BRW==104))return; // already on
  EUSCI_A0->CTLW0 = 0x0001;                   // hold the USCI module in reset mode
  // bit15=0,      no parity bits
  // bit14=x,      not used when parity is disabled
  // bit13=0,      LSB first
  // bit12=0,      8-bit data length
  // bit11=0,      1 stop bit
  // bits10-8=000, asynchronous UART mode
  // bits7-6=11,   clock source to SMCLK
  // bit5=0,       reject erroneous characters and do not set flag
  // bit4=0,       do not set flag for break characters
  // bit3=0,       not dormant
  // bit2=0,       transmit data, not address (not used here)
  // bit1=0,       do not transmit break (not used here)
  // bit0=1,       hold logic in reset state while configuring
  EUSCI_A0->CTLW0 = 0x00C1;
                                        // set the baud rate
                                        // N = clock/baud rate = 12,000,000/115,200 = 104.1666667
  EUSCI_A0->BRW = 104;                        // UCBR = baud rate = int(N) = 104
  EUSCI_A0->MCTLW &= ~0xFFF1;                 // clear first and second modulation stage bit fields
                                        // configure second modulation stage select (from Table 22-4 on p731 of datasheet)
//  UCA0MCTLW |= (0<<8);                  // UCBRS = N - int(N) = 0.0417; plug this in Table 22-4
                                        // configure first modulation stage select (ignored when oversampling disabled)
//  UCA0MCTLW |= (10<<4);                 // UCBRF = int(((N/16) - int(N/16))*16) = 10
//  UCA0MCTLW |= 0x0001;                  // enable oversampling mode
  P1->SEL0 |= 0x0C;
  P1->SEL1 &= ~0x0C;                      // configure P1.3 and P1.2 as primary module function
  EUSCI_A0->CTLW0 &= ~0x0001;                 // enable the USCI module
  EUSCI_A0->IE &= ~0x000F;                    // disable interrupts (transmit ready, start received, transmit empty, receive full)
}

//------------UART_InChar------------
// Wait for new serial port input
// Input: none
// Output: ASCII code for key typed
char UART_InChar(void){
  while((EUSCI_A0->IFG&0x01) == 0);
  return((char)(EUSCI_A0->RXBUF));
}

//------------UART_OutChar------------
// Output 8-bit to serial port
// Input: letter is an 8-bit ASCII character to be transferred
// Output: none
void UART_OutChar(char data){
  while((EUSCI_A0->IFG&0x02) == 0);
  EUSCI_A0->TXBUF = data;
}

//------------UART_OutString------------
// Output String (NULL termination)
// Input: pointer to a NULL-terminated string to be transferred
// Output: none
void UART_OutString(char *pt){
  while(*pt){
    UART_OutChar(*pt);
    pt++;
  }
}

//------------UART_InUDec------------
// InUDec accepts ASCII input in unsigned decimal format
//     and converts to a 32-bit unsigned number
//     valid range is 0 to 4294967295 (2^32-1)
// Input: none
// Output: 32-bit unsigned number
// If you enter a number above 4294967295, it will return an incorrect value
// Backspace will remove last digit typed
uint32_t UART_InUDec(void){
uint32_t number=0, length=0;
char character;
  character = UART_InChar();
  while(character != CR){ // accepts until <enter> is typed
// The next line checks that the input is a digit, 0-9.
// If the character is not 0-9, it is ignored and not echoed
    if((character>='0') && (character<='9')) {
      number = 10*number+(character-'0');   // this line overflows if above 4294967295
      length++;
      UART_OutChar(character);
    }
// If the input is a backspace, then the return number is
// changed and a backspace is outputted to the screen
    else if((character==BS) && length){
      number /= 10;
      length--;
      UART_OutChar(character);
    }
    character = UART_InChar();
  }
  return number;
}

//-----------------------UART_OutUDec-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
void UART_OutUDec(uint32_t n){
// This function uses recursion to convert decimal number
//   of unspecified length as an ASCII string
  if(n >= 10){
    UART_OutUDec(n/10);
    n = n%10;
  }
  UART_OutChar(n+'0'); /* n is between 0 and 9 */
}
uint32_t Messageindexb;
char Messageb[8];
void static fillmessageb(uint32_t n){
// This function uses recursion to convert decimal number
//   of unspecified length as an ASCII string
  if(n >= 10){
    fillmessageb(n/10);
    n = n%10;
  }
  Messageb[Messageindexb] = (n+'0'); /* n is between 0 and 9 */
  if(Messageindexb<7)Messageindexb++;
}
void static fillmessage4b(uint32_t n){
  if(n>=1000){  // 1000 to 9999
    Messageindexb = 0;
  } else if(n>=100){  // 100 to 999
    Messageb[0] = ' ';
    Messageindexb = 1;
  }else if(n>=10){ //
    Messageb[0] = ' '; /* n is between 10 and 99 */
    Messageb[1] = ' ';
    Messageindexb = 2;
  }else{
    Messageb[0] = ' '; /* n is between 0 and 9 */
    Messageb[1] = ' ';
    Messageb[2] = ' ';
    Messageindexb = 3;
  }
  fillmessageb(n);
}
void static fillmessage5b(uint32_t n){
  if(n>99999)n=99999;
  if(n>=10000){  // 10000 to 99999
    Messageindexb = 0;
  } else if(n>=1000){  // 1000 to 9999
    Messageb[0] = ' ';
    Messageindexb = 1;
  }else if(n>=100){  // 100 to 999
    Messageb[0] = ' ';
    Messageb[1] = ' ';
    Messageindexb = 2;
  }else if(n>=10){ //
    Messageb[0] = ' '; /* n is between 10 and 99 */
    Messageb[1] = ' ';
    Messageb[2] = ' ';
    Messageindexb = 3;
  }else{
    Messageb[0] = ' '; /* n is between 0 and 9 */
    Messageb[1] = ' ';
    Messageb[2] = ' ';
    Messageb[3] = ' ';
    Messageindexb = 4;
  }
  fillmessageb(n);
}
void static fillmessage7b(uint32_t n){
  if(n>9999999)n=9999999;
  if(n>=1000000){  // 1000000 to 9999999
    Messageindexb = 0;
  } else if(n>=100000){  // 100000 to 999999
    Messageb[0] = ' ';
    Messageindexb = 1;
  }else if(n>=10000){  // 10000 to 99999
    Messageb[0] = ' ';
    Messageb[1] = ' ';
    Messageindexb = 2;
  }else if(n>=1000){ //
    Messageb[0] = ' '; /* n is between 1000 and 9999 */
    Messageb[1] = ' ';
    Messageb[2] = ' ';
    Messageindexb = 3;
  }else if(n>=100){ //
    Messageb[0] = ' '; /* n is between 100 and 999 */
    Messageb[1] = ' ';
    Messageb[2] = ' ';
    Messageb[3] = ' ';
    Messageindexb = 4;
  }else if(n>=10){ //
    Messageb[0] = ' '; /* n is between 10 and 99 */
    Messageb[1] = ' ';
    Messageb[2] = ' ';
    Messageb[3] = ' ';
    Messageb[4] = ' ';
    Messageindexb = 5;
  }else{
    Messageb[0] = ' '; /* n is between 0 and 9 */
    Messageb[1] = ' ';
    Messageb[2] = ' ';
    Messageb[3] = ' ';
    Messageb[4] = ' ';
    Messageb[5] = ' ';
    Messageindexb = 6;
  }
  fillmessageb(n);
}
//-----------------------UART_OutUDec4-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
void UART_OutUDec4(uint32_t n){
  if(n>9999){
    UART_OutString("****");
  }else{
    Messageindexb = 0;
    fillmessage4b(n);
    Messageb[Messageindexb] = 0; // terminate
    UART_OutString(Messageb);
  }
}
//-----------------------UART_OutUDec5-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
void UART_OutUDec5(uint32_t n){
  if(n>99999){
    UART_OutString("*****");
  }else{
    Messageindexb = 0;
    fillmessage5b(n);
    Messageb[Messageindexb] = 0; // terminate
    UART_OutString(Messageb);
  }
}
//-----------------------UART_OutUDec7-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Fixed format 7 digits with no space before or after
void UART_OutUDec7(uint32_t n){
  if(n>9999999){
    UART_OutString("*******");
  }else{
    Messageindexb = 0;
    fillmessage7b(n);
    Messageb[Messageindexb] = 0; // terminate
    UART_OutString(Messageb);
  }
}
//-----------------------UART_OutUFix1-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
void UART_OutUFix1(uint32_t n){
  UART_OutUDec(n/10);
  UART_OutChar('.');
  UART_OutUDec(n%10);
  UART_OutChar('%');
}
//---------------------UART_InUHex----------------------------------------
// Accepts ASCII input in unsigned hexadecimal (base 16) format
// Input: none
// Output: 32-bit unsigned number
// No '$' or '0x' need be entered, just the 1 to 8 hex digits
// It will convert lower case a-f to uppercase A-F
//     and converts to a 16 bit unsigned number
//     value range is 0 to FFFFFFFF
// If you enter a number above FFFFFFFF, it will return an incorrect value
// Backspace will remove last digit typed
uint32_t UART_InUHex(void){
uint32_t number=0, digit, length=0;
char character;
  character = UART_InChar();
  while(character != CR){
    digit = 0x10; // assume bad
    if((character>='0') && (character<='9')){
      digit = character-'0';
    }
    else if((character>='A') && (character<='F')){
      digit = (character-'A')+0xA;
    }
    else if((character>='a') && (character<='f')){
      digit = (character-'a')+0xA;
    }
// If the character is not 0-9 or A-F, it is ignored and not echoed
    if(digit <= 0xF){
      number = number*0x10+digit;
      length++;
      UART_OutChar(character);
    }
// Backspace outputted and return value changed if a backspace is inputted
    else if((character==BS) && length){
      number /= 0x10;
      length--;
      UART_OutChar(character);
    }
    character = UART_InChar();
  }
  return number;
}

//--------------------------UART_OutUHex----------------------------
// Output a 32-bit number in unsigned hexadecimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1 to 8 digits with no space before or after
void UART_OutUHex(uint32_t number){
// This function uses recursion to convert the number of
//   unspecified length as an ASCII string
  if(number >= 0x10){
    UART_OutUHex(number/0x10);
    UART_OutUHex(number%0x10);
  }
  else{
    if(number < 0xA){
      UART_OutChar(number+'0');
     }
    else{
      UART_OutChar((number-0x0A)+'A');
    }
  }
}

//------------UART_InString------------
// Accepts ASCII characters from the serial port
//    and adds them to a string until <enter> is typed
//    or until max length of the string is reached.
// It echoes each character as it is inputted.
// If a backspace is inputted, the string is modified
//    and the backspace is echoed
// terminates the string with a null character
// uses busy-waiting synchronization on RDRF
// Input: pointer to empty buffer, size of buffer
// Output: Null terminated string
// -- Modified by Agustinus Darmawan + Mingjie Qiu --
void UART_InString(char *bufPt, uint16_t max) {
int length=0;
char character;
  character = UART_InChar();
  while(character != CR){
    if(character == BS){
      if(length){
        bufPt--;
        length--;
        UART_OutChar(BS);
      }
    }
    else if(length < max){
      *bufPt = character;
      bufPt++;
      length++;
      UART_OutChar(character);
    }
    character = UART_InChar();
  }
  *bufPt = 0;
}

// record time Task 0 is started
void TExaS_Task0(void){uint32_t t,dt;
  t = BSP_Time_Get(); //usec
//  if((Index0>0)&&(Index0<PROFILESIZE0)){
//    TimeBuffer0[Index0] = t;
//  }
  if(Index0>0){
    dt = t-Last0; // time between executions
    if(dt>Max0)Max0 = dt; // maximum
    if(dt<Min0)Min0 = dt; // minimum
    Sum0 = Sum0+dt;
  }
  Index0++;
  Last0=t;  
  LogicData ^= 0x01;
}

// record time Task 1 is started
void TExaS_Task1(void){uint32_t t,dt;
  t = BSP_Time_Get(); //usec
//  if(Index1<PROFILESIZE1){
//    TimeBuffer1[Index1] = BSP_Time_Get();
//  }
  if(Index1>0){
    dt = t-Last1; // time between executions
    if(dt>Max1)Max1 = dt; // maximum
    if(dt<Min1)Min1 = dt; // minimum
    Sum1 = Sum1+dt;
  }
  Index1++;
  Last1=t;  
  LogicData ^= 0x02;
}
// record time Task 2 is started
void TExaS_Task2(void){uint32_t t,dt;
  t = BSP_Time_Get(); //usec
//  if(Index2<PROFILESIZE2){
//    TimeBuffer2[Index2] = BSP_Time_Get();
//  }
  if(Index2>0){
    dt = t-Last2; // time between executions
    if(dt>Max2)Max2 = dt; // maximum
    if(dt<Min2)Min2 = dt; // minimum
    Sum2 = Sum2+dt;
  }
  Index2++;
  Last2=t;  
  LogicData ^= 0x04;
}
// record time Task 3 is started
void TExaS_Task3(void){uint32_t t,dt;
  t = BSP_Time_Get(); //usec
//  if(Index3<PROFILESIZE3){
//    TimeBuffer3[Index3] = BSP_Time_Get();
//  }
  if(Index3>0){
    dt = t-Last3; // time between executions
    if(dt>Max3)Max3 = dt; // maximum
    if(dt<Min3)Min3 = dt; // minimum
    Sum3 = Sum3+dt;
  }
  Index3++;
  Last3=t;  
  LogicData ^= 0x08;
}
// record time Task 4 is started
void TExaS_Task4(void){uint32_t t,dt;
  t = BSP_Time_Get(); //usec
//  if(Index4<PROFILESIZE4){
//    TimeBuffer4[Index4] = BSP_Time_Get();
//  }
  if(Index4>0){
    dt = t-Last4; // time between executions
    if(dt>Max4)Max4 = dt; // maximum
    if(dt<Min4)Min4 = dt; // minimum
    Sum4 = Sum4+dt;
  }
  Index4++;
  Last4=t;  
  LogicData ^= 0x10;
}
// record time Task 5 is started
void TExaS_Task5(void){uint32_t t,dt;
  t = BSP_Time_Get(); //usec
//  if(Index5<PROFILESIZE5){
//    TimeBuffer5[Index5] = BSP_Time_Get();
//  }
  if(Index5>0){
    dt = t-Last5; // time between executions
    if(dt>Max5)Max5 = dt; // maximum
    if(dt<Min5)Min5 = dt; // minimum
    Sum5 = Sum5+dt;
  }
  Index5++;
  Last5=t;  
  LogicData ^= 0x20;
}
//#define TExaS_Task1()  if(Index1<PROFILESIZE){TimeBuffer1[Index1++] = BSP_Time_Get();}
//#define TExaS_Task2()  if(Index2<PROFILESIZE){TimeBuffer2[Index2++] = BSP_Time_Get();}
//#define TExaS_Task3()  if(Index3<PROFILESIZE){TimeBuffer3[Index3++] = BSP_Time_Get();}
//#define TExaS_Task4()  if(Index4<PROFILESIZE){TimeBuffer4[Index4++] = BSP_Time_Get();}
//#define TExaS_Task5()  if(Index5<PROFILESIZE){TimeBuffer5[Index5++] = BSP_Time_Get();}

void Encrypt(unsigned long sec){
}
void SetGrade(unsigned long lab, unsigned long grade, unsigned long id){

}

