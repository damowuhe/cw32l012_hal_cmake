/**
  ******************************************************************************
  * @file    cw32l012_hal_rcc.h
  * @brief   RCC HAL module header (STM32F1-style API)
  ******************************************************************************
  */

#ifndef __CW32L012_HAL_RCC_H
#define __CW32L012_HAL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cw32l012_hal_def.h"

/* --- Exported types --- */

/** @brief PLL Init structure */
typedef struct
{
  uint32_t PLLState;
  uint32_t PLLSource;
  uint32_t PLLMUL;
} RCC_PLLInitTypeDef;

/** @brief RCC Oscillator Init structure */
typedef struct
{
  uint32_t OscillatorType;
  uint32_t HSIState;
  uint32_t HSIDivider;
  uint32_t HSEState;
  uint32_t HSEFreq;
  uint8_t  HSEDriver;
  uint32_t LSIState;
  uint32_t LSEState;
  uint8_t  LSEDriver;
  uint32_t PLLState;
  RCC_PLLInitTypeDef PLL;
} RCC_OscInitTypeDef;

/** @brief RCC Clock Init structure */
typedef struct
{
  uint32_t ClockType;
  uint32_t SYSCLKSource;
  uint32_t AHBCLKDivider;
  uint32_t APB1CLKDivider;
  uint32_t APB2CLKDivider;
} RCC_ClkInitTypeDef;

/* --- Exported constants --- */

/* Oscillator types */
#define RCC_OSCILLATORTYPE_HSI      0x00000001U
#define RCC_OSCILLATORTYPE_HSE      0x00000002U
#define RCC_OSCILLATORTYPE_LSI      0x00000004U
#define RCC_OSCILLATORTYPE_LSE      0x00000008U
#define RCC_OSCILLATORTYPE_PLL      0x00000010U

/* Oscillator states */
#define RCC_HSI_ON                  ENABLE
#define RCC_HSI_OFF                 DISABLE
#define RCC_HSE_ON                  ENABLE
#define RCC_HSE_OFF                 DISABLE
#define RCC_LSI_ON                  ENABLE
#define RCC_LSI_OFF                 DISABLE
#define RCC_LSE_ON                  ENABLE
#define RCC_LSE_OFF                 DISABLE
#define RCC_PLL_ON                  ENABLE
#define RCC_PLL_OFF                 DISABLE

/* HSI dividers */
#define RCC_HSI_DIV1                ((uint32_t)(1UL  << 11))
#define RCC_HSI_DIV2                ((uint32_t)(2UL  << 11))
#define RCC_HSI_DIV4                ((uint32_t)(4UL  << 11))
#define RCC_HSI_DIV6                ((uint32_t)(6UL  << 11))
#define RCC_HSI_DIV8                ((uint32_t)(8UL  << 11))
#define RCC_HSI_DIV12               ((uint32_t)(11UL << 11))
#define RCC_HSI_DIV16               ((uint32_t)(12UL << 11))
#define RCC_HSI_DIV24               ((uint32_t)(14UL << 11))
#define RCC_HSI_DIV32               ((uint32_t)(0UL))

/* PLL source */
#define RCC_PLLSOURCE_HSI           0x00000000U
#define RCC_PLLSOURCE_HSE           0x00000001U

/* SYSCLK sources */
#define RCC_SYSCLKSOURCE_HSI        0x00000000U
#define RCC_SYSCLKSOURCE_HSE        0x00000001U
#define RCC_SYSCLKSOURCE_PLLCLK     0x00000002U
#define RCC_SYSCLKSOURCE_LSI        0x00000003U
#define RCC_SYSCLKSOURCE_LSE        0x00000004U

/* HCLK dividers */
#define RCC_SYSCLK_DIV1             (0x0UL << 5)
#define RCC_SYSCLK_DIV2             (0x1UL << 5)
#define RCC_SYSCLK_DIV4             (0x2UL << 5)
#define RCC_SYSCLK_DIV8             (0x3UL << 5)
#define RCC_SYSCLK_DIV16            (0x4UL << 5)
#define RCC_SYSCLK_DIV32            (0x5UL << 5)
#define RCC_SYSCLK_DIV64            (0x6UL << 5)
#define RCC_SYSCLK_DIV128           (0x7UL << 5)

/* PCLK dividers */
#define RCC_HCLK_DIV1               (0x0UL << 3)
#define RCC_HCLK_DIV2               (0x1UL << 3)
#define RCC_HCLK_DIV4               (0x2UL << 3)
#define RCC_HCLK_DIV8               (0x3UL << 3)

/* Clock types (for RCC_ClkInit.ClockType) */
#define RCC_CLOCKTYPE_SYSCLK        0x00000001U
#define RCC_CLOCKTYPE_HCLK          0x00000002U
#define RCC_CLOCKTYPE_PCLK1         0x00000004U
#define RCC_CLOCKTYPE_PCLK2         0x00000008U

/* Flash latency */
#define FLASH_LATENCY_0             0x00000000U
#define FLASH_LATENCY_1             0x00000001U
#define FLASH_LATENCY_2             0x00000002U
#define FLASH_LATENCY_3             0x00000003U

/* HSE mode */
#define RCC_HSE_MODE_OSC            0x00000000U
#define RCC_HSE_MODE_BYPASS         0x00000040U

/* SYSCTRL key register write protection */
#define SYSCTRL_KEY                 (0x5A5A0000U)
#define SYSCTRL_KEY_MASK            (0xFFFF0000U)

/* --- Exported functions --- */

/* Oscillator config */
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);

/* Clock config */
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *RCC_ClkInitStruct,
                                       uint32_t FLatency);

/* Individual oscillator control */
HAL_StatusTypeDef HAL_RCC_HSI_Enable(uint32_t HSIDiv);
void HAL_RCC_HSI_Disable(void);
HAL_StatusTypeDef HAL_RCC_LSI_Enable(void);
void HAL_RCC_LSI_Disable(void);
HAL_StatusTypeDef HAL_RCC_HSE_Enable(uint32_t Mode, uint32_t Freq, uint8_t Driver);
void HAL_RCC_HSE_Disable(void);
HAL_StatusTypeDef HAL_RCC_LSE_Enable(uint32_t Mode, uint8_t Driver);
void HAL_RCC_LSE_Disable(void);

/* Frequency getters */
uint32_t HAL_RCC_GetHCLKFreq(void);
uint32_t HAL_RCC_GetPCLK1Freq(void);
uint32_t HAL_RCC_GetSysClkFreq(void);

/* --- Peripheral clock enable/disable macros --- */

#define __HAL_RCC_GPIOA_CLK_ENABLE()    do { CW_SYSCTRL->AHBEN |= SYSCTRL_KEY | SYSCTRL_AHBEN_GPIOA_Msk; } while(0U)
#define __HAL_RCC_GPIOB_CLK_ENABLE()    do { CW_SYSCTRL->AHBEN |= SYSCTRL_KEY | SYSCTRL_AHBEN_GPIOB_Msk; } while(0U)
#define __HAL_RCC_GPIOC_CLK_ENABLE()    do { CW_SYSCTRL->AHBEN |= SYSCTRL_KEY | SYSCTRL_AHBEN_GPIOC_Msk; } while(0U)
#define __HAL_RCC_GPIOF_CLK_ENABLE()    do { CW_SYSCTRL->AHBEN |= SYSCTRL_KEY | SYSCTRL_AHBEN_GPIOF_Msk; } while(0U)
#define __HAL_RCC_DMA_CLK_ENABLE()      do { CW_SYSCTRL->AHBEN |= SYSCTRL_KEY | SYSCTRL_AHBEN_DMA_Msk; } while(0U)
#define __HAL_RCC_UART1_CLK_ENABLE()    do { CW_SYSCTRL->APBEN1 = (CW_SYSCTRL->APBEN1 & 0x0000FFFFU) | SYSCTRL_KEY | SYSCTRL_APBEN1_UART1_Msk; } while(0U)
#define __HAL_RCC_UART2_CLK_ENABLE()    do { CW_SYSCTRL->APBEN1 = (CW_SYSCTRL->APBEN1 & 0x0000FFFFU) | SYSCTRL_KEY | SYSCTRL_APBEN1_UART2_Msk; } while(0U)
#define __HAL_RCC_UART3_CLK_ENABLE()    do { CW_SYSCTRL->APBEN1 = (CW_SYSCTRL->APBEN1 & 0x0000FFFFU) | SYSCTRL_KEY | SYSCTRL_APBEN1_UART3_Msk; } while(0U)
#define __HAL_RCC_SPI1_CLK_ENABLE()     do { CW_SYSCTRL->APBEN1 = (CW_SYSCTRL->APBEN1 & 0x0000FFFFU) | SYSCTRL_KEY | SYSCTRL_APBEN1_SPI1_Msk; } while(0U)
#define __HAL_RCC_TIM1_CLK_ENABLE()     do { CW_SYSCTRL->APBEN1 = (CW_SYSCTRL->APBEN1 & 0x0000FFFFU) | SYSCTRL_KEY | SYSCTRL_APBEN1_ATIM_Msk; } while(0U)

#ifdef __cplusplus
}
#endif
#endif /* __CW32L012_HAL_RCC_H */
