#include "cw32l012_hal_dma.h"
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma) { UNUSED(hdma); return HAL_OK; }
HAL_StatusTypeDef HAL_DMA_DeInit(DMA_HandleTypeDef *hdma) { UNUSED(hdma); return HAL_OK; }
HAL_StatusTypeDef HAL_DMA_Start(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength) { UNUSED(hdma);UNUSED(SrcAddress);UNUSED(DstAddress);UNUSED(DataLength); return HAL_OK; }
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma) { UNUSED(hdma); }
