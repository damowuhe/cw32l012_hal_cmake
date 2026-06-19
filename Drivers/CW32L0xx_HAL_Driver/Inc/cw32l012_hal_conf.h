/**
  ******************************************************************************
  * @file    cw32l012_hal_conf.h
  * @brief   HAL Configuration file
  ******************************************************************************
  */

#ifndef __CW32L012_HAL_CONF_H
#define __CW32L012_HAL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#define HAL_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED

#include "cw32l012_hal_def.h"

#ifdef USE_FULL_ASSERT
  #define HAL_ASSERT(x)  assert_param(x)
#else
  #define HAL_ASSERT(x)  ((void)0U)
#endif

#ifdef __cplusplus
}
#endif
#endif /* __CW32L012_HAL_CONF_H */
