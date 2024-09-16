/*
 * systick_delay.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Aaron Gumba
 */

#include "systick_delay.h"
void systickDelay(int delay){

	SysTick->LOAD = SYSTICK_LOAD_VAL;
	SysTick->VAL  = CLR_SYSTICK;
	SysTick->CTRL |= CLK_SOURCE;
	SysTick->CTRL |= SYSTICK_EN;

	for(int i =0 ; i< delay; i++){
		//wait until the countflag is set
		while ((SysTick->CTRL & FLAG)== 0){}

	}

	SysTick->VAL  = CLR_SYSTICK;
}
