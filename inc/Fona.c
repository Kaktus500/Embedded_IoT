/*
 * Fona.c
 *
*/
// Jonathan Valvano
// October 6, 2020

/* This example accompanies the book
   "Embedded Systems: Introduction to Robotics,
   Jonathan W. Valvano, ISBN: 9781074544300, copyright (c) 2020
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/

Simplified BSD License (FreeBSD License)
Copyright (c) 2020, Jonathan Valvano, All rights reserved.

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
/*
 * derived from Adafruit_FONA.cpp Adafruit_FONA.h
 *

 * This is a library for our Adafruit FONA Cellular Module
 *
 * Designed specifically to work with the Adafruit FONA
 * ----> http://www.adafruit.com/products/1946
 * ----> http://www.adafruit.com/products/1963
 *
 * These displays use TTL Serial to communicate, 2 pins are required to
 * interface
 * Adafruit invests time and resources providing this open source code,
 * please support Adafruit and open-source hardware by purchasing
 * products from Adafruit!
 *
 * section author Author
 *
 * Written by Limor Fried/Ladyada for Adafruit Industries.
 * section license License
 *
 * BSD license, all text above must be included in any redistribution
 *
 */
// built-in LED1 connected to P1.0
// P1.0, P2.0 are an output to profiling scope/logic analyzer
// Fona pin connection
// Bat     to 3.7V LiIon battery, also on JST-2
// GND     to MSP432 ground and battery ground, also on JST-2
// +SPKR   to speaker+
// -SPKR   to speaker-
// Rst     to J2.18, MSP432 GPIO output, P3.0
// PS      not connected
// Key     grounded
// RI      not connected
// TX      to J1.3, MSP432 UCA2RXD P3.2
// RX      to J1.4, MSP432 UCA2TXD P3.3
// NS      not connected
// Vio     to 3.3V
/*
JST 2-pin - this is the battery input connector. It works with any of our Lipoly batteries but since the charge rate is
500mA (and the cellular module can spike high current draw!) we suggest our 500mAh (https://adafru.it/drL) or
1200mAh (http://adafru.it/258)batteries. You can also connect a JST cable here if you have other plans. See the
cable photo for polarity, red is + and black is gnd. (http://adafru.it/261)

MicroUSB connector - this is the LiPoly/LiIon battery charging port. The SIM800 has a USB interface but its ONLY
for reprogramming the module with an expensive and unavailable IDE. So charge only! The charge rate is
500mA max.

Headset jack - this is a 'standard' TRRS 3.5mm phone headset jack with stereo earphone and mono
microphone. Any 'iPhone' or 'Android' compatible (but not iPhone original) should work. (https://adafru.it/fbK) We
tried about 10 different ones, and basically the more expensive once are more comfortable and louder but our
official iPhone headset mic did not work for unknown reasons. Sleeve is Mic+, first ring is ground, then the
second ring and tip are for stereo audio. The module does not have stereo out so we just tied both together.

Vio - THIS IS THE MOST IMPORTANT PIN! This is the pin that you MUST drive with an external voltage from 3V-
5V to set the logic level converter. The converter also buffers the indicator LEDs so NOTHING will appear to
work unless this pin is powered! You should set the voltage to whatever voltage your microcontroller uses for
logic. A 5V micro (like Arduino) should have it be 5V, a 3V logic micro should set it to 3V.

VBAT & GND - these are the same pins as the 2-pin JST connector. Connect to a 3.7V/4.2V Lipoly/LiIon battery.
Do not power from a power supply or LDO. Use only a battery, at least 500mA, 1000mAh+ is best since there
can be 2A spikes of current

Key - This is also a super important pin (but not as important as Vio). This is the power on/off indicator. Its also
tied to the button in the top left. Tie this pin to ground for 2 seconds to turn the module on or off. It's not a level
signal so it isn't like "low is off, high is on" - instead you must pulse it for 2 seconds to turn off/on. The module
comes by default off. Tie this permanently to ground if you never want your micro to turn off the FONA for power
saving

PS - this is the Power Status pin. It is low when the module is off and high when the module has power. If you're
using the Key button or pin, you can monitor this pad to see when the module's booted up. This is tied to the Pwr
LED too.

NS - this is the Network Status pin. It pulses to signal the current status of the module. This is also tied to the Net
LED so for more detail see the LEDs section below.

Reset - this is module hard reset pin. By default it has a high pull-up (module not in reset). If you absolutely got
the module in a bad space, toggle this pin low for 100ms to perform a hard reset.

RX & TX - OK now that I made you read all that you can actually use the UART pins. The module uses UART to
send and receive commands and data. These pins are auto-baud so whatever baud rate you send "AT" after
reset or boot is the baud rate is used. RX is into the module, TX is out of the module.

RI - this is the Ring Indicator. It is basically the 'interrupt' out pin from the module. It is by default high and will
pulse low for 120ms when a call is received. It can also be configured to pulse when an SMS is received.

SPK+ and - : This is for connecting an external 8 ohm speaker, max 1W. You can configure the module to route
calls and FM radio to the headset or the external audio. The two pins are differential so they don't have output
DC blocking capacitors. You cannot connect this to a stereo, powered speakers or other non-differential
amplifier without adding a 100uF+ blocking cap in series to the + pin and then not using the - pin. Instead, your
amp should use GND for the - reference

MIC + and -: this is for connecting an external electret microphone, it will bias the mic with 2V. Most electrets will
work just fine. No extra circuitry is required for the mic such as a biaser or amplifier, just wire it up directly!

LEDs
PWR - Blue! Lit when the module is booted and running

NET - Red! You can use this for checking the current state without sending an AT command:
- 64ms on, 800ms off - the module is running but hasn't made connection to the cellular network yet
- 64ms on, 3 seconds off - the module has made contact with the cellular network and can send/receive voice
and SMS
- 64ms on, 300ms off - the GPRS data connection you requested is active
By watching the blinks you can get a visual feedback on whats going on.

Charging - Orange! This is next to the microUSB jack. Indicates the onboard lipo charger is charging
Done - Green! This is next to the JST jack. Indicates that the battery charging is done and the battery is full

Other Breakout Pins
We scattered a few other breakouts around the board.

Buzzer and PWM (Top right) - These are tied to the PWM output of the module! The PWM capability is quite nice,
it can set any frequency and duty cycle. The PWM pin is directly output from the module and is 0-2.8Vpp. The
Buzzer output has a NPN drive transistor so it can run a small vibration motor. Bz+ is the VBat voltage, Bz- is
toggled on and off to ground.

ADC (left middle) - the SIM800 has an ADC that can read 0-2.8VDC from this pin, referenced to ground. It also
has an internal battery ADC so you can use this for a sensor or something. You can query the voltage from the
UART. 2.8V max, people!

5V (left middle) - this is the USB 5V from the microUSB connector when its in and powered. Good if you need to
know when the microUSB is plugged in and/or want to recharge the battery from an external plug.

2.8V test point - We have a test point for the 2.8V internal regulator, its off to the right.
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "msp.h"
#include "..\inc\Fona.h"
#include "..\inc\UART0.h"
#include "..\inc\UART1.h"
#include "..\inc\Clock.h"
#define LEDOUT (*((volatile uint8_t *)(0x42098040)))
// P3->OUT is 8-bit port at 0x4000.4C22
// I/O address be 0x4000.0000+n, and let b represent the bit 0 to 7.
// n=0x4C22, b=0
// bit banded address is 0x4200.0000 + 32*n + 4*b
#define RST (*((volatile uint8_t *)(0x42098440)))
#define FONADELAY 40
#ifdef FONA_DEBUG
#define DebugOutString(x) UART0_OutString((char *)x)
#define DebugOutChar UART0_OutChar
#define DebugOutUHex2 UART0_OutUHex2
#else
#define DebugOutString(x)
#define DebugOutChar(x)
#define DebugOutHex2(x)
#endif

uint8_t replybuffer[255];  ///< buffer for holding replies from the module
uint8_t const useragent[] = "FONA";
uint8_t const ok_reply[] = "OK";

// *************low level private functions **************
/**
 * @brief Read all available serial input to flush pending data.
 *
 */
void flushInput(void){uint8_t in;
// flush receiver buffer
uint32_t timeoutloop = 0;
  while(timeoutloop++ < FONADELAY) {
    in = UART1_InCharNonBlock();
    while(in){
      in = UART1_InCharNonBlock();
      DebugOutChar(in);
      timeoutloop = 0; // If char was received reset the timer
    }
    Clock_Delay1ms(1); // 40 ms with no input
  }
}

void readAllInput(void){uint8_t in;
// flush receiver buffer
uint32_t timeoutloop = 0;
  while(timeoutloop++ < FONADELAY) {
    in = UART1_InCharNonBlock();
    while(in){
      DebugOutChar(in); //
      in = UART1_InCharNonBlock();
      timeoutloop = 0; // If char was received reset the timer
    }
    Clock_Delay1ms(1); // 40 ms with no input
  }
}



/**
 * @brief Read directly into the reply buffer
 *
 * @param read_length The number of bytes to return
 * @return uint16_t The number of bytes read
 */
uint32_t readRaw(uint16_t read_length) {uint8_t in;
  uint32_t idx = 0;

  while (read_length && (idx < sizeof(replybuffer) - 1)) {
    in = UART1_InCharNonBlock();

    if (in) {
      replybuffer[idx] = in;
      idx++;
      read_length--;
    }
  }
  replybuffer[idx] = 0;

  return idx;
}

/**
 * @brief Read a single line or up to 254 bytes
 *
 * @param timeout Reply timeout
 * @param multiline true: read the maximum amount. false: read up to the second
 * newline
 * @return uint8_t the number of bytes read
 */
uint8_t readline(uint32_t timeout, int multiline) {uint8_t in;
  uint16_t replyidx = 0;

  while (timeout--) {
    if (replyidx >= 254) {
      // DEBUG_PRINTLN(F("SPACE"));
      break;
    }

    while(in = UART1_InCharNonBlock()) {
      if (in == '\r'){
        continue;
      }
      if(in == 0x0A) {
        if (replyidx == 0){// the first 0x0A is ignored
          continue;
        }
        if(!multiline) {
          timeout = 0; // the second 0x0A is the end of the line
          break;
        }
      }
      replybuffer[replyidx] = in;
     // DebugOutString("0x");DebugOutUHex2(in);DebugOutChar(',');

      replyidx++;
    }

    if(timeout == 0) {
      break;
    }
  //  Clock_Delay1ms(1);
    Clock_Delay1us(1000);
  }
  replybuffer[replyidx] = 0; // null term
  return replyidx;
}
/**
 * @brief Send data and verify the response matches an expected response
 *
 * @param send Pointer to the buffer of data to send
 * @param reply Buffer with the expected reply
 * @param timeout Read timeout
 * @return true: success, false: failure
 */
/**
 * @brief Send a command and return the reply
 *
 * @param send The char* command to send
 * @param timeout Timeout for reading a  response
 * @return uint8_t The response length
 */
uint8_t getReply(uint8_t *send, uint32_t timeout) {
  flushInput();

  DebugOutString("\n\r---> ");
  DebugOutString(send);

  UART1_OutString((uint8_t *)send);UART1_OutChar(LF);

  uint32_t l = readline(timeout,0);

  DebugOutString("\n\r<--- ");
  DebugOutString(replybuffer);DebugOutChar(CR);DebugOutChar(LF);

  return l;
}
int sendCheckReply(uint8_t *send, const uint8_t *reply, uint32_t timeout) {
  if (!getReply(send, timeout))
    return 0;
  return (strcmp((const char *)replybuffer, (const char *)reply) == 0);
}

void fonaCommand(uint8_t *pt){
  UART1_OutString(pt);  // send string
  readAllInput();
}
// *************high level public functions **************

void Fona_Reset(void){ // reset Fona
 // P3.0 GPIO output to RST
  RST = 0;  // reset
  Clock_Delay1ms(100);
  RST = 1;  // exit reset
  Clock_Delay1ms(10);
}


void Fona_Init(uint32_t n){
// baud choices defined in UART1.h
  P3->SEL0 &= ~0x01;    // P3.0 GPIO output to RST
  P3->SEL1 &= ~0x01;    // configure P3.0 as GPIO
  P3->DIR |= 0x01;      // make P3.0 out
  //
  // add code to initialize GPIO input for RI
  //
  UART1_InitB(n);       // serial port to Fona
  //************ configure the Fona module**********************
  Fona_Reset();
  fonaCommand("AT\n");        // initialize auto-baud'er
  fonaCommand("AT\n");        // initialize auto-baud'er
  fonaCommand("ATE1\n");      // Turn on echo
  fonaCommand("AT+CMEE=2\n"); // Turn on verbose errors
#ifdef FONA_DEBUG
  fonaCommand("ATI\n");       // Get the module name and revision
  fonaCommand("AT+CCID\n");   // Report CCID for device
  fonaCommand("AT+COPS?\n");  // Check that you're connected to the network
  fonaCommand("AT+CSQ\n");    // Check the 'signal strength' - the first # is dB strength,
  fonaCommand("AT+CBC\n");    // will return the lipo battery state.
  // The second number is the % full (in this case its 92%) and
  // the third number is the actual voltage in mV
  fonaCommand("AT+CPMS=?\n"); // list of supported SMS memory devices
  fonaCommand("AT+CPMS?\n");  // SMS messages
  fonaCommand("AT+CSMS=?\n"); // list of supported SMS services
  fonaCommand("AT+CSMS?\n");  // SMS service
  fonaCommand("AT+CFGRI?\n"); // check RI configuration service
#endif
  fonaCommand("ATE0\n");      // Turn off echo

  Clock_Delay1ms(200);
  readAllInput(); // remove any buffered input
  //************ configuration ended***********************
}

// Set the preferred SMS storage.
//  SMS_SIM = 1 for storage on the SIM.
//  SMS_FONA= 0 for storage on the FONA chip
void Fona_SetSMSStorage(int place){
  if(place){
    fonaCommand("AT+CPMS=\"SM\",\"SM\",\"SM\"\n"); // set SMS memory devices to SIM card
  }else{
    fonaCommand("AT+CPMS=\"ME\",\"ME\",\"ME\"\n"); // set SMS memory devices to FONA chip
  }
  fonaCommand("AT+CSMS?\n");  // check SMS service
}

void Fona_SetSMSInterrupt(int n){
    // configure RI pin
  if(n == 0){
    fonaCommand("AT+CFGRI=0\n"); // off
  }else if(n == 1){
    fonaCommand("AT+CFGRI=1\n"); // On(TCPIP,FTP and URC control RI PIN)
  }else if(n == 2){
    fonaCommand("AT+CFGRI=2\n"); // On(only TCPIP control RI PIN)
  }
  fonaCommand("AT+CFGRI?\n");  // check RI configuration service
}


int32_t Fona_GetNumSMS(void){
    // Get the number of SMS messages
    // "AT+CMGF=1"  get into text mode
    // "AT+CPMS?" ask how many sms are stored
    // parse response
  return -1;
}

// Reading SMS's is a bit involved so we don't use helpers that may cause delays
// or debug printouts!

/**
 * @brief Read an SMS message into a provided buffer
 *
 * @param message_index The SMS message index to retrieve
 * @param smsbuff SMS message buffer
 * @param maxlen The maximum read length
 * @param readlen The length read
 * @return 1: success, 0: failure
 */
int Fona_ReadSMS(uint32_t message_index, char *smsbuff,
                            uint32_t maxlen, uint32_t *readlen){
/* Adafruit_FONA.cpp C++ code

   // text mode
  if (!sendCheckReply(F("AT+CMGF=1"), ok_reply))
    return false;

  // show all text mode parameters
  if (!sendCheckReply(F("AT+CSDH=1"), ok_reply))
    return false;

  // parse out the SMS len
  uint16_t thesmslen = 0;

  DEBUG_PRINT(F("AT+CMGR="));
  DEBUG_PRINTLN(message_index);

  // getReply(F("AT+CMGR="), message_index, 1000);  //  do not print debug!
  mySerial->print(F("AT+CMGR="));
  mySerial->println(message_index);
  readline(1000); // timeout

  // DEBUG_PRINT(F("Reply: ")); DEBUG_PRINTLN(replybuffer);
  // parse it out...

  DEBUG_PRINTLN(replybuffer);

  if (!parseReply(F("+CMGR:"), &thesmslen, ',', 11)) {
    *readlen = 0;
    return false;
  }

  readRaw(thesmslen);

  flushInput();

  uint16_t thelen = min(maxlen, (uint16_t)strlen(replybuffer));
  strncpy(smsbuff, replybuffer, thelen);
  smsbuff[thelen] = 0; // end the string

  DEBUG_PRINTLN(replybuffer);

  *readlen = thelen;
  return true;
  */
  return 0; // fail
}

/**
 * @brief Delete an SMS Message
 *
 * @param message_index The message to delete
 * @return true: success, false: failure
 */
int Fona_DeleteSMS(uint8_t message_index){
/*
  if (!sendCheckReply(F("AT+CMGF=1"), ok_reply))
    return false;
  // read an sms
  char sendbuff[12] = "AT+CMGD=000";
  sendbuff[8] = (message_index / 100) + '0';
  message_index %= 100;
  sendbuff[9] = (message_index / 10) + '0';
  message_index %= 10;
  sendbuff[10] = message_index + '0';

  return sendCheckReply(sendbuff, ok_reply, 2000);
*/
  return 0;
}

/**
 * @brief Retrieve the sender of the specified SMS message and copy it as a
 *    string to the sender buffer.  Up to senderlen characters of the sender
 * will be copied and a null terminator will be added if less than senderlen
 *    characters are copied to the result.
 *
 * @param message_index The SMS message index to retrieve the sender for
 * @param sender Pointer to a buffer to fill with the sender
 * @param senderlen The maximum length to read
 * @return 1: a result was successfully retrieved, 0: failure
 */
int Fona_GetSMSSender(uint32_t message_index, char *sender,
                                 int senderlen){
/* Adafruit_FONA.cpp C++ code

  // Ensure text mode and all text mode parameters are sent.
  if (!sendCheckReply(F("AT+CMGF=1"), ok_reply))
    return false;
  if (!sendCheckReply(F("AT+CSDH=1"), ok_reply))
    return false;

  DEBUG_PRINT(F("AT+CMGR="));
  DEBUG_PRINTLN(message_index);

  // Send command to retrieve SMS message and parse a line of response.
  mySerial->print(F("AT+CMGR="));
  mySerial->println(message_index);
  readline(1000);

  DEBUG_PRINTLN(replybuffer);

  // Parse the second field in the response.
  bool result = parseReplyQuoted(F("+CMGR:"), sender, senderlen, ',', 1);
  // Drop any remaining data from the response.
  flushInput();
  return result;
  */
  return 0; // fail
}


/**
 * @brief Send an SMS Message from a buffer provided
 *
 * @param phone     The SMS address buffer,
 * @param message   The SMS message buffer
 * @return true: success, false: failure
 */
int Fona_SendSMS(uint8_t *phone, uint8_t *message) {
  if (!sendCheckReply((uint8_t *)"AT+CMGF=1", ok_reply,5000)){
    DebugOutString("AT+CMGF=1 fail\n");
    return 0; // fail
  }
  uint8_t sendcmd[30] = "AT+CMGS=\"";
  strncpy((char *)(sendcmd + 9), (char *)phone,
          30 - 9 - 2); // 9 bytes beginning, 2 bytes for close quote + null
  sendcmd[strlen((char *)sendcmd)] = '\"';

  if (!sendCheckReply(sendcmd, "> ",1000)){
   DebugOutString(sendcmd);
   DebugOutString(" fail\n ");
   return 0; // fail
  }
  DebugOutString("> ");
  DebugOutString(message); DebugOutChar(CR);DebugOutChar(LF);
  UART1_OutString(message); // sending text
  UART1_OutChar(LF);
  UART1_OutChar(0x1A);     // terminate SMS

  DebugOutString("^Z\n");

  readline(10000,0); // read the +CMGS reply, wait up to 10 seconds!!!
  if (strstr((char *)replybuffer, "+CMGS") == 0) {
    return 0; // fail
  }
  readline(1000,0); // read OK

  if (strcmp((char *)replybuffer, "OK") != 0) {
    return 0; // fail
  }
  return 1; // success
}

