/**
  ******************************************************************************
  * @file    cw32l012_hal_dma.h
  * @brief   DMA HAL module header
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_DMA_H
#define __CW32L012_HAL_DMA_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

#define DMA_CHANNEL_1      0U
#define DMA_CHANNEL_2      1U
#define DMA_CHANNEL_3      2U
#define DMA_CHANNEL_4      3U

typedef struct
{
  uint32_t SrcAddress;
  uint32_t DstAddress;
  uint32_t Size;
  uint32_t Direction;
  uint32_t PeriphInc;
  uint32_t MemInc;
  uint32_t PeriphDataAlign;
  uint32_t MemDataAlign;
  uint32_t Mode;
  uint32_t Priority;
} DMA_InitTypeDef;

typedef struct __DMA_HandleTypeDef
{
  void *Instance;
  DMA_InitTypeDef Init;
  HAL_LockTypeDef Lock;
  __IO uint32_t State;
  void *Parent;
} DMA_HandleTypeDef;

HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);

#ifdef __cplusplus
}
#endif
#endif
