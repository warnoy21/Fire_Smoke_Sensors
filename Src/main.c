
//#include  "adc.h"
/*
 * Use to tweak resistor of the flame sensor and smoke sensor
 *
 *
 *
 * */
#include "flame_sensor.h"
#include "smoke_adc.h"
void fire_presence (uint32_t val);
void smoke_presence (uint32_t val);
uint32_t  fire_detector;
uint32_t  smoke_detector;


int main(){


	flame_sensor_init();
	smoke_adc_init();
	start_adc_conv();

	/*init PC3 led*/
	RCC->AHB1ENR |=(1U<<2);
	GPIOC->MODER &=~(1U<<7);
	GPIOC->MODER |=(1U<<6);



	while(1){

		fire_detector = flame_sensor_read();
		fire_presence(fire_detector);

		smoke_detector = read_smoke_val();
		smoke_presence(smoke_detector);
	}



}

void fire_presence (uint32_t val){

	if (val > 0){

		GPIOC->ODR &= ~(1U << 3); //set bit 3 (PC3 low)
			}
	else {
		GPIOC->ODR |= (1U << 3);     // Set bit 3 (PC3 high)
	}
	for(int i = 0 ; i< 100000;i++){}
}

void smoke_presence (uint32_t val){
	if (val > 500){


				GPIOC->ODR |= (1U << 3);     // Set bit 3 (PC3 high)

	}
	else {

				GPIOC->ODR &= ~(1U << 3); //set bit 3 (PC3 low)
	}
	for(int i = 0 ; i< 100000;i++){}
}


