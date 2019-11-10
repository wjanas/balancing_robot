/*
 * gyro521.h
 *
 *  Created on: 13.10.2018
 *      Author: user
 */

#ifndef GY521_H_
#define GY521_H_


#include "main.h"

#define ADDR 0x68<<1
#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48
#define ACCEL_RESOLUTION 2.0

typedef enum TENDENCY{
	FALLING,
	STABLE,
	RISING
} tendency;


/* Variables */
float gyroYRate;

/* Function Prototypes */

void gy521_Init();
int16_t getGyro_X();
int16_t getGyro_Y();
int16_t getGyro_Z();
int16_t getAcc_X();
int16_t getAcc_Y();
int16_t getAcc_Z();
float getAccelPitch();
float getGyroPitch(float gyroAngle, int16_t rawGyro);
float getGyroYRate(int16_t rawGyro);
int8_t complementaryFilter(float gyro, float accel);
tendency checkTendency(int16_t val_1, uint16_t val_2);
#endif /* GY521_H_ */
