/*
 * motion_control.c
 *
 *  Created on: 18.10.2018
 *      Author: user
 */

#include "motion_control.h"
#include "stm32f1xx_hal.h"
#include "main.h"
#include "PID.h"

float getSpeed(){
	float v = _steps * 30;
	return v;
}


void changeSpeed(int rpm){
	if(rpm > 120){
		rpm = 120;
	}

	if(rpm != 0){
		int ARR = (100000/(rpm *3.33))-1;
		TIM2->ARR = ARR;
	}
	_speed = rpm;

}


void motorsInit(){
	HAL_GPIO_WritePin(LEFT_MOTOR_I1_PORT, LEFT_MOTOR_I1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RIGHT_MOTOR_I1_PORT, RIGHT_MOTOR_I1, GPIO_PIN_RESET);
	_steps = 0;
	_v = 0;
}

void stepSingle(stepper_motor motor, direction dir){

	if(motor == RIGHT){
		if(dir == FORWARD){
			HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_PORT, RIGHT_MOTOR_DIR, GPIO_PIN_SET);
		}
		else{
			HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_PORT, RIGHT_MOTOR_DIR, GPIO_PIN_RESET);
		}

		HAL_GPIO_WritePin(RIGHT_MOTOR_STEP_PORT, RIGHT_MOTOR_STEP, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RIGHT_MOTOR_STEP_PORT, RIGHT_MOTOR_STEP, GPIO_PIN_RESET);
	}
	else{
		if(dir == FORWARD){
			HAL_GPIO_WritePin(LEFT_MOTOR_DIR_PORT, LEFT_MOTOR_DIR, GPIO_PIN_RESET);
		}
		else{
			HAL_GPIO_WritePin(LEFT_MOTOR_DIR_PORT, LEFT_MOTOR_DIR, GPIO_PIN_SET);
		}

		HAL_GPIO_WritePin(LEFT_MOTOR_STEP_PORT, LEFT_MOTOR_STEP, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LEFT_MOTOR_STEP_PORT, LEFT_MOTOR_STEP, GPIO_PIN_RESET);
	}

}

void stepBoth(direction dir){
	if(dir == FORWARD){
		HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_PORT, RIGHT_MOTOR_DIR, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LEFT_MOTOR_DIR_PORT, LEFT_MOTOR_DIR, GPIO_PIN_RESET);
	}
	else{
		HAL_GPIO_WritePin(RIGHT_MOTOR_DIR_PORT, RIGHT_MOTOR_DIR, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LEFT_MOTOR_DIR_PORT, LEFT_MOTOR_DIR, GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(RIGHT_MOTOR_STEP_PORT, RIGHT_MOTOR_STEP, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LEFT_MOTOR_STEP_PORT, LEFT_MOTOR_STEP, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LEFT_MOTOR_STEP_PORT, LEFT_MOTOR_STEP, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RIGHT_MOTOR_STEP_PORT, RIGHT_MOTOR_STEP, GPIO_PIN_RESET);

	_steps++;
}


void moveRobot(uint16_t speed, direction dir){
	_steps++;
	if(_speed != previousSpeed){
	changeSpeed(_speed);
	}
	//stepSingle(RIGHT,dir);
	//stepSingle(LEFT,dir);
	stepBoth(dir);
	previousSpeed = _speed;
}

