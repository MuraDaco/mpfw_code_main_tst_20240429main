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
 * sdkInterruptConfig.h
 *
 *  Created on: Jun, 12 2024
 *      Author: Marco Dau
 */

#ifndef SDK_INTERRUPT_CONFIG_H_
#define SDK_INTERRUPT_CONFIG_H_

#include "stm32f7xx_hal.h"
#include "sdkInterruptUnit.h"
//#include "sdkInterruptTbl.h"
#include "sdkInterruptConfigAppId.h"



sdkInterrupt_t*  sdkInterruptUnitPtrArray[sdkInterruptId_Num] = {
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_DMA2_Stream0                   ,IntHandler_audio            ,kSdkAppId_audio                ,kSdkWhenRunHandler_WhenAppIdMatches    },
//    {   kSdkInterruptId_DMA2_Stream5                   ,IntHandler_audio            ,kSdkAppId_audio                ,kSdkWhenRunHandler_WhenAppIdMatches    },
//    {   kSdkInterruptId_AUDIO_OUT_SAIx_DMAx            ,IntHandler_audio            ,kSdkAppId_audio                ,kSdkWhenRunHandler_Always              },
//    {   kSdkInterruptId_AUDIO_DFSDMx_DMAx_BUTTOM_LEFT  ,IntHandler_audio            ,kSdkAppId_audio                ,kSdkWhenRunHandler_Always              },
//    {   kSdkInterruptId_AUDIO_DFSDMx_DMAx_BUTTOM_RIGHT ,IntHandler_audio            ,kSdkAppId_audio                ,kSdkWhenRunHandler_Always              },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_SysTick                        ,radar_sensor_SysTick        ,kSdkAppId_radarSensor          ,kSdkWhenRunHandler_Always              },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_DMA2_Stream0                   ,IntHandler_sdRAM            ,kSdkAppId_sdRAM                ,kSdkWhenRunHandler_WhenAppIdMatches    },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_SysTick                        ,HAL_IncTick                 ,kSdkAppId_sdk_hal              ,kSdkWhenRunHandler_Always              },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_EXTI15_10                      ,IntHandler_TouchScreen      ,kSdkAppId_TouchScreen          ,kSdkWhenRunHandler_Always              },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_OTG                            ,IntHandler_hhcd             ,kSdkAppId_usb_hhcd             ,kSdkWhenRunHandler_Always              },
//    {   kSdkInterruptId_OTG_FS                         ,IntHandler_hhcd             ,kSdkAppId_usb_hhcd             ,kSdkWhenRunHandler_Always              },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_DMA2_Stream0                   ,IntHandler_uSD              ,kSdkAppId_uSD                  ,kSdkWhenRunHandler_WhenAppIdMatches    },
//    {   kSdkInterruptId_DMA2_Stream5                   ,IntHandler_uSD              ,kSdkAppId_uSD                  ,kSdkWhenRunHandler_WhenAppIdMatches    },
//    {   kSdkInterruptId_BSP_SDMM                       ,IntHandler_uSD              ,kSdkAppId_uSD                  ,kSdkWhenRunHandler_Always              },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_SysTick                        ,uyRTC_SysTick               ,kSdkAppId_uyRTC                ,kSdkWhenRunHandler_Always              },
//    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//    {   kSdkInterruptId_EXTI15_10                      ,IntHandler_wakeupButton     ,kSdkAppId_wakeupButton         ,kSdkWhenRunHandler_Always              },
    NULL
};



#endif /* SDK_INTERRUPT_CONFIG_H_ */
