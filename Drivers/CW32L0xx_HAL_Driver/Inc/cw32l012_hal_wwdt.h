#ifndef __CW32L012_HAL_WWDT_H
#define __CW32L012_HAL_WWDT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
typedef struct { uint32_t Prescaler; uint32_t Window; uint32_t Counter; } WWDT_InitTypeDef;
typedef struct __WWDT_HandleTypeDef { WWDT_TypeDef *Instance; WWDT_InitTypeDef Init; HAL_LockTypeDef Lock; __IO uint32_t State; } WWDT_HandleTypeDef;
HAL_StatusTypeDef HAL_WWDT_Init(WWDT_HandleTypeDef *hwwdt);
#ifdef __cplusplus
}
#endif
#endif
