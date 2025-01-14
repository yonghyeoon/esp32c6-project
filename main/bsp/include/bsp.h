#ifndef MAIN_BSP_BSP_H_
#define MAIN_BSP_BSP_H_

#include "def.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void bspInit();
void delay(uint32_t ms);

#endif /* MAIN_BSP_BSP_H_ */