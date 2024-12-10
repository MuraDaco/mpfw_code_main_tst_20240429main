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

sdkInterrupt_t*  sdkInterruptUnitPtrArray[sdkInterruptId_Num] = {

    {   kSdkInterruptId_EXTI15_1                       },
    {   kSdkInterruptId_DMA2_Stream0                   },
    {   kSdkInterruptId_DMA2_Stream5                   },
    {   kSdkInterruptId_AUDIO_OUT_SAIx_DMAx            },
    {   kSdkInterruptId_AUDIO_DFSDMx_DMAx_BUTTOM_LEF   },
    {   kSdkInterruptId_AUDIO_DFSDMx_DMAx_BUTTOM_RIG   },
    {   kSdkInterruptId_BSP_SDMM                       },
    {   kSdkInterruptId_OTG                            },
    {   kSdkInterruptId_OTG_FS                         },

    // {   kSdkInterruptId_SysTick  ,sdkInterruptDMA_Handler     ,kSdkWhenRunHandler_Always   },
    // {   kSdkInterruptId_SysTick  ,sdkInterruptButton_Handler  ,kSdkWhenRunHandler_Always   },
    // 
    NULL
};



#endif /* SDK_INTERRUPT_CONFIG_H_ */
