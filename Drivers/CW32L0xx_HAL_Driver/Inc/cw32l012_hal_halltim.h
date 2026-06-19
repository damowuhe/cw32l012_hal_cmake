#ifndef __CW32L012_HAL_HALLTIM_H
#define __CW32L012_HAL_HALLTIM_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
typedef struct __HALLTIM_HandleTypeDef { HALLTIM_TypeDef *Instance; HAL_LockTypeDef Lock; __IO uint32_t State; } HALLTIM_HandleTypeDef;
HAL_StatusTypeDef HAL_HALLTIM_Init(HALLTIM_HandleTypeDef *hhall);
void HAL_HALLTIM_IRQHandler(HALLTIM_HandleTypeDef *hhall);
#ifdef __cplusplus
}
#endif
#endif
