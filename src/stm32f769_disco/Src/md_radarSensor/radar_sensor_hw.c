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

#define _RADAR_SENSOR_HW_DEF_C

/* Includes ------------------------------------------------------------------*/
#include "radar_sensor_hw.h"

#include "stm32f769i_discovery.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

void SensorLed_Init(void) {

    GPIO_InitTypeDef gpio_init_structure;

    /* Enable the SENSOR INPUTS clock */
    SENSOR_LED_GPIO_CLK_ENABLE();

    /* Configure sensor inputs pin as input */
    gpio_init_structure.Mode  = GPIO_MODE_OUTPUT_PP;
    gpio_init_structure.Pull  = GPIO_PULLUP;
    gpio_init_structure.Speed = GPIO_SPEED_HIGH;

    gpio_init_structure.Pin = SENSOR_LED_PIN;
    HAL_GPIO_Init(SENSOR_LED_GPIO_PORT, &gpio_init_structure);

    HAL_GPIO_WritePin(SENSOR_LED_GPIO_PORT, SENSOR_LED_PIN, GPIO_PIN_RESET);
}

void SensorInputs_Init(void) {

    GPIO_InitTypeDef gpio_init_structure;

    /* Enable the SENSOR INPUTS clock */
    SENSOR_INPUTS_GPIO_CLK_ENABLE();

    /* Configure sensor inputs pin as input */
    gpio_init_structure.Mode = GPIO_MODE_INPUT;
    gpio_init_structure.Speed = GPIO_SPEED_FAST;

    // push button
    input[InputType_button].status_old  = DIn_Status_OFF;
    input[InputType_button].port        = SENSOR_INPUTS_GPIO_PORT;
    input[InputType_button].pin         = SENSOR_INPUT_1_PIN;
    gpio_init_structure.Pull = GPIO_PULLUP;
    gpio_init_structure.Pin  = input[InputType_button].pin;
    HAL_GPIO_Init(input[InputType_button].port, &gpio_init_structure);

    // radar sensor
    input[InputType_sensor_out].status_old  = DIn_Status_OFF;
    input[InputType_sensor_out].port        = SENSOR_INPUTS_GPIO_PORT;
    input[InputType_sensor_out].pin         = SENSOR_INPUT_2_PIN;
    gpio_init_structure.Pull = GPIO_NOPULL;
    gpio_init_structure.Pin  = input[InputType_sensor_out].pin;
    HAL_GPIO_Init(input[InputType_sensor_out].port, &gpio_init_structure);

}

