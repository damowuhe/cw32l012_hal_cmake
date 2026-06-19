#include "cw32l012_hal_rtc.h"
HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef *hrtc) { UNUSED(hrtc); return HAL_OK; }
HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime) { UNUSED(hrtc);UNUSED(sTime); return HAL_OK; }
HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate) { UNUSED(hrtc);UNUSED(sDate); return HAL_OK; }
__WEAK void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc) { UNUSED(hrtc); }
