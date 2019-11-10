/*
 * gyro521.c
 *
 *  Created on: 13.10.2018
 *      Author: user
 */
#include "gy521.h"
 I2C_HandleTypeDef hi2c1;


void gy521_Init(){
	  uint8_t d[2];
	  d[0] = 0x6B;
	  d[1] = 0x00;
	  while(HAL_I2C_Master_Transmit(&hi2c1, ADDR, (uint8_t*)d,2,100) != HAL_OK){}
	  HAL_Delay(200);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
	  HAL_Delay(200);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
	  HAL_Delay(200);
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);

}

int16_t getGyro_X(){
	int16_t value;
	uint8_t temp[2];

	HAL_I2C_Mem_Read(&hi2c1, ADDR, GYRO_XOUT_H, 1, &temp[0], sizeof(temp[0]), HAL_MAX_DELAY);
	HAL_I2C_Mem_Read(&hi2c1, ADDR, GYRO_XOUT_L, 1, &temp[1], sizeof(temp[1]), HAL_MAX_DELAY);

	value = ((temp[0] << 8) | temp[1]);
	return value;

}
int16_t getGyro_Y(){
	int16_t value;
	uint8_t temp[2];

	HAL_I2C_Mem_Read(&hi2c1, ADDR, GYRO_YOUT_H , 1, &temp[0], sizeof(temp[0]), HAL_MAX_DELAY);
	HAL_I2C_Mem_Read(&hi2c1, ADDR, GYRO_YOUT_L , 1, &temp[1], sizeof(temp[1]), HAL_MAX_DELAY);

	value = ((temp[0] << 8) | temp[1]);
	return value;
}
int16_t getGyro_Z(){
	int16_t value;
	uint8_t temp[2];

	HAL_I2C_Mem_Read(&hi2c1, ADDR, GYRO_ZOUT_H , 1, &temp[0], sizeof(temp[0]), HAL_MAX_DELAY);
	HAL_I2C_Mem_Read(&hi2c1, ADDR, GYRO_ZOUT_L , 1, &temp[1], sizeof(temp[1]), HAL_MAX_DELAY);

	value = ((temp[0] << 8) | temp[1]);
	return value;
}
int16_t getAcc_X(){
	int16_t value;
	uint8_t temp[2];


	HAL_I2C_Mem_Read(&hi2c1, ADDR, ACCEL_XOUT_H, 1, &temp[0], sizeof(temp[0]), HAL_MAX_DELAY);
	HAL_I2C_Mem_Read(&hi2c1, ADDR, ACCEL_XOUT_L, 1, &temp[1], sizeof(temp[1]), HAL_MAX_DELAY);

	value = ((temp[0] << 8) | temp[1]);
	return value;
}
int16_t getAcc_Y(){
	int16_t value;
	uint8_t temp[2];

	HAL_I2C_Mem_Read(&hi2c1, ADDR, ACCEL_YOUT_H, 1, &temp[0], sizeof(temp[0]), HAL_MAX_DELAY);
	HAL_I2C_Mem_Read(&hi2c1, ADDR, ACCEL_YOUT_L, 1, &temp[1], sizeof(temp[1]), HAL_MAX_DELAY);

	value = ((temp[0] << 8) | temp[1]);
	return value;
}
int16_t getAcc_Z(){
	int16_t value;
	uint8_t temp[2];

	HAL_I2C_Mem_Read(&hi2c1, ADDR, ACCEL_ZOUT_H, 1, &temp[0], sizeof(temp[0]), HAL_MAX_DELAY);
	HAL_I2C_Mem_Read(&hi2c1, ADDR, ACCEL_ZOUT_L, 1, &temp[1], sizeof(temp[1]), HAL_MAX_DELAY);

	value = ((temp[0] << 8) | temp[1]);
	return value;
}


float getAccelPitch(){

	float Ax = (float)(getAcc_X() * ACCEL_RESOLUTION) / (float)INT16_MAX;
	float Ay = (float)(getAcc_Y() * ACCEL_RESOLUTION) / (float)INT16_MAX;
	float Az = (float)(getAcc_Z() * ACCEL_RESOLUTION) / (float)INT16_MAX;

	float accelAngle = (double)((-atan2(sqrt(Ay*Ay + Ax*Ax),Az)*180/3.14) + 90);

	return accelAngle;
}

float getGyroPitch(float gyroAngle , int16_t rawGyro){
	float Gy = getGyroYRate(rawGyro);
	gyroAngle = gyroAngle + Gy * 0.001;

	return gyroAngle;
}

float getGyroYRate(int16_t rawGyro){
	float zero = 80.75;
	float gYRate = (float)(rawGyro-zero) / 131.0;

	return gYRate;
}

int8_t complementaryFilter(float gyro, float accel){
	float u = 0.1;
	float theta = u * gyro + (1-u) * accel;

	return (int)(theta);
}



tendency checkTendency(int16_t val_1, uint16_t val_2){
	int16_t temp = val_2 - val_1;
		if(temp < 0){
			return FALLING;
		}
		else if(temp == 0){
			return STABLE;
		}
		else{
			return RISING;
		}
}
