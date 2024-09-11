/*
 * smoke_adc.h
 *
 *  Created on: Sep 10, 2024
 *      Author: Aaron Gumba
 */

#ifndef SMOKE_ADC_H_
#define SMOKE_ADC_H_

#include "stm32f4xx.h"

/*** Configure PIN PA1 ADC mode ***/

//ENABLE CLOCK ACCESS TO GPIOA
#define GPIOA_CLK_EN 		(1U<<0)
//GPIOA MODER
#define GPIOA_MODE			(0xC) //analog mode

//*** Configure ADC ***/

//ADC connected to APB2
#define ADC_CLK_EN 			(1U<<8)
//Lenght of ADC conversion (1 conversion = channel 1)
#define ADC_CONV_LENGHT		(0b1111<<20)
//starting ADC Sequence Start
#define ADC_priority_1		(1U<<0)
//Enable continuous conversion
#define ADC_cont_conv		(1U<<1)
//Turn ON ADC
#define ADC_ON 				(1U<<0)
//start conversion
#define ADC_start_conv		(1U<<30)

/***Read ADC value***/

//ADC finish conversion
#define ADC_EOC			(1U<<1)



void smoke_adc_init(void);
void start_adc_conv(void);
uint32_t read_smoke_val(void);

#endif /* SMOKE_ADC_H_ */
