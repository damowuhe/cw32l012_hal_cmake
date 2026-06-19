#ifndef __CW32L012_HAL_LPTIM_H
#define __CW32L012_HAL_LPTIM_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
typedef struct { uint32_t Prescaler; uint32_t Period; } LPTIM_InitTypeDef;
typedef struct __LPTIM_HandleTypeDef { LPTIM_TypeDef *Instance; LPTIM_InitTypeDef Init; HAL_LockTypeDef Lock; __IO uint32_t State; } LPTIM_HandleTypeDef;
HAL_StatusTypeDef HAL_LPTIM_Init(LPTIM_HandleTypeDef *hlptim);
HAL_StatusTypeDef HAL_LPTIM_Start(LPTIM_HandleTypeDef *hlptim);
void HAL_LPTIM_MspInit(LPTIM_HandleTypeDef *hlptim);
#ifdef __cplusplus
}
#endif
#endif
