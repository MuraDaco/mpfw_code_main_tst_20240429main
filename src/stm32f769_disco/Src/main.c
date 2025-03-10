/**
  ******************************************************************************
  * @file    BSP/Src/main.c
  * @author  MCD Application Team
  * @brief   This example code shows how to use the STM32F769I_DISCOVERY BSP Drivers
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "main_msc_standalone.h"
#include "radar_sensor.h"
//#include "hwI2C.h"
#include "hwDS3231.h"
#include "stlogo.h"

/** @addtogroup STM32F7xx_HAL_Examples
  * @{
  */

/** @addtogroup BSP
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint8_t DemoIndex = 0;
__IO uint8_t NbLoop = 1;
__IO uint32_t SdmmcTest = 0;
__IO uint32_t SdramTest = 0;

/* Private function prototypes -----------------------------------------------*/
static void MPU_Config(void);
void SystemClock_Config(void);
static void Display_DemoDescription(void);
static void CPU_CACHE_Enable(void);

BSP_DemoTypedef  BSP_examples[]=
{
  {Touchscreen_demo1, "TOUCHSCREEN DEMO1", 0},
  {Touchscreen_demo2, "TOUCHSCREEN DEMO2", 0},
  // {USBH_demo, "USBH DEMO", 0},
  // {AudioPlay_demo, "AUDIO PLAY", 0},
  // {AudioLoopback_demo, "AUDIO RECORD AND PLAY", 0},
  {RadarSensor_demo, "Radar Sensor", 0},
  // {SD_FatFS_demo, "SD FatFS", 0},
  // {SD_demo, "SD", 0},
  // {QSPI_demo, "QSPI", 0},
  {LCD_demo, "LCD", 0},
  {SDRAM_demo, "SDRAM", 0},
  // {SDRAM_DMA_demo, "SDRAM DMA", 0}, // there is a problem 
  {Log_demo, "LCD LOG", 0},
};
/* Private functions ---------------------------------------------------------*/

// start - from MSC_Standalone   

// end - from MSC_Standalone   

uint32_t  i2c_result1;
uint32_t  i2c_result2;
// uint32_t  i2c_result3;
// uint32_t  i2c_result4;
// uint32_t  i2c_result5;
// uint32_t  i2c_result6;
// uint32_t  i2c_result7;
// uint8_t   i2c_reg_control;
// uint8_t   i2c_reg_control_status;
// uint8_t   i2c_reg_seconds;

//uint8_t    i2c_result = 0;
// uint8_t              i2c_step;
// HAL_I2C_StateTypeDef i2c_state;
// uint32_t             i2c_error;
// 
// HAL_StatusTypeDef    i2c_result2;
// uint8_t              i2c_step2;
// HAL_I2C_StateTypeDef i2c_state2;
// uint32_t             i2c_error2;

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  uint8_t  lcd_status = LCD_OK;

  /* Configure the MPU attributes */
  MPU_Config();

  /* Enable the CPU Cache */
  CPU_CACHE_Enable();

  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();
  
  /* Configure the system clock to 200 MHz */
  SystemClock_Config();
  
  BSP_LED_Init(LED_GREEN);
  BSP_LED_Init(LED_RED);
  
  BSP_LED_On(LED_GREEN);
  
  /* Configure the Tamper push-button in GPIO Mode */
  BSP_PB_Init(BUTTON_WAKEUP, BUTTON_MODE_GPIO);

  /* Initialize the LCD */
  lcd_status = BSP_LCD_Init();
  while(lcd_status != LCD_OK);
  
  BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
  
  // rtc_data_array[0] = 43;
  // rtc_data_array[1] = 41;
  // rtc_data_array[2] = 19;
  // rtc_data_array[3] = 1;
  // rtc_data_array[4] = 17;
  // rtc_data_array[5] = 04;
  // rtc_data_array[6] = 24;

  // hwI2C_Init();
  // // i2c_step = 0;
  // i2c_result1 = ds3231_init_status_report();
  i2c_result1 = ds3231_init(CLOCK_RUN, NO_FORCE_RESET);
  //i2c_result2 = ds3231_run_status();
  //if (kStatus_DS3231_Clock_Halt == i2c_result2) i2c_result3 = ds3231_run_command	(CLOCK_RUN);
  //i2c_result4 = ds3231_run_status();

  
  
  // if(kStatus_I2C_OK == i2c_result) {
  //   i2c_step++;
  //   i2c_result = hwI2C_Test();
  //   i2c_state  = hwI2C_State_Get();
  //   i2c_error  = hwI2C_Error_Get();
  // }

  //i2c_step2 = 0;
  //i2c_result2 = hwI2C_Init();
  //if(HAL_OK == i2c_result2) {
  //  i2c_step2++;
  //  i2c_result2 = hwI2C_Test2();
  //  i2c_state2  = hwI2C_State_Get();
  //  i2c_error2  = hwI2C_Error_Get();
  

  BSP_LCD_Clear(LCD_COLOR_WHITE);
  Display_DemoDescription();

  // start - from MSC_Standalone   
  // end - from MSC_Standalone   

  
  /* Wait For User inputs */
  while (1)
  {    

    if(BSP_PB_GetState(BUTTON_WAKEUP) == GPIO_PIN_SET)
    {
      while (BSP_PB_GetState(BUTTON_WAKEUP) == GPIO_PIN_SET);
      
      BSP_examples[DemoIndex++].DemoFunc();
      
      if(DemoIndex >= COUNT_OF_EXAMPLE(BSP_examples))
      {
        NbLoop++;
        DemoIndex = 0;
      }
      Display_DemoDescription();
    }
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 200000000
  *            HCLK(Hz)                       = 200000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 400
  *            PLL_P                          = 2
  *            PLL_Q                          = 8
  *            PLLSAI_N                       = 384
  *            PLLSAI_P                       = 8
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct; // from MSC_Standalone
  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;     // from MSC_Standalone
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  RCC_OscInitStruct.PLL.PLLR = 7;
  
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }
  
  /* Activate the OverDrive to reach the 200 MHz Frequency */  
  ret = HAL_PWREx_EnableOverDrive();
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }

  // start - from MSC_Standalone
  /* Select PLLSAI output as USB clock source */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLLSAIP;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 192;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 4;
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV4;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  // end - from MSC_Standalone

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2; 
  
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6);
  if(ret != HAL_OK)
  {
    while(1) { ; }
  }  
}

/**
  * @brief  Display main demo messages
  * @param  None
  * @retval None
  */
static void Display_DemoDescription(void)
{
  char desc[50];
  char str_i2c_status[40];
  uint8_t l_rtc_data_array[7];

  /* Set LCD Foreground Layer  */
  BSP_LCD_SelectLayer(0);

  BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
  
  /* Clear the LCD */ 
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE); 
  BSP_LCD_Clear(LCD_COLOR_WHITE);

  /* Set the LCD Text Color */
  BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);  

  /* Display LCD messages */
  //sprintf(str_i2c_status,"%08lx -> rtc control_status", i2c_result1);
  //BSP_LCD_DisplayStringAt(0, 10, (uint8_t *) str_i2c_status, CENTER_MODE);
  
  BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"STM32F769I BSP", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 35, (uint8_t *)"Drivers examples", CENTER_MODE);

  ds3231_read(TIME,   l_rtc_data_array);
  sprintf(str_i2c_status,"%02d.%02d.%02d / %02d:%02d:%02d", l_rtc_data_array[kIdDateTime_Day], l_rtc_data_array[kIdDateTime_Month], l_rtc_data_array[kIdDateTime_Year], l_rtc_data_array[kIdDateTime_Hour], l_rtc_data_array[kIdDateTime_Minute], l_rtc_data_array[kIdDateTime_Second]);
  BSP_LCD_DisplayStringAt(0, 135, (uint8_t *) str_i2c_status, CENTER_MODE);
  // sprintf(str_i2c_status,"%08lx -> rtc run_command", i2c_result3);
  // BSP_LCD_DisplayStringAt(0, 160, (uint8_t *) str_i2c_status, CENTER_MODE);
  // sprintf(str_i2c_status,"%08lx -> rtc run_status", i2c_result4);
  // BSP_LCD_DisplayStringAt(0, 185, (uint8_t *) str_i2c_status, CENTER_MODE);

  // sprintf(str_i2c_status,"%06lx-%06lx-%06lx -> rtc run_status", i2c_result5, i2c_result6, i2c_result7);
  // BSP_LCD_DisplayStringAt(0, 210, (uint8_t *) str_i2c_status, CENTER_MODE);
  // sprintf(str_i2c_status,"%02x-%02x-%02x -> rtc run_status", i2c_reg_control, i2c_reg_control_status, i2c_reg_seconds);
  // BSP_LCD_DisplayStringAt(0, 235, (uint8_t *) str_i2c_status, CENTER_MODE);

  //sprintf(str_i2c_status,"%02d-%02d-%02d-%04lx -> i2c_status", i2c_result2, i2c_step2, i2c_state2, i2c_error2);
  //BSP_LCD_DisplayStringAt(0, 150, (uint8_t *) str_i2c_status, CENTER_MODE);

  /* Draw Bitmap */
  BSP_LCD_DrawBitmap((BSP_LCD_GetXSize() - 80)/2, 65, (uint8_t *)stlogo);
  
  BSP_LCD_SetFont(&Font12);
  // BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize()- 20, (uint8_t *)"Copyright (c) STMicroelectronics 2016", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize()- 20, (uint8_t *)"Copyright (c) STMicroelectronics 2024", CENTER_MODE);
  
  BSP_LCD_SetFont(&Font16);
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_FillRect(0, BSP_LCD_GetYSize()/2 + 15, BSP_LCD_GetXSize(), 60);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE); 
  // BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 30, (uint8_t *)"Press User button to start :", CENTER_MODE);
     BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 30, (uint8_t *)"test_0419_0653_ press the Bt", CENTER_MODE);
  sprintf(desc,"%s example", BSP_examples[DemoIndex].DemoName);
  BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize()/2 + 45, (uint8_t *)desc, CENTER_MODE);   
}

/**
  * @brief  Check for user input
  * @param  None
* @retval Input state (1 : active / 0 : Inactive)
  */
uint8_t CheckForUserInput(void)
{
  if(BSP_PB_GetState(BUTTON_WAKEUP) == GPIO_PIN_SET)
  {
    while (BSP_PB_GetState(BUTTON_WAKEUP) == GPIO_PIN_SET);
    return 1 ;
  }
  return 0;
}

/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* Turn RED LED ON */  
  BSP_LED_On(LED_RED);
  /* Turn GREEN LED OFF */   
  BSP_LED_Off(LED_GREEN);
  while(1)
  {
  }
}

/**
  * @brief  Configure the MPU attributes
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;

  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU as Strongly ordered for not defined regions */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x00;
  MPU_InitStruct.Size = MPU_REGION_SIZE_4GB;
  MPU_InitStruct.AccessPermission = MPU_REGION_NO_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x87;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Configure the MPU attributes as WT for SDRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xC0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER1;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Configure the MPU QSPI flash */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x90000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_64MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER2;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x0;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;


  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  
  /* Configure the MPU attributes FMC control registers */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xA0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_8KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER3;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x0;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
  
  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */ 

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

// start - from MSC_Standalone



// end   - from MSC_Standalone

/**
  * @}
  */ 

/**
  * @}
  */
  
