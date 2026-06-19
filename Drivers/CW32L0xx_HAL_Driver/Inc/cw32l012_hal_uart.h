/**
  ******************************************************************************
  * @file    cw32l012_hal_uart.h
  * @brief   UART HAL module header
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_UART_H
#define __CW32L012_HAL_UART_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

/* UART base addresses defined in cw32l012.h */

typedef struct
{
  uint32_t BaudRate;
  uint32_t WordLength;
  uint32_t StopBits;
  uint32_t Parity;
  uint32_t Mode;
  uint32_t HwFlowCtl;
  uint32_t OverSampling;
} UART_InitTypeDef;

#define UART_MODE_TX_RX  0x00000003U
#define UART_PARITY_NONE 0x00000000U
#define UART_STOPBITS_1  0x00000000U

typedef struct __UART_HandleTypeDef
{
  UART_TypeDef *Instance;
  UART_InitTypeDef Init;
  const uint8_t *pTxBuffPtr;
  uint16_t TxXferSize;
  uint8_t *pRxBuffPtr;
  uint16_t RxXferSize;
  DMA_HandleTypeDef *hdmatx;
  DMA_HandleTypeDef *hdmarx;
  HAL_LockTypeDef Lock;
  __IO uint32_t gState;
  __IO uint32_t RxState;
  __IO uint32_t ErrorCode;
} UART_HandleTypeDef;

HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

#ifdef __cplusplus
}
#endif
#endif
