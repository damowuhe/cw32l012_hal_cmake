/**
  ******************************************************************************
  * @file    cw32l012_it.c
  * @brief   Interrupt Service Routines
  ******************************************************************************
  */

#include "main.h"
#include "cw32l012_it.h"

/**
  * @brief  SysTick handler — required for HAL_Delay()
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}
