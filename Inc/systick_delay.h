/*
 * systick_delay.h
 *
 *  Created on: Sep 16, 2024
 *      Author: Aaron Gumba
 */

#ifndef SYSTICK_DELAY_H_
#define SYSTICK_DELAY_H_

#include "stm32f4xx.h"
/***CONFIG SYSTIC***/
#define SYSTICK_LOAD_VAL			16000000
#define SYSTICK_EN				(1U<<0)
#define CLK_SOURCE				(1U<<2)
#define FLAG					(1<<16)
#define CLR_SYSTICK				(0)

void systickDelay(int delay);

#endif /* SYSTICK_DELAY_H_ */
