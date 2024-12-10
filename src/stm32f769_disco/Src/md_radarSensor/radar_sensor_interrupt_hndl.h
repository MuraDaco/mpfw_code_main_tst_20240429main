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
 * radar_sensor_interrupt_hndl.c
 *
 *  Created on: Jun, 14 2024
 *      Author: Marco Dau
 */

 
 /* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __RADAR_SENSOR_INTERRUPT_HNDL_H
#define __RADAR_SENSOR_INTERRUPT_HNDL_H

#ifdef _RADAR_SENSOR_INTERRUPT_HNDL_DEF_C
#define _RADAR_SENSOR_INTERRUPT_HNDL_EXTERN_DEF
#else
#define _RADAR_SENSOR_INTERRUPT_HNDL_EXTERN_DEF extern
#endif

#include <stdint.h>

_RADAR_SENSOR_INTERRUPT_HNDL_EXTERN_DEF volatile uint8_t  timer_lcd;


void radar_sensor_SysTick (void);
void lcd_timer_update (void);

#endif /* __RADAR_SENSOR_INTERRUPT_HNDL_H */

