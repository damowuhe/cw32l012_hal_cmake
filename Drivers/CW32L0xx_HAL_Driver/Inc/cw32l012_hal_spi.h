/**
  ******************************************************************************
  * @file    cw32l012_hal_spi.h
  * @brief   SPI HAL module header
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_SPI_H
#define __CW32L012_HAL_SPI_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

typedef struct
{
  uint32_t Mode;
  uint32_t Direction;
  uint32_t DataSize;
  uint32_t CLKPolarity;
  uint32_t CLKPhase;
  uint32_t NSS;
  uint32_t BaudRatePrescaler;
  uint32_t FirstBit;
} SPI_InitTypeDef;

typedef struct __SPI_HandleTypeDef
{
  SPI_TypeDef *Instance;
  SPI_InitTypeDef Init;
  uint8_t *pTxBuffPtr;
  uint16_t TxXferSize;
  uint8_t *pRxBuffPtr;
  uint16_t RxXferSize;
  DMA_HandleTypeDef *hdmatx;
  DMA_HandleTypeDef *hdmarx;
  HAL_LockTypeDef Lock;
  __IO uint32_t State;
  __IO uint32_t ErrorCode;
} SPI_HandleTypeDef;

HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi);
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout);
void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi);
void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi);

#ifdef __cplusplus
}
#endif
#endif
