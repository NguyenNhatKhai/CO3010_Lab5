/*
 * uart.c
 *
 *  Created on: Dec 15, 2023
 *      Author: Nhat Khai
 */

#include "uart.h"

uint8_t uartChar = 0;
uint8_t uartBuffer[UART_SIZE];
uint8_t uartIndex = 0;
unsigned char uartFlag = 0;
char uartMessage[100];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) {
		uartBuffer[uartIndex] = uartChar;
		uartFlag = 1;
		HAL_UART_Receive_IT(&huart2, &uartChar, 1);
	}
}
void uartRead(void) {
	if (uartFlag == 1) {
		uartFlag = 0;
		SCH_AddTask(commandParser, 0, 0);
	}
}

void uartSend(void) {
	HAL_UART_Transmit(&huart2, (void*)uartMessage, sprintf(uartMessage, "\r\n!ADC=%ld#", sensorValue), 100);
}
