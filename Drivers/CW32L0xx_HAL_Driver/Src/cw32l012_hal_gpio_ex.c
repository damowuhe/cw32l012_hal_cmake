/**
  ******************************************************************************
  * @file    cw32l012_hal_gpio_ex.c
  * @brief   GPIO HAL Extended module driver
  ******************************************************************************
  */

#include "cw32l012_hal_gpio_ex.h"

void HAL_GPIO_ConfigFilter(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint32_t FltClk)
{
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  GPIOx->FILTER = FltClk | GPIO_Pin;
}

void HAL_GPIO_ConfigAlternateFunction(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t Alternate)
{
  uint8_t i;
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  for (i = 0; i < 16; i++) if (GPIO_Pin == (1U << i)) break;
  if (i >= 16) return;
  if (i < 8)
    GPIOx->AFRL = (GPIOx->AFRL & (~(0xFU << (i * 4U)))) | ((uint32_t)Alternate << (i * 4U));
  else
    GPIOx->AFRH = (GPIOx->AFRH & (~(0xFU << ((i - 8U) * 4U)))) | ((uint32_t)Alternate << ((i - 8U) * 4U));
}

void HAL_GPIO_SWD2GPIO(void) { CW_SYSCTRL->CR2 = CW_SYSCTRL->CR2 | (0x5A5A0000U | (1UL << 1)); }
void HAL_GPIO_GPIO2SWD(void) { CW_SYSCTRL->CR2 = 0x5A5A0000U | (CW_SYSCTRL->CR2 & (~(1UL << 1))); }
