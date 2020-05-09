/*
 * motor_control.c
 *
 *  Created on: Nov 15, 2019
 *      Author: wojciech
 */

#include "motor_control.h"

void setMotorSpeed(motor_t *motor, uint8_t speed){

	if(speed > 100){
		speed = 100;
	} else if (speed < 0){
		speed = 0;
	}

	motor->duty_cycle = speed;
}

void generateMotorsPWM(motor_t *left, motor_t *right, uint8_t cnt){
	if(cnt < left->duty_cycle){
		HAL_GPIO_WritePin(PWM_B_PORT, PWM_B_PIN, GPIO_PIN_SET);
	} else{
		HAL_GPIO_WritePin(PWM_B_PORT, PWM_B_PIN, GPIO_PIN_SET);
	}

	if(cnt < right->duty_cycle){
			HAL_GPIO_WritePin(PWM_A_PORT, PWM_A_PIN, GPIO_PIN_SET);
	} else{
			HAL_GPIO_WritePin(PWM_A_PORT, PWM_A_PIN, GPIO_PIN_SET);
	}
}


void moveRobot(direction_t dir){
	if(dir == FORWARD){
		HAL_GPIO_WritePin(AIN_1_PORT, AIN_1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AIN_2_PORT, AIN_2_PIN, GPIO_PIN_SET);

		HAL_GPIO_WritePin(BIN_1_PORT, BIN_1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BIN_2_PORT, BIN_2_PIN, GPIO_PIN_SET);
	} else if (dir == BACKWARD){
		HAL_GPIO_WritePin(AIN_1_PORT, AIN_1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(AIN_2_PORT, AIN_2_PIN, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(BIN_1_PORT, BIN_1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(BIN_2_PORT, BIN_2_PIN, GPIO_PIN_RESET);
	}

}

void shortBreakMotors(){
	HAL_GPIO_WritePin(AIN_1_PORT, AIN_1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(AIN_2_PORT, AIN_2_PIN, GPIO_PIN_SET);

	HAL_GPIO_WritePin(BIN_1_PORT, BIN_1_PIN, GPIO_PIN_SET);
	HAL_GPIO_WritePin(BIN_2_PORT, BIN_2_PIN, GPIO_PIN_SET);
}













