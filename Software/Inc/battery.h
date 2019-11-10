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
int calulateBatteryLevel(float voltage);
void displayBatteryLevel(int percentage);
int checkForOverdischarge(Voltage *vol);
int measureBatteryLevel(Voltage *vol);

#endif
