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
## ******************************************************************
## __________________________________________________________________
## TST/APP CPP FILES Definitions
trace_execution()



# set(CODE_APP_TB_COMMON
#     ${MAIN_XXX_SRC_COMMON_DIR}/tb/tb/kr/krThread/v_${TB_KR_THREAD_VER}/krThreadTbl.cpp
#     ${MAIN_XXX_SRC_COMMON_DIR}/tb/tb/kr/krInit/v_${TB_KR_INIT_VER}/krInitStaticTbl.cpp
#     ${MAIN_XXX_SRC_COMMON_DIR}/tb/tb/kr/krTimer/v_${TB_KR_TIMER_VER}/krTimerTbl.cpp
#     ${MAIN_XXX_SRC_COMMON_DIR}/tb/tb/sv/svStateMachine/v_${TB_SV_STATE_MACHINE_VER}/svStateMachineTbl.cpp
# )


## --- set(CODE_MD_STARTUP_DIR
## ---     ${MAIN_XXX_SRC_DIR}/Src/md_startup/startup_stm32f769xx.s
## ---     ${MAIN_XXX_SRC_DIR}/Src/md_startup/syscalls.c
## --- )

## xxx set(CODE_INTERRUPTS_DIR
## xxx     ${MAIN_XXX_SRC_DIR}/Src/interrupt/stm32f7xx_it.c
## xxx )

set(CODE_MD_FREERTOS_DIR
    ${MAIN_XXX_SRC_DIR}/Src/md_freertos/freertos.c
)


set(CODE_MD_UY_RTC_DIR
    ${MAIN_XXX_SRC_DIR}/Src/md_uyRTC/hwI2C.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uyRTC/hwDS3231.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uyRTC/uyRTC.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uyRTC/uyRTC_interrupt_hndl.c
)

set(CODE_MD_RADAR_SENSOR_DIR
    ${MAIN_XXX_SRC_DIR}/Src/md_radarSensor/radar_sensor_hw.c
    ${MAIN_XXX_SRC_DIR}/Src/md_radarSensor/radar_sensor_interrupt_hndl.c
    ${MAIN_XXX_SRC_DIR}/Src/md_radarSensor/radar_sensor_log.c
    ${MAIN_XXX_SRC_DIR}/Src/md_radarSensor/radar_sensor.c
)

set(CODE_MD_uSD_DIR
    ${MAIN_XXX_SRC_DIR}/Src/md_uSD/file_operations_SD_FatFS.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uSD/explorer_SD_FatFS.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uSD/sd_interrupt_hndl.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uSD/sd_diskio.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uSD/sd.c
    ${MAIN_XXX_SRC_DIR}/Src/md_uSD/sd_FatFS.c
)

set(CODE_MD_WAKEUP_BUTTON_DIR
    ${MAIN_XXX_SRC_DIR}/Src/md_wakeupButton/wakeupButton_interrupt_hndl.c
    ${MAIN_XXX_SRC_DIR}/Src/md_wakeupButton/wakeupButton.c
)


set(CODE_SRC_DIR
## ---    ${MAIN_XXX_SRC_DIR}/Src/audio_loopback.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/audio_play.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/lcd.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/log.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/main.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/qspi.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/sd.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/sd_diskio.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/sd_FatFS.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/sdram.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/touchscreen.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/usbh.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/usbh_conf.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/usbh_diskio_dma.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/file_operations.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/file_operations_SD_FatFS.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/explorer.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/explorer_SD_FatFS.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/menu.c
## ---
## ---    ${MAIN_XXX_SRC_DIR}/Src/system_stm32f7xx.c
## ---
## ---
## ---    ${MAIN_XXX_SRC_DIR}/Src/uyGlo.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/uyRTC.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/radar_sensor.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/radar_sensor_log.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/md_uyRTC/hwI2C.c
## ---    ${MAIN_XXX_SRC_DIR}/Src/md_uyRTC/hwDS3231.c
)




set(CODE_APP_SOURCE_MAIN
    ${CODE_MD_FREERTOS_DIR}
    ${CODE_MD_uSD_DIR}
    ${CODE_MD_UY_RTC_DIR}
    ${CODE_MD_RADAR_SENSOR_DIR}
    ${CODE_MD_WAKEUP_BUTTON_DIR}
    ## --- ${CODE_AUDIO_DIR}
    ## --- ${CODE_SRC_DIR}
)

end_include()
