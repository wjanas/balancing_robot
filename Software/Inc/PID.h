/*
 * PID.h
 *
 *  Created on: 13.10.2018
 *      Author: user
 */

#ifndef PID_H_
#define PID_H_
#include "stm32f1xx_hal.h"
#include "motion_control.h"
#include "gy521.h"
#include "main.h"

/* Variables */
double previousError;
float speedIntegral;
float angleIntegral;
int16_t previousSpeed;

/* Function Prototypes */

void PID_Init();
void anglePID(float refAngle, int8_t realAngle);
void speedPID(float refSpeed, float realSpeed);

#endif /* PID_H_ */
