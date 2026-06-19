cmake_minimum_required(VERSION 3.22)
# Enable CMake support for ASM and C languages
enable_language(C ASM)

# CW32L012 generated symbols (macros)
set(MX_Defines_Syms
    USE_HAL_DRIVER
    CW32L012x8
)

# CW32L012 generated include paths
set(MX_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CW32L0xx_HAL_Driver/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS/cw32l012/inc
)

# CW32L012 generated application sources
set(MX_Application_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/cw32l012_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/cw32l012_hal_msp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/sysmem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/syscalls.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../startup_cw32l012x8.s
)

# CW32L012 HAL/LL Drivers
set(CW32_Drivers_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS/cw32l012/src/system_cw32l012.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CW32L0xx_HAL_Driver/Src/cw32l012_hal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CW32L0xx_HAL_Driver/Src/cw32l012_hal_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CW32L0xx_HAL_Driver/Src/cw32l012_hal_gpio_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CW32L0xx_HAL_Driver/Src/cw32l012_hal_rcc.c
)

# Drivers Middlewares


# Link directories setup
set(MX_LINK_DIRS

)

# Project static libraries
set(MX_LINK_LIBS
    CW32_Drivers
    ${TOOLCHAIN_LINK_LIBRARIES}

)

# Interface library for includes and symbols
add_library(cw32cubemx INTERFACE)
target_include_directories(cw32cubemx INTERFACE ${MX_Include_Dirs})
target_compile_definitions(cw32cubemx INTERFACE ${MX_Defines_Syms})

# Create CW32_Drivers static library
add_library(CW32_Drivers OBJECT)
target_sources(CW32_Drivers PRIVATE ${CW32_Drivers_Src})
target_link_libraries(CW32_Drivers PUBLIC cw32cubemx)


# Add CW32 generated application sources to the project
target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${MX_Application_Src})

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE ${MX_LINK_DIRS})

# Add libraries to the project
target_link_libraries(${CMAKE_PROJECT_NAME} ${MX_LINK_LIBS})

# Add the map file to the list of files to be removed with 'clean' target
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES ADDITIONAL_CLEAN_FILES ${CMAKE_PROJECT_NAME}.map)

# Validate that generated code is compatible with C standard
if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(ERROR "Generated code requires C11 or higher")
endif()
