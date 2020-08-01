/*
 * state.h
 *
 *  Created on: 2020Äê8ÔÂ1ÈÕ
 *      Author: Ech0Potato
 */

#ifndef STATE_H_
#define STATE_H_

#include<msp430.h>
void Buffer_Init(void);
void Command_Handler(char * command);
void Buffer_Init(void);
void StateMachine_Init(void);
void StateMachine(void);

#endif /* STATE_H_ */
