#include "cw32l012_hal_spi.h"
HAL_StatusTypeDef HAL_SPI_Init(SPI_HandleTypeDef *hspi) { UNUSED(hspi); return HAL_OK; }
HAL_StatusTypeDef HAL_SPI_Transmit(SPI_HandleTypeDef *hspi, const uint8_t *pData, uint16_t Size, uint32_t Timeout) { UNUSED(hspi);UNUSED(pData);UNUSED(Size);UNUSED(Timeout); return HAL_OK; }
HAL_StatusTypeDef HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout) { UNUSED(hspi);UNUSED(pData);UNUSED(Size);UNUSED(Timeout); return HAL_OK; }
void HAL_SPI_IRQHandler(SPI_HandleTypeDef *hspi) { UNUSED(hspi); }
__WEAK void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi) { UNUSED(hspi); }
