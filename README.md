# CW32L012 HAL 库 — CMake + GCC 工程模板

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![MCU](https://img.shields.io/badge/MCU-CW32L012C8T6-green)](http://www.whxy.com)
[![Core](https://img.shields.io/badge/Core-Cortex--M0+-lightgrey)]()

**武汉芯源 CW32L012 的 STM32 HAL 风格硬件抽象层**，API 完全对标 STM32F1 HAL，支持 CMake + GCC + OpenOCD 工具链。

> **免责声明**：本项目仅供参考学习，项目过程中出现的任何问题，作者不承担任何责任。使用本库即表示您已理解并同意此声明。

---

## 为什么选这个 HAL 库？

原厂 SDK 是寄存器级 LL 库（每个引脚一个宏，外设配置靠写寄存器）。本 HAL 库**参考 STM32F4/F1 HAL 架构重写**，提供：

| 特性 | 说明 |
|------|------|
| **F1 风格 API** | `HAL_GPIO_Init()`, `HAL_UART_Transmit()`, `HAL_TIM_PWM_Start()` |
| **Handle 结构体** | `UART_HandleTypeDef`, `TIM_HandleTypeDef` — 外设状态/锁/错误码统一管理 |
| **MSP 回调** | `HAL_UART_MspInit()` — 时钟/引脚/NVIC 解耦到用户层 |
| **中断 / DMA** | `HAL_UART_Transmit_IT()`, `_DMA()` 三种传输模式 |
| **自包含** | 直接操作寄存器，不依赖原厂库，`cw32l012.h` CMSIS 定义即可 |
| **完整覆盖** | 30 个外设模块，全部分立 .h/.c |

从 STM32 迁移到 CW32L012？改 `#include` + 改引脚号，其他代码不变。

---

## 快速开始

```bash
git clone https://github.com/damowuhe/cw32l012_hal_cmake.git
cd cw32l012_hal_cmake

# 编译
cmake --preset Debug
cmake --build build/Debug

# 烧录 (CMSIS-DAP)
cmake --build build/Debug --target flash
```

---

## OpenOCD 配置

`openocd/cw32l012.cfg` 是 CW32L012 的 OpenOCD 目标配置文件，需要复制到 OpenOCD 安装目录：

```bash
# 复制到 OpenOCD scripts 目录
cp openocd/cw32l012.cfg <OpenOCD安装路径>/scripts/target/
```

配置内容（基于用户手册寄存器）：

| 参数 | 值 | 说明 |
|------|-----|------|
| CPUTAPID | `0x0BC11477` | Cortex-M0+ SWD ID |
| Flash | `0x00000000` 64KB | Flash 基址 |
| RAM 工作区 | `0x20000000` 4KB | 8KB RAM 中分配 |
| Flash 控制器 | `0x40022000` | CW32L012 Flash 控制器 |
| 复位后频率 | 24MHz | HSI /4 |
| DBGMCU | `0x4000402C` | 调试时暂停看门狗/定时器 |

---

## 示例代码：LED 闪烁 (PC13)

```c
#include "main.h"

int main(void)
{
    SystemClock_Config();   // HSI 96MHz
    HAL_Init();             // SysTick 1ms
    MX_GPIO_Init();         // PC13 推挽输出

    while (1) {
        HAL_GPIO_TogglePin(CW_GPIOC, GPIO_PIN_13);
        HAL_Delay(500);
    }
}

static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    __HAL_RCC_GPIOC_CLK_ENABLE();

    GPIO_InitStruct.Pin   = GPIO_PIN_13;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;

    HAL_GPIO_Init(CW_GPIOC, &GPIO_InitStruct);
}
```

---

## HAL 库结构

```
Drivers/CW32L0xx_HAL_Driver/
├── Inc/                         # 30 个头文件
│   ├── cw32l012_hal.h           # 总头文件
│   ├── cw32l012_hal_def.h       # HAL 状态码 / Lock / Tick
│   ├── cw32l012_hal_conf.h      # 模块开关
│   ├── cw32l012_hal_gpio.h      # GPIO (F1 API)
│   ├── cw32l012_hal_gpio_ex.h   # GPIO 扩展 (AF / 滤波 / SWD)
│   ├── cw32l012_hal_rcc.h       # 时钟控制 (RCC)
│   ├── cw32l012_hal_dma.h       # DMA
│   ├── cw32l012_hal_uart.h      # UART (轮询 / 中断 / DMA)
│   ├── cw32l012_hal_spi.h       # SPI
│   ├── cw32l012_hal_i2c.h       # I2C
│   ├── cw32l012_hal_adc.h       # ADC
│   ├── cw32l012_hal_dac.h       # DAC
│   ├── cw32l012_hal_tim.h       # 定时器 (ATIM / GTIM1-4 / BTIM1-3)
│   ├── cw32l012_hal_lptim.h     # 低功耗定时器
│   ├── cw32l012_hal_rtc.h       # RTC
│   ├── cw32l012_hal_flash.h     # Flash
│   ├── cw32l012_hal_pwr.h       # 电源管理
│   ├── cw32l012_hal_iwdt.h      # 独立看门狗
│   ├── cw32l012_hal_wwdt.h      # 窗口看门狗
│   └── ... (crc, cordic, eau, lvd, vc, opa, irmod, debug, ram, digitalsign, halltim)
└── Src/                         # 28 个源文件 (对应实现)
```

---

## 环境要求

| 工具 | 版本 | 下载 |
|------|------|------|
| CMake | ≥ 3.22 | https://cmake.org |
| Ninja | any | `winget install Ninja-build.Ninja` |
| arm-none-eabi-gcc | ≥ 12.2 | https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads |
| OpenOCD | 0.11+ AT32 分支 | 含 CW32 flash 驱动 |

---

## CMake 目标

| 目标 | 说明 |
|------|------|
| `cw32l012` | 编译固件 |
| `flash` | 烧录 (CMSIS-DAP) |
| `flash-stlink` | 烧录 (ST-Link) |
| `reset` | 复位 |
| `erase` | 全片擦除 |
| `debug-ocd` | 启动 OpenOCD GDB 服务器 |

---

## 时钟配置

`SystemClock_Config()` 中修改频率，只需改 2 处：

| HSI 分频 | 频率 | Flash 等待 |
|----------|------|-----------|
| `RCC_HSI_DIV1` | 96MHz | `FLASH_LATENCY_3` |
| `RCC_HSI_DIV2` | 48MHz | `FLASH_LATENCY_1` |
| `RCC_HSI_DIV4` | 24MHz | `FLASH_LATENCY_0` |
| `RCC_HSI_DIV8` | 12MHz | `FLASH_LATENCY_0` |
| `RCC_HSI_DIV12` | 8MHz | `FLASH_LATENCY_0` |

支持 HSI / HSE / PLL / LSI / LSE 全部时钟源。

---

## HAL API 参考

```c
// === GPIO ===
HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState);
HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

// === RCC ===
__HAL_RCC_GPIOA_CLK_ENABLE();   // (宏, 非函数)
__HAL_RCC_UART1_CLK_ENABLE();
HAL_RCC_OscConfig(RCC_OscInitTypeDef *);
HAL_RCC_ClockConfig(RCC_ClkInitTypeDef *, uint32_t FLatency);

// === UART ===
HAL_UART_Init(UART_HandleTypeDef *);
HAL_UART_Transmit(UART_HandleTypeDef *, const uint8_t *, uint16_t, uint32_t Timeout);
HAL_UART_Receive_IT(UART_HandleTypeDef *, uint8_t *, uint16_t);
HAL_UART_IRQHandler(UART_HandleTypeDef *);

// === TIM ===
HAL_TIM_Base_Init(TIM_HandleTypeDef *);
HAL_TIM_PWM_Start(TIM_HandleTypeDef *, uint32_t Channel);
__HAL_TIM_SET_COMPARE(TIM_HandleTypeDef *, uint32_t Channel, uint32_t Compare);

// === System ===
HAL_Init();          // 配置 SysTick 1ms
HAL_Delay(500);      // 毫秒延时
HAL_GetTick();       // 系统 Tick
```

---

## 项目结构

```
cw32l012_hal_cmake/
├── CMakeLists.txt
├── CMakePresets.json
├── README.md
├── cmake/
│   ├── cw32cubemx/CMakeLists.txt
│   └── gcc-arm-none-eabi.cmake
├── Core/
│   ├── Inc/ (main.h, cw32l012_it.h)
│   └── Src/ (main.c, cw32l012_it.c, cw32l012_hal_msp.c, syscalls.c, sysmem.c)
├── Drivers/
│   ├── CMSIS/cw32l012/          # CMSIS-Core + 设备头文件
│   └── CW32L0xx_HAL_Driver/     # HAL 库 (30 Inc + 28 Src)
├── openocd/
│   └── cw32l012.cfg             # OpenOCD 目标配置文件
├── cw32l012_flash.ld            # 链接脚本
├── cw32l012.svd                 # SVD 调试寄存器视图
└── startup_cw32l012x8.s         # 启动汇编
```

---

## 许可

MIT License © 2025 damowuhe

---

## 参考

- [CW32L012 用户手册 V1.2](http://www.whxy.com)
- [STM32F4 HAL Driver](https://github.com/STMicroelectronics/stm32f4xx_hal_driver) — API 设计来源
- [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
