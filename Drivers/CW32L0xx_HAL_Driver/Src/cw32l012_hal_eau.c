#include "cw32l012_hal_eau.h"
HAL_StatusTypeDef HAL_EAU_Division(int32_t Dividend, int32_t Divisor, int32_t *Quotient, int32_t *Remainder) { if(Divisor==0)return HAL_ERROR; if(Quotient)*Quotient=Dividend/Divisor; if(Remainder)*Remainder=Dividend%Divisor; return HAL_OK; }
HAL_StatusTypeDef HAL_EAU_Sqrt(uint32_t Value, uint32_t *Result) { UNUSED(Value); if(Result)*Result=0; return HAL_OK; }
