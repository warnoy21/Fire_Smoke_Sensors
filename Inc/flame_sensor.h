/*
 * flame_sensor.h
 *
 *  Created on: Sep 10, 2024
 *      Author: Aaron Gumba
 */

#ifndef FLAME_SENSOR_H_
#define FLAME_SENSOR_H_

#include "stm32f4xx.h"
#define GPIOAEN 		(1U<<0)

void flame_sensor_init(void);
uint32_t flame_sensor_read(void);
#endif /* FLAME_SENSOR_H_ */
