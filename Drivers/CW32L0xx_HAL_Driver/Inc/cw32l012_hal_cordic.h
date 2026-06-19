#ifndef __CW32L012_HAL_CORDIC_H
#define __CW32L012_HAL_CORDIC_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
HAL_StatusTypeDef HAL_CORDIC_Init(void);
HAL_StatusTypeDef HAL_CORDIC_Calculate(int32_t x, int32_t y, int32_t *result);
#ifdef __cplusplus
}
#endif
#endif
