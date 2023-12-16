/*
 * command.h
 *
 *  Created on: Dec 15, 2023
 *      Author: Nhat Khai
 */

#ifndef INC_COMMAND_H_
#define INC_COMMAND_H_

#include <string.h>
#include "scheduler.h"
#include "uart.h"

void commandExecute(void);
void commandParser(void);

#endif /* INC_COMMAND_H_ */
