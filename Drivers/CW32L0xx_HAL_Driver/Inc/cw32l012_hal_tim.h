/**
  ******************************************************************************
  * @file    cw32l012_hal_tim.h
  * @brief   TIM HAL module header (ATIM/GTIM/BTIM)
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_TIM_H
#define __CW32L012_HAL_TIM_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

#define TIM_CHANNEL_1  0x00000000U
#define TIM_CHANNEL_2  0x00000001U
#define TIM_CHANNEL_3  0x00000002U
#define TIM_CHANNEL_4  0x00000003U
#define TIM_CHANNEL_5  0x00000004U
#define TIM_CHANNEL_6  0x00000005U

typedef struct
{
  uint32_t Prescaler;
  uint32_t CounterMode;
  uint32_t Period;
  uint32_t ClockDivision;
  uint32_t RepetitionCounter;
  uint32_t AutoReloadPreload;
} TIM_Base_InitTypeDef;

typedef struct
{
  uint32_t OCMode;
  uint32_t Pulse;
  uint32_t OCPolarity;
  uint32_t OCFastMode;
} TIM_OC_InitTypeDef;

typedef struct __TIM_HandleTypeDef
{
  void *Instance;
  TIM_Base_InitTypeDef Init;
  DMA_HandleTypeDef *hdma[TIM_CHANNEL_6 + 1U];
  HAL_LockTypeDef Lock;
  __IO uint32_t State;
  __IO uint32_t Channel;
} TIM_HandleTypeDef;

HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim);
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef *sConfig, uint32_t Channel);
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim);
void HAL_TIM_MspInit(TIM_HandleTypeDef *htim);

#define __HAL_TIM_SET_COMPARE(__HANDLE__, __CHANNEL__, __COMPARE__)  ((void)0U)

#ifdef __cplusplus
}
#endif
#endif
