#include "cw32l012_hal_tim.h"
HAL_StatusTypeDef HAL_TIM_Base_Init(TIM_HandleTypeDef *htim) { UNUSED(htim); return HAL_OK; }
HAL_StatusTypeDef HAL_TIM_Base_Start(TIM_HandleTypeDef *htim) { UNUSED(htim); return HAL_OK; }
HAL_StatusTypeDef HAL_TIM_Base_Stop(TIM_HandleTypeDef *htim) { UNUSED(htim); return HAL_OK; }
HAL_StatusTypeDef HAL_TIM_PWM_Init(TIM_HandleTypeDef *htim) { UNUSED(htim); return HAL_OK; }
HAL_StatusTypeDef HAL_TIM_PWM_ConfigChannel(TIM_HandleTypeDef *htim, TIM_OC_InitTypeDef *sConfig, uint32_t Channel) { UNUSED(htim);UNUSED(sConfig);UNUSED(Channel); return HAL_OK; }
HAL_StatusTypeDef HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel) { UNUSED(htim);UNUSED(Channel); return HAL_OK; }
void HAL_TIM_IRQHandler(TIM_HandleTypeDef *htim) { UNUSED(htim); }
__WEAK void HAL_TIM_MspInit(TIM_HandleTypeDef *htim) { UNUSED(htim); }
