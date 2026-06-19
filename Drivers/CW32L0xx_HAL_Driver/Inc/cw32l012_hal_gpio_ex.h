/**
  ******************************************************************************
  * @file    cw32l012_hal_gpio_ex.h
  * @brief   GPIO HAL Extended module header
  ******************************************************************************
  */

#ifndef __CW32L012_HAL_GPIO_EX_H
#define __CW32L012_HAL_GPIO_EX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cw32l012_hal_gpio.h"

/* Filter clock sources */
#define GPIO_FLTCLK_HCLK2       (((uint32_t)0) << 16)
#define GPIO_FLTCLK_HCLK4       (((uint32_t)1) << 16)
#define GPIO_FLTCLK_HCLK8       (((uint32_t)2) << 16)
#define GPIO_FLTCLK_BTIM1OV     (((uint32_t)3) << 16)
#define GPIO_FLTCLK_LSI         (((uint32_t)5) << 16)
#define GPIO_FLTCLK_LPTIMOV     (((uint32_t)7) << 16)

/* Alternate function values */
#define GPIO_AF0_GPIO           0x00U
#define GPIO_AF1                 0x01U
#define GPIO_AF2                 0x02U
#define GPIO_AF3                 0x03U
#define GPIO_AF4                 0x04U
#define GPIO_AF5                 0x05U
#define GPIO_AF6                 0x06U
#define GPIO_AF7                 0x07U
#define GPIO_AF8                 0x08U
#define GPIO_AF9                 0x09U

/* Exported functions */
void HAL_GPIO_ConfigFilter(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint32_t FltClk);
void HAL_GPIO_ConfigAlternateFunction(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, uint8_t Alternate);
void HAL_GPIO_SWD2GPIO(void);
void HAL_GPIO_GPIO2SWD(void);

#ifdef __cplusplus
}
#endif
#endif /* __CW32L012_HAL_GPIO_EX_H */
