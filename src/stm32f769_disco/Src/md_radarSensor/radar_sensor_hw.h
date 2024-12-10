//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the essential code that is used in every application
//  Copyright (C) (2023) Marco Dau
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//  
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  You can contact me by the following email address
//  marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
//  
//  *******************************************************************************
/*
 * radar_sensor_hw.h
 *
 *  Created on: Jun, 14 2024
 *      Author: Marco Dau
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RADAR_SENSOR_HW_H
#define __RADAR_SENSOR_HW_H


#ifdef _RADAR_SENSOR_HW_DEF_C
#define _RADAR_SENSOR_HW_EXTERN_DEF
#else
#define _RADAR_SENSOR_HW_EXTERN_DEF extern
#endif

#include "stm32f7xx_hal.h"

/* Includes ----------------------------------------------------------------- */

#define SENSOR_LED_PIN                        GPIO_PIN_7
#define SENSOR_INPUT_1_PIN                    GPIO_PIN_3
#define SENSOR_INPUT_2_PIN                    GPIO_PIN_4

#define SENSOR_LED_GPIO_PORT                  GPIOF
#define SENSOR_INPUTS_GPIO_PORT               GPIOJ

#define SENSOR_LED_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOF_CLK_ENABLE()
#define SENSOR_LED_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOF_CLK_DISABLE()
#define SENSOR_INPUTS_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOJ_CLK_ENABLE()
#define SENSOR_INPUTS_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOJ_CLK_DISABLE()



typedef enum {
     DIn_Status_OFF = GPIO_PIN_RESET
    ,DIn_Status_ON  = GPIO_PIN_SET
} DIn_Status;

typedef enum {
     InputType_button
    ,InputType_sensor_out
    ,InputType_num
} InputType;


typedef struct
{
  DIn_Status    status_cur;
  DIn_Status    status_old;
  GPIO_TypeDef* port;
  uint16_t      pin;
} DIn_TypeDef;

_RADAR_SENSOR_HW_EXTERN_DEF          uint16_t g_timer_lcd_SysTick;
_RADAR_SENSOR_HW_EXTERN_DEF volatile uint8_t  timer_lcd_update;

_RADAR_SENSOR_HW_EXTERN_DEF DIn_TypeDef input[InputType_num];

void SensorLed_Init(void);
void SensorInputs_Init(void);

#endif /* __RADAR_SENSOR_HW_H */

