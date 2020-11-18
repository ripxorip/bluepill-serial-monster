#include <stm32f1xx.h>
#include "dev_config.h"

// | Signal |   Direction   |     UART1     |     UART2     |     UART3     |
// |:-------|:-------------:|:--------------|:--------------|:--------------|
// |   RX   |      IN       |    **PA10**   |      PA3      |    **PB11**   |
// |   TX   |      OUT      |      PA9      |      PA2      |      PB10     |
// |   RTS  |      OUT      |      N/A      |      PA1      |      PB14     |
// |   CTS  |      IN       |      N/A      |      PA0      |    **PB13**   |
// |   DSR  |      IN       |    **PB7**    |    **PB4**    |    **PB6**    |
// |   DTR  |      OUT      |      PA4      |      PA5      |      PA6      |
// |   DCD  |      IN       |    **PB15**   |    **PB8**    |    **PB9**    |
 
static const device_config_t default_device_config = {
    .cdc_config = {
        .port_config = {
            /*  Port 0 */
            {
                .pins = 
                {
                    /*  rx */ { .port = GPIOA, .pin = 10, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_high },
                    /*  tx */ { .port = GPIOA, .pin =  9, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_alternate, .output = gpio_output_pp },
                    /* rts */ { .port = 0 }, /* No RTS due to the below reason  */
                    /* cts */ { .port = 0 }, /* CTS pin is occupied by USB      */
                    /* dsr */ { .port = GPIOB, .pin =  7, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_low },
                    /* dtr */ { .port = GPIOA, .pin =  4, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_general, .polarity = gpio_polarity_low },
                    /* dcd */ { .port = GPIOB, .pin = 15, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_low },
                }
            },
            /*  Port 1 */
            {
                .pins = 
                {
                    /*  rx */ { .port = GPIOA, .pin =  3, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_high },
                    /*  tx */ { .port = GPIOA, .pin =  2, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_alternate, .output = gpio_output_pp },
                    /* rts */ { .port = GPIOA, .pin =  1, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_alternate, .output = gpio_output_pp },
                    /* cts */ { .port = GPIOA, .pin =  0, .dir = gpio_dir_input,  .pull = gpio_pull_down, .polarity = gpio_polarity_low },
                    /* dsr */ { .port = GPIOB, .pin =  4, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_low },
                    /* dtr */ { .port = GPIOA, .pin =  5, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_general, .polarity = gpio_polarity_low },
                    /* dcd */ { .port = GPIOB, .pin =  8, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_low },
                }
            },
            /*  Port 2 */
            {
                .pins = 
                {
                    /*  rx */ { .port = GPIOB, .pin = 11, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_high },
                    /*  tx */ { .port = GPIOB, .pin = 10, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_alternate, .output = gpio_output_pp },
                    /* rts */ { .port = GPIOB, .pin = 14, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_alternate, .output = gpio_output_pp },
                    /* cts */ { .port = GPIOB, .pin = 13, .dir = gpio_dir_input,  .pull = gpio_pull_down, .polarity = gpio_polarity_low },
                    /* dsr */ { .port = GPIOB, .pin =  6, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_low },
                    /* dtr */ { .port = GPIOA, .pin =  6, .dir = gpio_dir_output, .speed = gpio_speed_medium, .func = gpio_func_general, .polarity = gpio_polarity_low },
                    /* dcd */ { .port = GPIOB, .pin =  9, .dir = gpio_dir_input,  .pull = gpio_pull_up, .polarity = gpio_polarity_low },
                }
            },
        }
    }
};

const device_config_t *device_config_get() {
    return &default_device_config;
}