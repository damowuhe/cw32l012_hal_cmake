/**
  ******************************************************************************
  * @file    cw32l012_hal_i2c.h
  * @brief   I2C HAL module header
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_I2C_H
#define __CW32L012_HAL_I2C_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

typedef struct
{
  uint32_t ClockSpeed;
  uint32_t DutyCycle;
  uint32_t OwnAddress1;
  uint32_t AddressingMode;
  uint32_t DualAddressMode;
} I2C_InitTypeDef;

typedef struct __I2C_HandleTypeDef
{
  I2C_TypeDef *Instance;
  I2C_InitTypeDef Init;
  uint8_t *pBuffPtr;
  uint16_t XferSize;
  DMA_HandleTypeDef *hdmatx;
  DMA_HandleTypeDef *hdmarx;
  HAL_LockTypeDef Lock;
  __IO uint32_t State;
  __IO uint32_t ErrorCode;
} I2C_HandleTypeDef;

HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c);
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);
void HAL_I2C_IRQHandler(I2C_HandleTypeDef *hi2c);
void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c);

#ifdef __cplusplus
}
#endif
#endif
