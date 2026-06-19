#include "cw32l012_hal_pwr.h"
void HAL_PWR_EnterSleepMode(void) { SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk; __DSB(); __WFI(); }
void HAL_PWR_EnterDeepSleepMode(void) { SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; __DSB(); __WFI(); }
