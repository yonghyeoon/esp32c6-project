#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "led.h"

static const char *TAG = "led";

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define LED_GPIO CONFIG_LED_GPIO
#define LED_BLINK_PERIOD CONFIG_LED_BLINK_PERIOD

static led_strip_handle_t led_strip;

static bool led_state = false;
static int r = 16, g = 16, b = 16;

static LedCommand command = LED_BLINK;

static TaskHandle_t ledTaskHandle;
// LED 태스크
static void led_task(void *pvParameters) {
    while (1) {
        switch (command)
        {
            case LED_BLINK:
                ESP_LOGI(TAG, "before on led!");
                on_led();   // LED 켜기
                ESP_LOGI(TAG, "after on led!");
                vTaskDelay(LED_BLINK_PERIOD / portTICK_PERIOD_MS); // 500ms 대기
                ESP_LOGI(TAG, "before off led!");
                off_led();  // LED 끄기
                ESP_LOGI(TAG, "after off led!");
                vTaskDelay(LED_BLINK_PERIOD / portTICK_PERIOD_MS); // 500ms 대기
                break;
            case LED_ON:
                if (!led_state) {
                    on_led();
                }
                break;
            
            default:
                break;
        }
    }
}

void led_set_pixel_color(int red, int green, int blue){
    r = red;
    g = green;
    b = blue;
}

void on_led(void) {
    if (!led_state) {
        /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
        led_strip_set_pixel(led_strip, 0, r, g, b);
        /* Refresh the strip to send data */
        led_strip_refresh(led_strip);
        led_state = true;
    }
}

void off_led(void) {
    if (led_state) {
        /* Set all LED off to clear all pixels */
        led_strip_clear(led_strip);
        led_state = false;
    }
}

void configure_led(void)
{
    ESP_LOGI(TAG, "configured LED!");
    /* LED strip initialization with the GPIO and pixels number*/
    led_strip_config_t strip_config = {
        .strip_gpio_num = LED_GPIO,
        .max_leds = 1, // at least one LED on board
    };
    ESP_LOGI(TAG, "%d", strip_config.led_pixel_format);

    // RMT - Remote Control Transceiver
    led_strip_rmt_config_t rmt_config = {
        .resolution_hz = 10 * 1000 * 1000, // 10MHz
        .flags.with_dma = false,
    };
    ESP_ERROR_CHECK(led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip));

    /* Set all LED off to clear all pixels */
    led_strip_clear(led_strip);
}

void init_led() {
    configure_led();
}

// LED 상태 변경
void set_command_led(LedCommand comm) {
    command = comm;
}

void turn_on_led(void) {
    xTaskCreate(&led_task, "LED Task", 2048, NULL, 0, &ledTaskHandle);
}