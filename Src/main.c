

/*
 * Flame and smoke sensor that communicates to raspi via uart
 *
 *  Created on: Sep 10, 2024	Author: Aaron Gumba
 *				Sep 12, 2024			Aaron Gumba		-added Uart
 *				Sep 16,2024				Aaron Gumba		-added systick timer delay
 * */
#include "flame_sensor.h"
#include "smoke_adc.h"
#include "uart_pi.h"
#include "systick_delay.h"
#include <stdbool.h>
bool fire_presence (uint32_t f_val);
bool smoke_presence (uint32_t s_val);
void led_init(void);
void UART_send_string(const char *str);

uint16_t volatile fire_detector;
uint16_t volatile smoke_detector;

bool volatile firee;
bool volatile smokee;
int main(){


	flame_sensor_init();
	smoke_adc_init();
	start_adc_conv();
	led_init();

	/***Configure leds***/
	uart_init();



	;

	while(1){

		fire_detector = flame_sensor_read();
		firee = fire_presence(fire_detector);

		smoke_detector = read_smoke_val();
		smokee =smoke_presence(smoke_detector);

		if (firee || smokee){
			UART_write('O');
			systickDelay(3);
		}


		//UART_send_string("OFF");

	}



}
void UART_send_string(const char *str){
    // Loop through each character of the string
    while(*str != '\0'){
        UART_write(*str);  // Send the current character
        str++;             // Move to the next character in the string
    }
}
bool fire_presence (uint32_t volatile f_val){

	if (f_val > 0){

		GPIOC->ODR &= ~(1U << 2); //set bit 3 (PC3 low)
		return false ;
			}
	else {
		GPIOC->ODR |= (1U << 2);     // Set bit 3 (PC3 high)
		return true;
	}
	systickDelay(3);

}
bool smoke_presence (uint32_t volatile s_val){
	if (s_val > 700){


				GPIOC->ODR |= (1U << 3);     // Set bit 3 (PC3 high)
				return true;

	}
	else {

				GPIOC->ODR &= ~(1U << 3); //set bit 3 (PC3 low)
				return false;
	}
	systickDelay(3);


}

void led_init(void){

	RCC->AHB1ENR |=(1U<<2);

	/*init PC3 led*/
	GPIOC->MODER &=~(1U<<7);
	GPIOC->MODER |=(1U<<6);

	/*init PC2 led*/
	GPIOC->MODER &=~(1U<<5);
	GPIOC->MODER |=(1U<<4);
}

