/*
 * motion_control.h
 *
 *  Created on: 18.10.2018
 *      Author: user
 */
#ifndef MOTION_CONTROL_H_
#define MOTION_CONTROL_H_


#include "main.h"
#include "stm32f1xx_hal.h"

#define RIGHT_MOTOR_I1 GPIO_PIN_14
#define RIGHT_MOTOR_I2 GPIO_PIN_15
#define RIGHT_MOTOR_DIR GPIO_PIN_12
#define RIGHT_MOTOR_STEP GPIO_PIN_13
#define RIGHT_MOTOR_I1_PORT GPIOB
#define RIGHT_MOTOR_I2_PORT GPIOB
#define RIGHT_MOTOR_DIR_PORT GPIOB
#define RIGHT_MOTOR_STEP_PORT GPIOB

#define LEFT_MOTOR_I1 GPIO_PIN_5
#define LEFT_MOTOR_I2 GPIO_PIN_4
#define LEFT_MOTOR_DIR GPIO_PIN_15
#define LEFT_MOTOR_STEP GPIO_PIN_3
#define LEFT_MOTOR_I1_PORT GPIOB
#define LEFT_MOTOR_I2_PORT GPIOB
#define LEFT_MOTOR_DIR_PORT GPIOA
#define LEFT_MOTOR_STEP_PORT GPIOB

typedef enum DIRECTION{
	FORWARD,
	BACKWARD
} direction;

typedef enum STEPPER_MOTOR{
	RIGHT,
	LEFT
} stepper_motor;

/* Variables */

uint16_t _steps;
uint16_t _v;
volatile uint16_t _speed;
int _speedTest;
float peek;
volatile direction _dir;

/* Function Prototypes */

void motorsInit();			//initializes motors
float getSpeed(); 			//speed in RPM
void changeSpeed(int rpm);	//max 120RPM
void stepSingle(stepper_motor motor, direction dir); 	//forces step on single motor
void stepBoth(direction dir); 							//forces step on both motors
void moveRobot(uint16_t speed, direction dir); 			//moves robot using stepSingle()


#endif /*MOTION_CONTROL_H_*/
