/*
 * flame_sensor.c
 * Detect flame sensor using PA15
 *  Created on: Sep 10, 2024
 *      Author: Aaron Gumba
 */


#include "flame_sensor.h"

void flame_sensor_init (void){

	/***Configure Pin***/

	/*Enable Clock access to pin PA15*/
	RCC-> AHB1ENR |= GPIOAEN;

	/*Initialize PA15 mode*/
	//clear and explicitly state it to ensure input mode
	GPIOA->MODER &=~(1U<<31);
	GPIOA->MODER &=~(1U<<30);


	/*Read data from PA15*/
}


uint32_t flame_sensor_read(void){


	return (GPIOA->IDR & (1U << 15));  // Read PA15

}

