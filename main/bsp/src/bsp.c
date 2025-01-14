#include "bsp.h"

static const char* TAG = "bsp";

void bspInit(void) {
    ESP_LOGI(TAG, "called bsp Init function!!");
    
}

void delay(uint32_t ms) {
    vTaskDelay(ms / portTICK_PERIOD_MS);
}