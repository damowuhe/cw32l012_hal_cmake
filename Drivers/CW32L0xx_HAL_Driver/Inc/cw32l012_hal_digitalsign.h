#ifndef __CW32L012_HAL_DIGITALSIGN_H
#define __CW32L012_HAL_DIGITALSIGN_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
void HAL_DIGITALSIGN_GetChipUid(uint8_t *pChipUid);
uint16_t HAL_DIGITALSIGN_GetFlashSize(void);
#ifdef __cplusplus
}
#endif
#endif
