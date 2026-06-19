#include "cw32l012_hal_dac.h"
HAL_StatusTypeDef HAL_DAC_Init(DAC_HandleTypeDef *hdac) { UNUSED(hdac); return HAL_OK; }
HAL_StatusTypeDef HAL_DAC_Start(DAC_HandleTypeDef *hdac, uint32_t Channel) { UNUSED(hdac);UNUSED(Channel); return HAL_OK; }
HAL_StatusTypeDef HAL_DAC_SetValue(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t Alignment, uint32_t Data) { UNUSED(hdac);UNUSED(Channel);UNUSED(Alignment);UNUSED(Data); return HAL_OK; }
__WEAK void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac) { UNUSED(hdac); }
