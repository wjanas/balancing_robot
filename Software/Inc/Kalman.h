/*
 * Kalman.h
 *
 *  Created on: 13.11.2018
 *      Author: user
 */

#ifndef KALMAN_H_
#define KALMAN_H_

#include "gy521.h"
#include "math.h"
#include "stm32f1xx_hal.h"


/*Variables */

float Q_angle; // Process noise variance for the accelerometer
float Q_bias; // Process noise variance for the gyro bias
float R_measure; // Measurement noise variance - this is actually the variance of the measurement noise

int16_t _angle; // The angle calculated by the Kalman filter - part of the 2x1 state vector
float _bias; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
float _rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

float P[2][2]; // Error covariance matrix - This is a 2x2 matrix

float test;
/*Function prototypes*/

void kalmanInit();
int16_t getKalmanAngle(float newAngle, float newRate, float dt);     // Angle in degrees, the rate in degrees per second and the delta time in seconds


#endif /* KALMAN_H_ */
