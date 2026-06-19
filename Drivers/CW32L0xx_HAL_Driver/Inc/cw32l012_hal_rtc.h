#ifndef __CW32L012_HAL_RTC_H
#define __CW32L012_HAL_RTC_H
#ifdef __cplusplus
extern "C" {
#endif
#include "cw32l012_hal_def.h"
typedef struct { uint32_t HourFormat; uint32_t AsynchPrediv; } RTC_InitTypeDef;
typedef struct { uint8_t Hours; uint8_t Minutes; uint8_t Seconds; } RTC_TimeTypeDef;
typedef struct { uint8_t WeekDay; uint8_t Month; uint8_t Date; uint8_t Year; } RTC_DateTypeDef;
typedef struct __RTC_HandleTypeDef { RTC_TypeDef *Instance; RTC_InitTypeDef Init; HAL_LockTypeDef Lock; __IO uint32_t State; } RTC_HandleTypeDef;
HAL_StatusTypeDef HAL_RTC_Init(RTC_HandleTypeDef *hrtc);
HAL_StatusTypeDef HAL_RTC_SetTime(RTC_HandleTypeDef *hrtc, RTC_TimeTypeDef *sTime);
HAL_StatusTypeDef HAL_RTC_SetDate(RTC_HandleTypeDef *hrtc, RTC_DateTypeDef *sDate);
void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc);
#ifdef __cplusplus
}
#endif
#endif
