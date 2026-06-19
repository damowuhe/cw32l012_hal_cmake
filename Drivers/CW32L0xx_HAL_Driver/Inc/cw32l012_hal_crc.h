#ifndef __CW32L012_HAL_CRC_H
#define __CW32L012_HAL_CRC_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
uint16_t HAL_CRC_Calculate(uint16_t CrcMode, const uint8_t *pData, uint32_t Size);
#ifdef __cplusplus
}
#endif
#endif
