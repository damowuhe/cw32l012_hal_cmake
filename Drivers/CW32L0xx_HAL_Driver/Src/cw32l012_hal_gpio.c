/**
  ******************************************************************************
  * @file    cw32l012_hal_gpio.c
  * @brief   GPIO HAL module driver (F1-style API)
  ******************************************************************************
  */

#include "cw32l012_hal_gpio.h"

/* REGBITS_SET/CLR already defined in base_types.h */

void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init)
{
  uint32_t position = 0x00U;
  uint32_t currentPin;

  assert_param(IS_GPIO_PIN(GPIO_Init->Pin));
  assert_param(IS_GPIO_MODE(GPIO_Init->Mode));

  while (((GPIO_Init->Pin) >> position) != 0U)
  {
    currentPin = (GPIO_Init->Pin) & (1UL << position);
    if (currentPin != 0x00U)
    {
      if (GPIO_Init->Mode == GPIO_MODE_ANALOG)
      {
        REGBITS_SET(GPIOx->ANALOG, currentPin);
      }
      else
      {
        REGBITS_CLR(GPIOx->ANALOG, currentPin);

        if ((GPIO_Init->Mode & 0xF0U) != 0U) /* IT mode — force input */
        {
          REGBITS_SET(GPIOx->DIR, currentPin);
          REGBITS_CLR(GPIOx->PUR, currentPin);
          if (GPIO_Init->Pull == GPIO_PULLUP)   REGBITS_SET(GPIOx->PUR, currentPin);
          REGBITS_CLR(GPIOx->RISEIE, currentPin);
          REGBITS_CLR(GPIOx->FALLIE, currentPin);
          if (GPIO_Init->Mode == GPIO_MODE_IT_RISING || GPIO_Init->Mode == GPIO_MODE_IT_RISING_FALLING)
            REGBITS_SET(GPIOx->RISEIE, currentPin);
          if (GPIO_Init->Mode == GPIO_MODE_IT_FALLING || GPIO_Init->Mode == GPIO_MODE_IT_RISING_FALLING)
            REGBITS_SET(GPIOx->FALLIE, currentPin);
        }
        else if (GPIO_Init->Mode == GPIO_MODE_INPUT)
        {
          REGBITS_SET(GPIOx->DIR, currentPin);
          REGBITS_CLR(GPIOx->PUR, currentPin);
          if (GPIO_Init->Pull == GPIO_PULLUP)   REGBITS_SET(GPIOx->PUR, currentPin);
        }
        else /* Output or AF */
        {
          REGBITS_CLR(GPIOx->DIR, currentPin);
          if (GPIO_Init->Mode == GPIO_MODE_OUTPUT_OD || GPIO_Init->Mode == GPIO_MODE_AF_OD)
            REGBITS_SET(GPIOx->OPENDRAIN, currentPin);
          else
            REGBITS_CLR(GPIOx->OPENDRAIN, currentPin);
        }
      }
    }
    position++;
  }
}

void HAL_GPIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin)
{
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  REGBITS_SET(GPIOx->ANALOG, GPIO_Pin);
  REGBITS_SET(GPIOx->DIR, GPIO_Pin);
  REGBITS_CLR(GPIOx->PUR, GPIO_Pin);
  REGBITS_CLR(GPIOx->RISEIE, GPIO_Pin);
  REGBITS_CLR(GPIOx->FALLIE, GPIO_Pin);
  REGBITS_CLR(GPIOx->OPENDRAIN, GPIO_Pin);
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  return (GPIOx->IDR & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  assert_param(IS_GPIO_PIN_ACTION(PinState));
  if (PinState == GPIO_PIN_SET) GPIOx->BSRR = GPIO_Pin;
  else                          GPIOx->BRR  = GPIO_Pin;
}

void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  assert_param(IS_GPIO_PIN(GPIO_Pin));
  GPIOx->TOG = GPIO_Pin;
}

HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  UNUSED(GPIOx); UNUSED(GPIO_Pin);
  return HAL_OK;
}
