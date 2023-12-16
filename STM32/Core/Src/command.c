/*
 * command.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Nhat Khai
 */

#include "command.h"

static uint8_t commandTask = 0;
char commandString[UART_SIZE];

void commandExecute(void) {
	if (strcmp(commandString, "!RST#") == 0) {
		SCH_AddTask(sensorRead, 0, 0);
		commandTask = SCH_DeleteTask(commandTask);
		commandTask = SCH_AddTask(uartSend, 100, 3000);
		return;
	}
	if (strcmp(commandString, "!OK#") == 0) {
		commandTask = SCH_DeleteTask(commandTask);
		return;
	}
}

void commandParser(void) {
	if (uartIndex == 0) {
		if (uartBuffer[uartIndex] == '!') {
			uartIndex ++;
		}
	}
	else {
		if (uartBuffer[uartIndex] == '#') {
			sprintf(commandString, "%s", uartBuffer);
			SCH_AddTask(commandExecute, 0, 0);
			memset(uartBuffer, 0, UART_SIZE);
			uartIndex = 0;
		}
		else {
			if (uartIndex < UART_SIZE - 1) {
				uartIndex ++;
			}
		}
	}
}
