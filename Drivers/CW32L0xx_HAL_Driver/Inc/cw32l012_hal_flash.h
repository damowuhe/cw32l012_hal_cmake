/**
  ******************************************************************************
  * @file    cw32l012_hal_flash.h
  * @brief   FLASH HAL module header
  ******************************************************************************
  */
#ifndef __CW32L012_HAL_FLASH_H
#define __CW32L012_HAL_FLASH_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"

HAL_StatusTypeDef HAL_FLASH_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_Lock(void);
HAL_StatusTypeDef HAL_FLASH_ErasePage(uint32_t PageAddress);
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint32_t Data);

#ifdef __cplusplus
}
#endif
#endif
