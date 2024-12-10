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
 * radar_sensor_log.h
 *
 *  Created on: Jun, 14 2024
 *      Author: Marco Dau
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RADAR_SENSOR_LOG_H
#define __RADAR_SENSOR_LOG_H

#include <stdint.h>

//#include "radar_sensor.h"

#define LINE_STEP_1     1
#define LINE_STEP_2     2
#define LINE_STEP_3     3
#define LINE_STEP_4     4
#define LINE_STEP_5     5
#define LINE_STEP_6     6
#define LINE_STEP_7     7
#define LINE_STEP_8     8

#define MAX_LOG_EVENT_LINE 8

// 0         1         2    
// 0123456789012345678901234567890
// 2024.04.10 - 17:23:51 - x xxx[cr][null]
#define LOG_MESSAGE_LENGTH RTC_STRING_DATE_TIME_LENGTH+9


uint8_t radar_sensor_log_init(uint8_t *p_str);
uint8_t radar_sensor_log_deinit(uint8_t p_step);

uint8_t radar_sensor_start_time_get(uint8_t *p_str);
uint8_t radar_sensor_log(uint8_t *p_str);

/* Includes ----------------------------------------------------------------- */


#endif /* __RADAR_SENSOR_LOG_H */

