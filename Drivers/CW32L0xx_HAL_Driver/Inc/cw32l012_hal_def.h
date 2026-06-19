/**
 ******************************************************************************
 * @file    cw32l012_hal_def.h
 * @brief   CW32L012 HAL common definitions
 *          Contains common types, lock mechanism, status codes and tick
 *          declarations used across all HAL modules.
 ******************************************************************************
 */

#ifndef __CW32L012_HAL_DEF_H
#define __CW32L012_HAL_DEF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "base_types.h"
#include "cw32l012.h"
#include "system_cw32l012.h"

/******************************************************************************
 * HAL Status
 ******************************************************************************/
typedef enum
{
    HAL_OK       = 0x00U,
    HAL_ERROR    = 0x01U,
    HAL_BUSY     = 0x02U,
    HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

/******************************************************************************
 * HAL Lock
 ******************************************************************************/
typedef enum
{
    HAL_UNLOCKED = 0x00U,
    HAL_LOCKED   = 0x01U
} HAL_LockTypeDef;

#define __HAL_LOCK(__HANDLE__)                                           \
    do {                                                                  \
        if ((__HANDLE__)->Lock == HAL_LOCKED)                             \
        {                                                                  \
            return HAL_BUSY;                                               \
        }                                                                  \
        else                                                               \
        {                                                                  \
            (__HANDLE__)->Lock = HAL_LOCKED;                              \
        }                                                                  \
    } while (0U)

#define __HAL_UNLOCK(__HANDLE__)                                         \
    do {                                                                  \
        (__HANDLE__)->Lock = HAL_UNLOCKED;                                \
    } while (0U)

/******************************************************************************
 * Peripheral State
 ******************************************************************************/
typedef enum
{
    HAL_PERIPH_STATE_RESET     = 0x00U,   /* Not initialized */
    HAL_PERIPH_STATE_READY     = 0x01U,   /* Initialized and ready */
    HAL_PERIPH_STATE_BUSY      = 0x02U,   /* Internal process ongoing */
    HAL_PERIPH_STATE_BUSY_TX   = 0x12U,   /* Data Transmission ongoing */
    HAL_PERIPH_STATE_BUSY_RX   = 0x22U,   /* Data Reception ongoing */
    HAL_PERIPH_STATE_BUSY_TX_RX = 0x32U,  /* Full-duplex ongoing */
    HAL_PERIPH_STATE_TIMEOUT   = 0x03U,   /* Timeout state */
    HAL_PERIPH_STATE_ERROR     = 0x04U    /* Error state */
} HAL_PeripheralStateTypeDef;

/******************************************************************************
 * HAL Tick / Delay
 ******************************************************************************/
#if !defined(UNUSED)
#define UNUSED(X) (void)(X)
#endif

#define HAL_MAX_DELAY    0xFFFFFFFFU
#define TICK_FREQ_1KHZ   1000U

extern __IO uint32_t uwTick;

HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_IncTick(void);
uint32_t HAL_GetTick(void);
void HAL_Delay(uint32_t Delay);

/******************************************************************************
 * HAL NVIC helpers
 ******************************************************************************/
#define HAL_NVIC_SetPriority(IRQn, Priority)     NVIC_SetPriority((IRQn), (Priority))
#define HAL_NVIC_EnableIRQ(IRQn)                 NVIC_EnableIRQ((IRQn))
#define HAL_NVIC_DisableIRQ(IRQn)                NVIC_DisableIRQ((IRQn))
#define HAL_NVIC_GetPriority(IRQn)               NVIC_GetPriority((IRQn))
#define HAL_NVIC_SystemReset(void)               NVIC_SystemReset()

/******************************************************************************
 * HAL SYSTICK configuration
 ******************************************************************************/
#define TICK_INT_PRIORITY    0x00U

/******************************************************************************
 * Assert helper macro (wraps existing assert_param)
 ******************************************************************************/
#define HAL_IS_BIT_SET(REG, BIT)         (((REG) & (BIT)) == (BIT))
#define HAL_IS_BIT_CLR(REG, BIT)         (((REG) & (BIT)) == 0U)

/******************************************************************************
 * Bit helper macros
 ******************************************************************************/
#ifndef bv
#define bv(n)                             ((uint32_t)1U << (n))
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CW32L012_HAL_DEF_H */
