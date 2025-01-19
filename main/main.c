#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"
#include "wifi.h"

void app_main(void)
{
    init_led();
    turn_on_led();

    init_wifi();
}
