/*
 * uart_self.h
 *
 *  Created on: 2020年7月31日
 *      Author: Ech0Potato
 */

#ifndef UART_SELF_H_
#define UART_SELF_H_

#include <msp430.h> //引用常用端口

void UART_Init();
void putchar(unsigned char tx_data);
void putstr(char *s);

#endif /* UART_SELF_H_ */
