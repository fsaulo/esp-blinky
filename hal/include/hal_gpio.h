#pragma once

#include "driver/gpio.h"

namespace hal_gpio 
{
    class esp_base {
    protected:
        const gpio_num_t _pin;
        const gpio_config_t _cfg;
        const bool _inverted = false;

    public:
        constexpr esp_base(
            const gpio_num_t pin, 
            const gpio_config_t& cfg, 
            const bool invert = false
        ) :
            _pin{ pin },
            _cfg{ cfg },
            _inverted { invert }
        { }

        virtual bool state(void) = 0;
        virtual esp_err_t set(const bool state) = 0;

        [[nodiscard]] esp_err_t init(void);
    }; // esp_base

    class esp_out : public esp_base {
    private:
        bool _state = false;

    public:
        constexpr esp_out(
            const gpio_num_t pin,
            const bool invert = false
        ) : esp_base {
                pin,
                gpio_config_t {
                    .pin_bit_mask = static_cast<uint32_t>(1) << pin,
                    .mode         = GPIO_MODE_OUTPUT,
                    .pull_up_en   = GPIO_PULLUP_DISABLE,
                    .pull_down_en = GPIO_PULLDOWN_ENABLE,
                    .intr_type    = GPIO_INTR_DISABLE
                },
                invert
            }
        { }

        [[nodiscard]] esp_err_t init(void);

        // esp_err_t toggle(void);
        esp_err_t set(const bool state);
        bool state(void) { return _state; }
    }; // esp_out

    // class esp_input {
    // private:
    //     gpio_num_t _pin;
    //     const bool _inverted = false;
    //
    // public:
    //     esp_err_t init(void);
    //     bool state(void);
    //
    // };
}
