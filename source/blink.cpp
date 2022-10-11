#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_log.h"

#include "blink.h"

static Blink blink;

extern "C" void app_main()
{
    ESP_ERROR_CHECK(blink.setup());

    for (;;) {
        blink.run();
    }
}

esp_err_t Blink::setup(void)
{
    esp_err_t status { ESP_OK };
    ESP_LOGI(LOG_TAG, "Setting up Blink application");
    
    status |= led.init();
    return status;
}

void Blink::run(void)
{
    ESP_LOGI(LOG_TAG, "Hello!");
    ESP_LOGD(LOG_TAG, "LED on");
    led.set(true);
    vTaskDelay(pdSECOND);

    ESP_LOGD(LOG_TAG, "LED off");
    led.set(false);
    vTaskDelay(pdSECOND);
}

