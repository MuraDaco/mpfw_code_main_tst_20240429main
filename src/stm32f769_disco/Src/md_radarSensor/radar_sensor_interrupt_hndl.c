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


#define _RADAR_SENSOR_INTERRUPT_HNDL_DEF_C

#include "radar_sensor_interrupt_hndl.h"
#include "radar_sensor_hw.h"

 void lcd_timer_SysTick (void)
{
    if(g_timer_lcd_SysTick)
    {
        if(g_timer_lcd_SysTick > 1000) g_timer_lcd_SysTick = 1000;
        g_timer_lcd_SysTick--;
    }
    else
    {
        g_timer_lcd_SysTick = 999;
        timer_lcd_update = 1;
    }
}

void lcd_timer_update (void)
{
    if(timer_lcd_update)
    {
        timer_lcd_update = 0;
        if(timer_lcd) timer_lcd--;
    }
}
