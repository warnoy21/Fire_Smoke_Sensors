/*
 * uart_pi.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Aaron Gumba
 */
#include "stm32f4xx.h"


#ifndef UART_PI_H_
#define UART_PI_H_

/***Configure Pins***/

//RCC enable
#define GPIOA_CLK_EN 		(1U<<0)

//PIN MODES
#define GPIOA9_MODE			(0x80000)
#define GPIOA9_FUNC_MODE	(0x70) //AF07

/***CONFIGURE UART2***/

//RCC UART enable
#define UART_CLK				(1U<<4)

//Full Duplex asynchronous communication
//8 bit word lenght CR1

//BaudRate (16Mhz)
#define UART_BD			    (0x683)

#define UART_EN				(1U<<13)
#define WORD_LENGHT			(1U<<12)
#define PCE					(1U<<10)
#define TE					(1<<3)
#define TXE					(1<<7)
#define STOP_13				(0U<<13)
#define STOP_12				(0U<<12)


void uart_init(void);
void UART_write(int ch);




#endif /* UART_PI_H_ */
