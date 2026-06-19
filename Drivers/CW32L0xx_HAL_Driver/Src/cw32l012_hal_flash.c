#include "cw32l012_hal_flash.h"
HAL_StatusTypeDef HAL_FLASH_Unlock(void) { return HAL_OK; }
HAL_StatusTypeDef HAL_FLASH_Lock(void) { return HAL_OK; }
HAL_StatusTypeDef HAL_FLASH_ErasePage(uint32_t PageAddress) { UNUSED(PageAddress); return HAL_OK; }
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint32_t Data) { UNUSED(TypeProgram);UNUSED(Address);UNUSED(Data); return HAL_OK; }
