/*
 * smoke_adc.c
 * Connected to PA1 -> AO of the sensor
 *  Created on: Sep 10, 2024
 *      Author: Aaron Gumba
 */


#include "smoke_adc.h"

void smoke_adc_init(void){

	RCC->AHB1ENR |= GPIOA_CLK_EN;
	GPIOA->MODER |= GPIOA_MODE;

	RCC->APB2ENR |=ADC_CLK_EN;
	ADC1->SQR1 	 &= ~(ADC_CONV_LENGHT); //Explicitly clear and set pins to 0
	ADC1->SQR3	 |= ADC_priority_1;
	ADC1->CR2	 |= ADC_cont_conv;
	ADC1->CR2	 |= ADC_ON;


}

void start_adc_conv(void){

	ADC1->CR2 |= ADC_start_conv;
}


uint32_t read_smoke_val(void){

	while (!(ADC1->SR & ADC_EOC)){} //wait for convertion to finish


	return ADC1->DR;
}
