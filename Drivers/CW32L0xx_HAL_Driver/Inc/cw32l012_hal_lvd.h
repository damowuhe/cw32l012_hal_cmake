#ifndef __CW32L012_HAL_LVD_H
#define __CW32L012_HAL_LVD_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
HAL_StatusTypeDef HAL_LVD_Init(uint32_t Threshold);
HAL_StatusTypeDef HAL_LVD_Enable(void);
#ifdef __cplusplus
}
#endif
#endif
