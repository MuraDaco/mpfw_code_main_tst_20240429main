#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the "main" entry point and, 
#       eventualy, application code that is platform dependent
#   Copyright (C) (2023) Marco Dau
#   
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as published
#   by the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#   
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#   
#   You can contact me by the following email address
#   marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
#   
#   *******************************************************************************
trace_execution()

include(${CODE_MAIN_CMAKE_MAIN_VER_DEF_DIR}/set_class_src_ver.cmake)

set(CONF_DIR
    ${SDK_PLATFORM_CONF_DIR}
    ${SDK_PLATFORM_FATFS_CONF_DIR}
    ${SDK_PLATFORM_FREERTOS_CONF_DIR}
    ${SDK_PLATFORM_INTERRUPT_CONF_DIR}
    ${SDK_PLATFORM_SDK_CONF_DIR}
    ${SDK_PLATFORM_UART_CONF_DIR}
)


set(MAIN_XXX_INC_DIR
    ${MAIN_XXX_SRC_DIR}/Src/md_audio
    ${MAIN_XXX_SRC_DIR}/Src/md_LCD
    ${MAIN_XXX_SRC_DIR}/Src/md_menuApp
    ${MAIN_XXX_SRC_DIR}/Src/md_qspi
    ${MAIN_XXX_SRC_DIR}/Src/md_radarSensor
    ${MAIN_XXX_SRC_DIR}/Src/md_sdk_hal
    ${MAIN_XXX_SRC_DIR}/Src/md_sdRAM
    ${MAIN_XXX_SRC_DIR}/Src/md_touchScreen
    ${MAIN_XXX_SRC_DIR}/Src/md_usb_hhcd
    ${MAIN_XXX_SRC_DIR}/Src/md_uSD
    ${MAIN_XXX_SRC_DIR}/Src/md_uyRTC
    ${MAIN_XXX_SRC_DIR}/Src/md_wakeupButton
)

set(CODE_DIR_APP_SOURCE_MAIN_INCLUDE
    ${CONF_DIR}
    ${MAIN_XXX_INC_DIR}
    ${LIBS_DIR}
    ${APPS_DIR}
)

end_include()
