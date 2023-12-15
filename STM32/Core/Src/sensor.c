/*
 * sensor.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Nhat Khai
 */

#include "sensor.h"

uint32_t sensorValue = 0;

void sensorRead(void) {
	sensorValue = HAL_ADC_GetValue(&hadc1);
}
