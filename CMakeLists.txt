

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_BOARD pico_w CACHE STRING "Board type")


include(pico_sdk_import.cmake)

project(Web_Server1 C CXX ASM)

pico_sdk_init()


add_executable(${PROJECT_NAME} Web_Server1.c 
            ${CMAKE_CURRENT_LIST_DIR}/libs/connect_wifi.c
            ${CMAKE_CURRENT_LIST_DIR}/libs/server.c
            ${CMAKE_CURRENT_LIST_DIR}/libs/init_config.c
            ${CMAKE_CURRENT_LIST_DIR}/libs/ssd1306.c
            ${CMAKE_CURRENT_LIST_DIR}/libs/global_manage.c
            ${CMAKE_CURRENT_LIST_DIR}/libs/buzzer.c)

pico_set_program_name(${PROJECT_NAME} "Web_Server1")
pico_set_program_version(${PROJECT_NAME} "0.1")

pico_enable_stdio_uart(${PROJECT_NAME} 0)
pico_enable_stdio_usb(${PROJECT_NAME} 1)

target_link_libraries(${PROJECT_NAME}
        pico_stdlib)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
        ${PICO_SDK_PATH}/lib/lwip/src/include
        ${PICO_SDK_PATH}/lib/lwip/src/include/arch
        ${PICO_SDK_PATH}/lib/lwip/src/include/lwip
)

target_sources(${PROJECT_NAME} PRIVATE
    ${PICO_SDK_PATH}/lib/lwip/src/apps/http/httpd.c
    ${PICO_SDK_PATH}/lib/lwip/src/apps/http/fs.c
)

target_link_libraries(${PROJECT_NAME}
        pico_cyw43_arch_lwip_threadsafe_background
        hardware_clocks
        hardware_pwm
        hardware_i2c)

pico_add_extra_outputs(${PROJECT_NAME})

