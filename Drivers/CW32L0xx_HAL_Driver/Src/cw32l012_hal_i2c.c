#include "cw32l012_hal_i2c.h"
HAL_StatusTypeDef HAL_I2C_Init(I2C_HandleTypeDef *hi2c) { UNUSED(hi2c); return HAL_OK; }
HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, const uint8_t *pData, uint16_t Size, uint32_t Timeout) { UNUSED(hi2c);UNUSED(DevAddress);UNUSED(pData);UNUSED(Size);UNUSED(Timeout); return HAL_OK; }
HAL_StatusTypeDef HAL_I2C_Master_Receive(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout) { UNUSED(hi2c);UNUSED(DevAddress);UNUSED(pData);UNUSED(Size);UNUSED(Timeout); return HAL_OK; }
void HAL_I2C_IRQHandler(I2C_HandleTypeDef *hi2c) { UNUSED(hi2c); }
__WEAK void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c) { UNUSED(hi2c); }
