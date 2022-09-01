/**
 * @file      Fona.h
 * @brief     Provide functions to send text messages via SMS using Fona
 * @details   Configure Adafruit FONA Cellular Module
 * @author    Daniel Valvano and Jonathan Valvano
 * @copyright Copyright 2020 by Jonathan W. Valvano, valvano@mail.utexas.edu,
 * @warning   AS-IS
 * @note      For more information see  http://users.ece.utexas.edu/~valvano/
 * @date      October 3, 2020

<table>
<caption id="FONAports">MSP432 connected to Fona</caption>
<tr><th>Fona    <th>Connection
<tr><td>Bat     <td>to 3.7V LiIon battery, also on JST-2
<tr><td>GND     <td>to MSP432 ground and battery ground, also on JST-2
<tr><td>+SPKR   <td>to speaker+
<tr><td>-SPKR   <td>to speaker-
<tr><td>Rst     <td>to J2.18, MSP432 GPIO output, P3.0
<tr><td>PS      <td>not connected
<tr><td>Key     <td>grounded
<tr><td>RI      <td>not connected
<tr><td>TX      <td>to J1.3, MSP432 UCA2RXD P3.2
<tr><td>RX      <td>to J1.4, MSP432 UCA2TXD P3.3
<tr><td>NS      <td>not connected
<tr><td>Vio     <td>to 3.3V
</table>
 ******************************************************************************/
/*!
 * @defgroup Fona
 * @brief Configure Adafruit FONA Cellular Module
 * @{*/

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
/**
 * \brief Define for enabling FONA debug output to UART0
 * @note  Remove this line to save time/space
 */
#define FONA_DEBUG 1
/**
 * \brief Save SMS on SIM, Fona_SetSMSStorage
 */
#define SMS_SIM 1
/**
 * \brief Save SMS on Fona, Fona_SetSMSStorage
 */
#define SMS_FONA 0

/**
 * @brief reset Fona
 *
 * @param none
 * @return none
 */
void Fona_Reset(void);

/**
 * @brief Initialize Fona
 *
 * @param  n specifies baud rate, n = 12,000,000/baud rate
 * @return none
 */
void Fona_Init(uint32_t baud);

/**
 * @brief Send an SMS Message from a buffer provided
 *
 * @param phone   The SMS address buffer
 * @param message The SMS message buffer
 * @return 1: success, 0: failure
 */
int Fona_SendSMS(uint8_t phone[],uint8_t message[]);

/**
 * @brief Set the preferred SMS storage
 *  SMS_SIM = 1 for storage on the SIM.<br>
 *  SMS_FONA= 0 for storage on the FONA chip
 * @param place  1 for SIM, 0 for FONA
 */
void Fona_SetSMSStorage(int place);


/**
 * @brief configure RI pin
 * n=0 off<br>
 * n=1 On(TCPIP,FTP and URC control RI PIN)<br>
 * n=2 On(only TCPIP control RI PIN)
 * @param n  0 1 or 2
 */
void Fona_SetSMSInterrupt(int n);


/**
 * @brief Get the number of SMS messages
 *
 * @param none
 * @return number of messages, -1: failure
 */
int32_t Fona_GetNumSMS(void);

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
                            uint32_t maxlen, uint32_t *readlen);

/**
 * @brief Delete an SMS Message
 *
 * @param message_index The message to delete
 * @return true: success, false: failure
 */
int Fona_DeleteSMS(uint8_t message_index);

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
                                 int senderlen);


/** @}*/
