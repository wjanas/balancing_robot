/*
 * Kalman.c
 *
 *  Created on: 13.11.2018
 *      Author: user
 */
#include "Kalman.h"

void kalmanInit(){
/*Variables used to adjust filter*/


	Q_angle = 0.0005f;
	Q_bias = 0.0005f;
	R_measure = 0.0003f;

	_angle = 0.0f; // Reset the angle
	_bias = 0.0f; // Reset bias

	P[0][0] = 0.0f;
	P[0][1] = 0.0f;
	P[1][0] = 0.0f;
	P[1][1] = 0.0f;
}


int16_t getKalmanAngle(float newAngle, float newRate, float dt) {

    _rate = newRate - _bias;
    _angle += dt * _rate;

    // Update estimation error covariance - Project the error covariance ahead
    P[0][0] += dt * (dt*P[1][1] - P[0][1] - P[1][0] + Q_angle);
    P[0][1] -= dt * P[1][1];
    P[1][0] -= dt * P[1][1];
    P[1][1] += Q_bias * dt;

    // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
    // Calculate Kalman gain - Compute the Kalman gain
    float S = P[0][0] + R_measure; // Estimate error

    //Calculate Kalman gain
    float K[2]; // Kalman gain - This is a 2x1 vector
    K[0] = P[0][0] / S;
    K[1] = P[1][0] / S;

    // Calculate angle and bias - Update estimate with measurement zk (newAngle)
    float y = newAngle - _angle; // Angle difference

    //Update angle and bias
    _angle += (int16_t)(K[0] * y);
    _bias += K[1] * y;

    // Calculate estimation error covariance - Update the error covariance
    float P00_temp = P[0][0];
    float P01_temp = P[0][1];

    P[0][0] -= K[0] * P00_temp;
    P[0][1] -= K[0] * P01_temp;
    P[1][0] -= K[1] * P00_temp;
    P[1][1] -= K[1] * P01_temp;

    return _angle;
}


