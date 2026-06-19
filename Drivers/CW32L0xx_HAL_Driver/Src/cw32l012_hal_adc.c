#include "cw32l012_hal_adc.h"
HAL_StatusTypeDef HAL_ADC_Init(ADC_HandleTypeDef *hadc) { UNUSED(hadc); return HAL_OK; }
HAL_StatusTypeDef HAL_ADC_Start(ADC_HandleTypeDef *hadc) { UNUSED(hadc); return HAL_OK; }
HAL_StatusTypeDef HAL_ADC_Stop(ADC_HandleTypeDef *hadc) { UNUSED(hadc); return HAL_OK; }
HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef *hadc, uint32_t Timeout) { UNUSED(hadc);UNUSED(Timeout); return HAL_OK; }
uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef *hadc) { UNUSED(hadc); return 0U; }
void HAL_ADC_IRQHandler(ADC_HandleTypeDef *hadc) { UNUSED(hadc); }
__WEAK void HAL_ADC_MspInit(ADC_HandleTypeDef *hadc) { UNUSED(hadc); }
