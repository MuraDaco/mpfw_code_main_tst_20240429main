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

#ifndef SDK_INTERRUPT_CONFIG_APP_ID_H_
#define SDK_INTERRUPT_CONFIG_APP_ID_H_


enum kSdkAppId {
     kSdkAppId_null
//    ,kSdkAppId_audio            //  5 - interrupt handler
//    ,kSdkAppId_freertos
//    ,kSdkAppId_interrupt
//    ,kSdkAppId_LCD              
//    ,kSdkAppId_menuApp
//    ,kSdkAppId_qspi
//    ,kSdkAppId_radarSensor      //  1 - interrupt handler
//    ,kSdkAppId_sdk_hal          //  1 - interrupt handler
//    ,kSdkAppId_sdRAM            //  1 - interrupt handler
//    ,kSdkAppId_startup
//    ,kSdkAppId_touchScreen      //  1 - interrupt handler
//    ,kSdkAppId_uart
//    ,kSdkAppId_usb_hhcd         //  2 - interrupt handler
//    ,kSdkAppId_uSD              //  3 - interrupt handler
//    ,kSdkAppId_uyRTC            //  1 - interrupt handler
//    ,kSdkAppId_wakeupButton     //  1 - interrupt handler
                                // ----------------------
    ,kSdkAppId_Num              // 16 - interrupt handler 
}



#endif /* SDK_INTERRUPT_CONFIG_APP_ID_H_ */
