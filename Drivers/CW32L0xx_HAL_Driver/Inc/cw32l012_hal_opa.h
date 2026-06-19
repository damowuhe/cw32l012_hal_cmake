#ifndef __CW32L012_HAL_OPA_H
#define __CW32L012_HAL_OPA_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
HAL_StatusTypeDef HAL_OPA_Init(OPA_TypeDef *OPAx);
HAL_StatusTypeDef HAL_OPA_Start(OPA_TypeDef *OPAx);
#ifdef __cplusplus
}
#endif
#endif
