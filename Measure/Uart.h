/*
 * Uart.h
 *
 *  Created on: 2020年7月23日
 *      Author: lenovo
 */

#ifndef UART_H_
#define UART_H_
#include <msp430.h> //引用常用端口

//------------------------------------------------------------------------------
// Conditions for 9600 Baud SW UART, SMCLK = 16MHz
//------------------------------------------------------------------------------
#define UART_TBIT_DIV_2     (16000000 / (9600 * 2))
#define UART_TBIT           (16000000 / 9600)


void TimerA_UART_init(void);
void TimerA_UART_tx(unsigned char byte);
void TimerA_UART_print(char *string);

#endif /* UART_H_ */
