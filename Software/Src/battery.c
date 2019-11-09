/*
 * battery.c
 *
 *  Created on: Nov 9, 2019
 *      Author: wojciech
 */


#include "battery.h"

extern TIM_HandleTypeDef htim3;



void displayBatteryLevel(int percentage){
	int red = 0;
	int green = 0;

	float red_dimming_factor = 0.5;
	float green_dimming_factor = red_dimming_factor * 0.5;

	if(percentage < 0){
		percentage = 0;
	} else if(percentage > 100){
		percentage = 100;
	}

	if(percentage < 50){

		red = 255 * red_dimming_factor;
		green = ((255 * 2 * percentage) / 100) * green_dimming_factor;

	} else{
		red = (255 -((255 * ( (percentage - 50) * 2))  / 100)) * red_dimming_factor;
		green = 255 * green_dimming_factor;
	}
	htim3.Instance->CCR2 = green;
	htim3.Instance->CCR3 = 0;
	htim3.Instance->CCR4 = red;

}
