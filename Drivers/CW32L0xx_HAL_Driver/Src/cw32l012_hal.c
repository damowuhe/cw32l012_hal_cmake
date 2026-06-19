/**
 ******************************************************************************
 * @file    cw32l012_hal.c
 * @brief   CW32L012 HAL core functions
 *          HAL_Init, HAL_DeInit, HAL_IncTick, HAL_GetTick, HAL_Delay
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "cw32l012_hal_def.h"
#include "cw32l012_hal_rcc.h"

/* Private variables ---------------------------------------------------------*/
__IO uint32_t uwTick = 0U;

/* Private function prototypes -----------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
 * @brief  Initialize the HAL Library; called at program startup.
 *         Configures the SysTick to generate 1ms interrupts.
 * @param  none
 * @retval HAL_StatusTypeDef
 */
HAL_StatusTypeDef HAL_Init(void)
{
    /* Configure SysTick to generate 1ms interrupts */
    if (SysTick_Config(SystemCoreClock / TICK_FREQ_1KHZ) != 0U)
    {
        return HAL_ERROR;  /* SysTick configuration failed */
    }

    /* Set SysTick interrupt priority (lowest) */
    NVIC_SetPriority(SysTick_IRQn, (1U << __NVIC_PRIO_BITS) - 1U);

    return HAL_OK;
}

/**
 * @brief  De-initialize the HAL Library.
 *         Disables SysTick and resets tick counter.
 * @param  none
 * @retval HAL_StatusTypeDef
 */
HAL_StatusTypeDef HAL_DeInit(void)
{
    /* Disable SysTick */
    SysTick->CTRL = 0U;

    /* Reset tick counter */
    uwTick = 0U;

    return HAL_OK;
}

/**
 * @brief  Increment the system tick (uwTick).
 *         Must be called from SysTick_Handler().
 * @param  none
 * @retval none
 */
void HAL_IncTick(void)
{
    uwTick++;
}

/**
 * @brief  Get the current system tick value in milliseconds.
 * @param  none
 * @retval uint32_t  Current tick value (ms)
 */
uint32_t HAL_GetTick(void)
{
    return uwTick;
}

/**
 * @brief  Blocking delay in milliseconds.
 *         Relies on HAL_IncTick() being called from SysTick_Handler().
 * @param  Delay   Delay duration in milliseconds
 * @retval none
 */
void HAL_Delay(uint32_t Delay)
{
    uint32_t tickstart = HAL_GetTick();
    uint32_t wait = Delay;

    /* Add one tick to guarantee minimum delay */
    if (wait < 0xFFFFFFFFU)
    {
        wait++;
    }

    while ((HAL_GetTick() - tickstart) < wait)
    {
        /* Wait */
    }
}

/**
 * @brief  SysTick interrupt handler.
 *         Calls HAL_IncTick() to increment the system tick.
 *         Users can add their own code in the callback section.
 * @param  none
 * @retval none
 */
__WEAK void SysTick_Handler(void)
{
    HAL_IncTick();
}
