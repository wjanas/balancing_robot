#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "main.h"

#define PWM_A_PORT GPIOB
#define PWM_A_PIN GPIO_PIN_13

#define PWM_B_PORT GPIOB
#define PWM_B_PIN GPIO_PIN_4

#define AIN_1_PORT GPIOB
#define AIN_1_PIN GPIO_PIN_15

#define AIN_2_PORT GPIOB
#define AIN_2_PIN GPIO_PIN_14

#define BIN_1_PORT GPIOB
#define BIN_1_PIN GPIO_PIN_3

#define BIN_2_PORT GPIOA
#define BIN_2_PIN GPIO_PIN_15

typedef enum {
	LEFT_SIDE,
	RIGHT_SIDE
}MOTOR;

typedef enum {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
}direction_t;



typedef struct{
	MOTOR motor;
	uint8_t duty_cycle;
}motor_t;

void setMotorSpeed(motor_t *motor, uint8_t speed);
void generateMotorsPWM(motor_t *left, motor_t *right, uint8_t cnt);
void moveRobot(direction_t dir);
void shortBreakMotors();


#endif
