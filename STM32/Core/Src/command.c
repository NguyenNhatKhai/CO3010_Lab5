/*
 * command.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Nhat Khai
 */

#include "command.h"

static uint8_t commandTask = 0;

void commandParser(void) {
	if (uartIndex == 0) {
		if (uartBuffer[uartIndex] == '!') {
			uartIndex ++;
		}
	}
	else if (uartBuffer[uartIndex] == '#') {
		if (strcmp((char*)uartBuffer, "!RST#") == 0) {
			SCH_AddTask(sensorRead, 0, 0);
			commandTask = SCH_DeleteTask(commandTask);
			commandTask = SCH_AddTask(uartSend, 100, 1000);
		}
		if (strcmp((char*)uartBuffer, "!OK#") == 0) {
			commandTask = SCH_DeleteTask(commandTask);
		}
		memset(uartBuffer, 0, UART_SIZE);
		uartIndex = 0;
	}
	else if (uartIndex < UART_SIZE - 1) {
		uartIndex ++;
	}
}
