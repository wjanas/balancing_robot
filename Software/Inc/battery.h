#ifndef BATTERY_H
#define BATTERY_H

#include "main.h"

#define ADC_TO_VOLTS 3.7/4095

typedef struct{
	float FirstPacketVoltage;
	float SecondPacketVoltage;
	float ThirdPacketVoltage;
	float BatteryVoltage;
}Voltage;

void getBatteryVoltage(Voltage *vol);
int caclulateBatteryLevel(float voltage);
void displayBatteryLevel(int percentage);
int checkForOverDischarge(Voltage *vol);

#endif
