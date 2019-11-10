/*
 * battery.c
 *
 *  Created on: Nov 9, 2019
 *      Author: wojciech
 */


#include "battery.h"

extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;
/* private: */

float voltage_levels[21] = {
		12.6, 12.45, 12.33, 12.25, 12.07, 11.95, 11.86, 11.74, 11.62, 11.56, 11.51, 11.45, 11.39, 11.36, 11.30, 11.24, 11.18, 11.12, 11.06, 10.83, 9.82
};


/* public */

void getBatteryVoltage(Voltage *vol){
	float measured_value[3];

	measured_value[0]= HAL_ADC_GetValue(&hadc1);
	measured_value[2]= HAL_ADC_GetValue(&hadc1);
	measured_value[3]= HAL_ADC_GetValue(&hadc1);

	vol->FirstPacketVoltage = 	measured_value[0] * ADC_TO_VOLTS * 2;
	vol->SecondPacketVoltage = 	measured_value[1] * ADC_TO_VOLTS * 3 - vol->FirstPacketVoltage;
	vol->ThirdPacketVoltage	= 	measured_value[2] * ADC_TO_VOLTS * 4 - vol->SecondPacketVoltage;
	vol->BatteryVoltage	= 		measured_value[2] * 4;

}

int caclulateBatteryLevel(float voltage){
	int battery_level = 0;
	for(int i = 0; i < 21; i++){
		if(voltage <= voltage_levels[i] && voltage > voltage_levels[i + 1] ){
			battery_level = (20 - i) * 5;
			return battery_level;
		}
	}
	return -1;
}

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

int checkForOverDischarge(Voltage *vol){
	if(fmax(fmax(vol->FirstPacketVoltage, vol->SecondPacketVoltage), vol->ThirdPacketVoltage) -
			fmin(fmin(vol->FirstPacketVoltage, vol->SecondPacketVoltage), vol->ThirdPacketVoltage) >= 0.2 ){
		return 1;
	} else if (vol->BatteryVoltage < 10.0){
		return 2;
	} else{
		return 0;
	}
}

