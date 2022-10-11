#pragma once

#ifndef LOG_LEVEL_LOCAL
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#endif

#ifndef LOG_TAG
#define LOG_TAG "Blink"
#endif

#ifndef CONFIG_FREERTOS_HZ
#define CONFIG_FREERTOS_HZ 100
#endif

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define pdSECOND pdMS_TO_TICKS(1000)

#include "hal_gpio.h"

class Blink final
{
public:
    esp_err_t setup(void);
    void run(void);
    
    hal_gpio::esp_out led{ GPIO_NUM_16, true };
};
