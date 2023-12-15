/*
 * led.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Nhat Khai
 */

#include "led.h"

void ledBlink(void) {
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}
