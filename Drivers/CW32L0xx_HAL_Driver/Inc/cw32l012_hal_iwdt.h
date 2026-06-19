#ifndef __CW32L012_HAL_IWDT_H
#define __CW32L012_HAL_IWDT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
typedef struct { uint32_t Prescaler; uint32_t Reload; } IWDT_InitTypeDef;
typedef struct __IWDT_HandleTypeDef { IWDT_TypeDef *Instance; IWDT_InitTypeDef Init; HAL_LockTypeDef Lock; __IO uint32_t State; } IWDT_HandleTypeDef;
HAL_StatusTypeDef HAL_IWDT_Init(IWDT_HandleTypeDef *hiwdt);
HAL_StatusTypeDef HAL_IWDT_Refresh(IWDT_HandleTypeDef *hiwdt);
#ifdef __cplusplus
}
#endif
#endif
