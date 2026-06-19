/**
  ******************************************************************************
  * @file    cw32l012_hal_adc.h
  * @brief   ADC HAL module header
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_ADC_H
#define __CW32L012_HAL_ADC_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

typedef struct
{
  uint32_t ClockPrescaler;
  uint32_t Resolution;
  uint32_t DataAlign;
  uint32_t ScanConvMode;
  uint32_t ContinuousConvMode;
  uint32_t NbrOfConversion;
} ADC_InitTypeDef;

typedef struct
{
  uint32_t Channel;
  uint32_t Rank;
  uint32_t SamplingTime;
} ADC_ChannelConfTypeDef;

typedef struct __ADC_HandleTypeDef
{
  ADC_TypeDef *Instance;
  ADC_InitTypeDef Init;
  DMA_HandleTypeDef *DMA_Handle;
  HAL_LockTypeDef Lock;
  __IO uint32_t State;
  __IO uint32_t ErrorCode;
} ADC_HandleTypeDef;

HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef *hadc);
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef *hadc, uint32_t Timeout);
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef *hadc);
void HAL_ADC_IRQHandler(ADC_HandleTypeDef *hadc);
void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc);

#ifdef __cplusplus
}
#endif
#endif
