#include "ap.h"
#include "bsp.h"

static const char* TAG = "ap";

void apInit(void) {

    ESP_LOGI(TAG, "called ap init function!!!");

    init_led();

    while (1) {
        delay(1000);
        set_led_state_toggle();
    }
}