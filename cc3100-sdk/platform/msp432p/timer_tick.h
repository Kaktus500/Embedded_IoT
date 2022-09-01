/*
 *
 *   Copyright (C) 2015 Texas Instruments Incorporated
 *   Edited Jonathan Valvano 12/16/2018 for MSP432 Timer2A
 *   All rights reserved. Property of Texas Instruments Incorporated.
 *   Restricted rights to use, duplicate or disclose this code are
 *   granted through contract.
 *
 *   The program may not be used without the written permission of
 *   Texas Instruments Incorporated or against the terms and conditions
 *   stipulated in the agreement under which this program has been supplied,
 *   and under no circumstances can it be used with non-TI connectivity device.
 *
 */

#ifndef __TIMER_TICK_H__
#define __TIMER_TICK_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

//#include "driverlib.h"

/*!
 *  \brief: Timer specs needed by SL host driver
 */

#define ACLOCK_FREQ               32768                     // set to 32.768 [kHz]
#define TIMER_PRESCALAR		        10                              //TIMER_A_CLOCKSOURCE_DIVIDER_32
#define TIMER_CLK                 (ACLOCK_FREQ/TIMER_PRESCALAR)   // timer frequency [Hz] or ticks/sec

#define MILLISECONDS_TO_TICKS(ms)       ((TIMER_CLK * ms)/1000)         // input: number of ms, output: number of ticks at given timer frequency
#define TICKS_TO_MILLISECONDS(ticks)    ((ticks)/(TIMER_CLK/1000))      // input: number of ticks, output: number of ms at given timer frequency
#define MAX_TIMER_TICKS                 0xFFFF                          // timer max count value OR timer period

/*!
 *  \brief  Timers
 */

unsigned long timer_GetCurrentTimestamp(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __TIMER_TICK_H__ */


