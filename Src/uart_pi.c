/*
 * uart_pi.c
 * PA9(USART2_TX) to communicate with the raspi (simplex)
 *
 *  Created on: Sep 12, 2024
 *      Author: Aaron Gumba
 */
#include "uart_pi.h"


void uart_init(void){

	RCC->AHB1ENR  |= GPIOA_CLK_EN;
	GPIOA->MODER  |= GPIOA9_MODE;
	GPIOA->AFR[1] |= GPIOA9_FUNC_MODE;

	RCC->APB2ENR |= UART_CLK;
	USART1->BRR  |= UART_BD;
	USART1->CR1  |= UART_EN;
	USART1->CR1  |= WORD_LENGHT;
	USART1->CR2  |= STOP_13;
	USART1->CR2  |= STOP_12;
	USART1->CR1  |= PCE;

	USART1->CR1  |= TE;
}


void UART_write(int ch){

	while(!(USART1->SR & TXE)){}

	USART1-> DR =(ch & 0xFF);

}



