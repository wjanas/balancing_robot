/*
 * PID.c
 *
 *  Created on: 13.10.2018
 *      Author: user
 */
#include "PID.h"
#include "main.h"

void PID_Init(){
	speedIntegral = 0;
	angleIntegral = 0;
	previousError = 0;
	previousSpeed = 0;
}


void anglePID(float refAngle, int8_t realAngle){

	double error;
	float Kp = 5; //5.85
	float Ki = 0;
	float Kd = 0;
	double v = 0;
	float dt = ((1 + TIM2->PSC)*(1+TIM2->ARR))/24000000;
	/*
	if(realAngle >= (refAngle - 3) && realAngle <= (refAngle + 3)){
		realAngle = refAngle;
	}
*/
	error = refAngle - realAngle;
	angleIntegral = angleIntegral  + error * dt;
	v = Kp*(error + (Kd* (error - previousError) / dt) + Ki * angleIntegral);// * 1.33;
	previousError = error;
}

void speedPID(float refSpeed, float realSpeed){

	double error;
	double v = 0;
	float Kp = 1.5;
	float Ki = 0;
	float Kd = 0;
	float dt = 0.1;

	error = refSpeed - realSpeed;
	speedIntegral = speedIntegral + error * dt;


	v = Kp*(error + (Kd*error / dt) + Ki * speedIntegral);
	v = acos((v*v)/(2*9.81*0.125));

	//_angle = (int16_t)(v);


}

