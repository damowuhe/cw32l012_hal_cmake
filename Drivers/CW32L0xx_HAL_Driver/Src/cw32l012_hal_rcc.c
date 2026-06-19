/**
  ******************************************************************************
  * @file    cw32l012_hal_rcc.c
  * @brief   RCC HAL module driver (F1-style API)
  ******************************************************************************
  */

#include "cw32l012_hal_rcc.h"
#include "cw32l012_hal_gpio.h"

#define SYSCTRL_KEY_MASK (0xFFFF0000U)
#define HSIOSC_VALUE     96000000U
static const uint32_t hsiprs_tbl[] = {32,1,2,3,4,5,6,7,8,9,10,12,16,20,24,28};

/* Internal frequency helpers */
static uint32_t RCC_GetHClkFreq(void)
{
  uint32_t val = 0;
  switch (CW_SYSCTRL->CR0_f.SYSCLK)
  {
    case 0x00: val = HSIOSC_VALUE / hsiprs_tbl[CW_SYSCTRL->HSI_f.DIV]; break;
    case 0x02: val = HSIOSC_VALUE / 4 * CW_SYSCTRL->PLL_f.MUL; break;
    case 0x03: val = 32800U; break;
    case 0x04: val = 32768U; break;
    default:   val = HSIOSC_VALUE / hsiprs_tbl[CW_SYSCTRL->HSI_f.DIV]; break;
  }
  return val >> CW_SYSCTRL->CR0_f.HCLKPRS;
}

static uint32_t RCC_GetPClkFreq(void)
{
  return RCC_GetHClkFreq() >> CW_SYSCTRL->CR0_f.PCLKPRS;
}

/* ===== OscConfig ===== */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct)
{
  if (RCC_OscInitStruct->OscillatorType & RCC_OSCILLATORTYPE_HSI)
  {
    if (RCC_OscInitStruct->HSIState == RCC_HSI_ON)
    {
      uint16_t timeout = 0xffff;
      CW_SYSCTRL->HSI = (RCC_OscInitStruct->HSIDivider) | ((*((volatile uint16_t*)0x001007C0U)) & 0x7FF);
      CW_SYSCTRL->CR1 |= 0x5A5A0000U | (1UL << 0); /* HSIEN */
      while (((CW_SYSCTRL->HSI & (1UL << 15)) == 0) && timeout) timeout--;
      if (timeout == 0) return HAL_ERROR;
    }
    else { CW_SYSCTRL->CR1 = ((CW_SYSCTRL->CR1 & ~0xFFFF0000U) | 0x5A5A0000U) & ~(1UL << 0); }
  }

  if (RCC_OscInitStruct->OscillatorType & RCC_OSCILLATORTYPE_HSE)
  {
    if (RCC_OscInitStruct->HSEState == RCC_HSE_ON)
    {
      uint16_t timeout = 0xffff;
      CW_SYSCTRL->AHBEN |= 0x5A5A0000U | (1UL << 7); /* GPIOF */
      CW_GPIOF->ANALOG |= GPIO_PIN_0 | GPIO_PIN_1;
      CW_SYSCTRL->HSE = 0x00200000 | RCC_OscInitStruct->HSEFreq | RCC_HSE_MODE_OSC;
      CW_SYSCTRL->CR1 |= 0x5A5A0000U | (1UL << 8) | (1UL << 7) | (1UL << 1); /* CLKCCS+HSECCS+HSEEN */
      while (((CW_SYSCTRL->HSE & (1UL << 19)) == 0) && timeout) timeout--;
      if (timeout == 0) return HAL_ERROR;
    }
    else { CW_SYSCTRL->CR1 = ((CW_SYSCTRL->CR1 & ~0xFFFF0000U) | 0x5A5A0000U) & ~(1UL << 1); }
  }

  return HAL_OK;
}

/* ===== ClockConfig ===== */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct, uint32_t FLatency)
{
  /* Flash latency */
  /* FLASHWAIT at CR2[6:4], clear then set */
  CW_SYSCTRL->CR2 = 0x5A5A0000U | (CW_SYSCTRL->CR2 & ~(0x7UL << 4)) | ((FLatency & 0x7UL) << 4);

  if (RCC_ClkInitStruct->ClockType & (RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1))
  {
    CW_SYSCTRL->CR0 = (CW_SYSCTRL->CR0 & ~0xFFFF0000U) | 0x5A5A0000U
                      | RCC_ClkInitStruct->AHBCLKDivider
                      | RCC_ClkInitStruct->APB1CLKDivider;
  }

  if (RCC_ClkInitStruct->ClockType & RCC_CLOCKTYPE_SYSCLK)
  {
    CW_SYSCTRL->CR0 = (CW_SYSCTRL->CR0 & ~(0xFFFF0000U | 0x7U)) | 0x5A5A0000U
                      | RCC_ClkInitStruct->SYSCLKSource;
  }

  SystemCoreClock = RCC_GetHClkFreq();
  return HAL_OK;
}

/* ===== Individual oscillators ===== */
HAL_StatusTypeDef HAL_RCC_HSI_Enable(uint32_t HSIDiv)
{
  uint16_t timeout = 0xffff;
  CW_SYSCTRL->HSI = (HSIDiv) | ((*((volatile uint16_t*)0x001007C0U)) & 0x7FF);
  CW_SYSCTRL->CR1 |= 0x5A5A0000U | (1UL << 0);
  while (((CW_SYSCTRL->HSI & (1UL << 15)) == 0) && timeout) timeout--;
  return (timeout == 0) ? HAL_ERROR : HAL_OK;
}
void HAL_RCC_HSI_Disable(void) { CW_SYSCTRL->CR1 = 0x5A5A0000U | (CW_SYSCTRL->CR1 & ~(1UL << 0)); }

HAL_StatusTypeDef HAL_RCC_LSI_Enable(void)
{
  uint16_t timeout = 0xffff;
  CW_SYSCTRL->LSI |= (2UL << 10);
  CW_SYSCTRL->CR1 |= 0x5A5A0000U | (1UL << 3);
  while (((CW_SYSCTRL->LSI & (1UL << 15)) == 0) && timeout) timeout--;
  return (timeout == 0) ? HAL_ERROR : HAL_OK;
}
void HAL_RCC_LSI_Disable(void) { CW_SYSCTRL->CR1 = 0x5A5A0000U | (CW_SYSCTRL->CR1 & ~(1UL << 3)); }

/* Frequency getters */
uint32_t HAL_RCC_GetHCLKFreq(void)  { return RCC_GetHClkFreq(); }
uint32_t HAL_RCC_GetPCLK1Freq(void) { return RCC_GetPClkFreq(); }
uint32_t HAL_RCC_GetSysClkFreq(void) { return RCC_GetHClkFreq() << CW_SYSCTRL->CR0_f.HCLKPRS; }

/* Stub functions for unused oscillators */
HAL_StatusTypeDef HAL_RCC_HSE_Enable(uint32_t Mode, uint32_t Freq, uint8_t Driver) { UNUSED(Mode);UNUSED(Freq);UNUSED(Driver);return HAL_OK; }
void HAL_RCC_HSE_Disable(void) {}
HAL_StatusTypeDef HAL_RCC_LSE_Enable(uint32_t Mode, uint8_t Driver) { UNUSED(Mode);UNUSED(Driver);return HAL_OK; }
void HAL_RCC_LSE_Disable(void) {}
