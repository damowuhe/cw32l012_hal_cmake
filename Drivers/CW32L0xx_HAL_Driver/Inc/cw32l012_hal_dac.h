/**
  ******************************************************************************
  * @file    cw32l012_hal_dac.h
  * @brief   DAC HAL module header
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_DAC_H
#define __CW32L012_HAL_DAC_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

typedef struct { uint32_t DAC_Trigger; uint32_t DAC_OutputBuffer; } DAC_ChannelConfTypeDef;

typedef struct __DAC_HandleTypeDef
{
  DAC_TypeDef *Instance;
  DAC_ChannelConfTypeDef Init;
  HAL_LockTypeDef Lock;
  __IO uint32_t State;
} DAC_HandleTypeDef;

HAL_StatusTypeDef HAL_DAC_Init(DAC_HandleTypeDef *hdac);
HAL_StatusTypeDef HAL_DAC_Start(DAC_HandleTypeDef *hdac, uint32_t Channel);
HAL_StatusTypeDef HAL_DAC_SetValue(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t Alignment, uint32_t Data);
void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac);

#ifdef __cplusplus
}
#endif
#endif
