#ifndef __CW32L012_HAL_EAU_H
#define __CW32L012_HAL_EAU_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
HAL_StatusTypeDef HAL_EAU_Division(int32_t Dividend, int32_t Divisor, int32_t *Quotient, int32_t *Remainder);
HAL_StatusTypeDef HAL_EAU_Sqrt(uint32_t Value, uint32_t *Result);
#ifdef __cplusplus
}
#endif
#endif
