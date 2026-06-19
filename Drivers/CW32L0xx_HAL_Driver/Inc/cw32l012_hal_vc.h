#ifndef __CW32L012_HAL_VC_H
#define __CW32L012_HAL_VC_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
HAL_StatusTypeDef HAL_VC_Init(VC_TypeDef *VCx);
HAL_StatusTypeDef HAL_VC_Start(VC_TypeDef *VCx);
#ifdef __cplusplus
}
#endif
#endif
