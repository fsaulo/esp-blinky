#include "hal_gpio.h"

namespace hal_gpio 
{
    [[nodiscard]] 
    esp_err_t esp_base::init(void)
    {
        esp_err_t status { ESP_OK };
        status |= gpio_config( &_cfg  );
        return status;
    }

    [[nodiscard]] 
    esp_err_t esp_out::init(void)
    {
        esp_err_t status { esp_base::init() };
        
        if ( ESP_OK == status ) {
            status |= set( _inverted );
        }

        return status;
    }
    
    esp_err_t esp_out::set(const bool state)
    {
        _state = state;
        return gpio_set_level(_pin, _inverted ? !state : state);
    }

} // namespace gpio
