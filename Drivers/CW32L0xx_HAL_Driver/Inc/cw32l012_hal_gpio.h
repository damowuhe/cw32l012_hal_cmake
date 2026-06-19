/**
  ******************************************************************************
  * @file    cw32l012_hal_gpio.h
  * @brief   GPIO HAL module header (STM32F1-style API)
  ******************************************************************************
  */

#ifndef __CW32L012_HAL_GPIO_H
#define __CW32L012_HAL_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cw32l012_hal_def.h"

/* --- Exported types --- */
typedef struct
{
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Pull;
  uint32_t Speed;
} GPIO_InitTypeDef;

typedef enum { GPIO_PIN_RESET = 0U, GPIO_PIN_SET } GPIO_PinState;

/* --- GPIO pin defines --- */
#define GPIO_PIN_0       ((uint16_t)0x0001)
#define GPIO_PIN_1       ((uint16_t)0x0002)
#define GPIO_PIN_2       ((uint16_t)0x0004)
#define GPIO_PIN_3       ((uint16_t)0x0008)
#define GPIO_PIN_4       ((uint16_t)0x0010)
#define GPIO_PIN_5       ((uint16_t)0x0020)
#define GPIO_PIN_6       ((uint16_t)0x0040)
#define GPIO_PIN_7       ((uint16_t)0x0080)
#define GPIO_PIN_8       ((uint16_t)0x0100)
#define GPIO_PIN_9       ((uint16_t)0x0200)
#define GPIO_PIN_10      ((uint16_t)0x0400)
#define GPIO_PIN_11      ((uint16_t)0x0800)
#define GPIO_PIN_12      ((uint16_t)0x1000)
#define GPIO_PIN_13      ((uint16_t)0x2000)
#define GPIO_PIN_14      ((uint16_t)0x4000)
#define GPIO_PIN_15      ((uint16_t)0x8000)
#define GPIO_PIN_All     ((uint16_t)0xFFFF)
#define GPIO_PIN_MASK    0x0000FFFFU

/* --- GPIO modes --- */
#define GPIO_MODE_INPUT                     0x00U
#define GPIO_MODE_OUTPUT_PP                 0x01U
#define GPIO_MODE_OUTPUT_OD                 0x02U
#define GPIO_MODE_AF_PP                     0x03U
#define GPIO_MODE_AF_OD                     0x04U
#define GPIO_MODE_ANALOG                    0x05U
#define GPIO_MODE_IT_RISING                 0x10U
#define GPIO_MODE_IT_FALLING                0x11U
#define GPIO_MODE_IT_RISING_FALLING         0x12U

/* --- GPIO pull --- */
#define GPIO_NOPULL        0x00000000U
#define GPIO_PULLUP        0x00000001U
#define GPIO_PULLDOWN      0x00000002U

/* --- GPIO speed --- */
#define GPIO_SPEED_FREQ_LOW         0x00000000U
#define GPIO_SPEED_FREQ_MEDIUM      0x00000001U
#define GPIO_SPEED_FREQ_HIGH        0x00000002U
#define GPIO_SPEED_FREQ_VERY_HIGH   0x00000003U

/* --- Exported functions --- */
void  HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void  HAL_GPIO_DeInit(GPIO_TypeDef *GPIOx, uint32_t GPIO_Pin);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void  HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void  HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#include "cw32l012_hal_gpio_ex.h"

/* --- Private macros --- */
#define IS_GPIO_PIN_ACTION(ACTION)  (((ACTION) == GPIO_PIN_RESET) || ((ACTION) == GPIO_PIN_SET))
#define IS_GPIO_PIN(PIN)            ((((uint32_t)PIN) & GPIO_PIN_MASK) != 0x00U)
#define IS_GPIO_MODE(MODE)          (((MODE) == GPIO_MODE_INPUT)              ||\
                                     ((MODE) == GPIO_MODE_OUTPUT_PP)          ||\
                                     ((MODE) == GPIO_MODE_OUTPUT_OD)          ||\
                                     ((MODE) == GPIO_MODE_AF_PP)              ||\
                                     ((MODE) == GPIO_MODE_AF_OD)              ||\
                                     ((MODE) == GPIO_MODE_ANALOG)             ||\
                                     ((MODE) == GPIO_MODE_IT_RISING)          ||\
                                     ((MODE) == GPIO_MODE_IT_FALLING)         ||\
                                     ((MODE) == GPIO_MODE_IT_RISING_FALLING))
#define IS_GPIO_PULL(PULL)          (((PULL) == GPIO_NOPULL) || ((PULL) == GPIO_PULLUP) || ((PULL) == GPIO_PULLDOWN))

#ifdef __cplusplus
}
#endif
#endif /* __CW32L012_HAL_GPIO_H */
