#include "cw32l012_hal_uart.h"
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart) { UNUSED(huart); return HAL_OK; }
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart) { UNUSED(huart); return HAL_OK; }
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout) { UNUSED(huart);UNUSED(pData);UNUSED(Size);UNUSED(Timeout); return HAL_OK; }
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout) { UNUSED(huart);UNUSED(pData);UNUSED(Size);UNUSED(Timeout); return HAL_OK; }
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size) { UNUSED(huart);UNUSED(pData);UNUSED(Size); return HAL_OK; }
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size) { UNUSED(huart);UNUSED(pData);UNUSED(Size); return HAL_OK; }
void HAL_UART_IRQHandler(UART_HandleTypeDef *huart) { UNUSED(huart); }
__WEAK void HAL_UART_MspInit(UART_HandleTypeDef *huart) { UNUSED(huart); }
__WEAK void HAL_UART_MspDeInit(UART_HandleTypeDef *huart) { UNUSED(huart); }
