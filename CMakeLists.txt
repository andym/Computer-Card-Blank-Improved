cmake_minimum_required(VERSION 3.13)

# Initialize the Pico SDK
include(pico_sdk_import.cmake)

project(computer_card_blank_improved C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Add include directory
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Create the main executable
add_executable(computer_card_blank_improved
    src/main.cpp
)

# Link with necessary Pico libraries
target_link_libraries(computer_card_blank_improved
    pico_stdlib
    hardware_adc
    hardware_dma
    hardware_flash
    hardware_i2c
    hardware_irq
    hardware_pwm
    hardware_spi
    hardware_clocks
    hardware_gpio
    pico_multicore
)

# Enable USB output, disable UART output
pico_enable_stdio_usb(computer_card_blank_improved 1)
pico_enable_stdio_uart(computer_card_blank_improved 0)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(computer_card_blank_improved)
