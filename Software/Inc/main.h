/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
#include "stdlib.h"
#include "math.h"
#include "stm32f1xx.h"
#include "gy521.h"
#include "PID.h"
#include "Kalman.h"
#include "battery.h"
#include "motor_control.h"

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */


/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_S1_Pin GPIO_PIN_1
#define ADC_S1_GPIO_Port GPIOA
#define ADC_S2_Pin GPIO_PIN_2
#define ADC_S2_GPIO_Port GPIOA
#define ADC_S3_Pin GPIO_PIN_3
#define ADC_S3_GPIO_Port GPIOA
#define PWM_A_Pin GPIO_PIN_13
#define PWM_A_GPIO_Port GPIOB
#define PWM_B_Pin GPIO_PIN_4
#define PWM_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define LED GPIO_PIN_8

#define RGB_GREEN_PORT 	GPIOA
#define RGB_GREEN_PIN 	GPIO_PIN_7

#define RGB_BLUE_PORT 	GPIOB
#define RGB_BLUE_PIN	GPIO_PIN_0

#define RGB_RED_PORT	GPIOB
#define RGB_RED_PIN	GPIO_PIN_1


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
