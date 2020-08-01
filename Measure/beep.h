/*
 * beep.h
 *
 *  Created on: 2019年5月28日
 *      Author: ximikang
 */

#ifndef BEEP_H_
#define BEEP_H_

#include<msp430.h> //引用常用端口

#define BEEP BIT0 //定义了led的bit

extern void init_beep(void);
extern void on_beep(void);
extern void off_beep(void);
extern void beep(void);
void long_beep(void);
void short_beep(void);
void short_long_change(void);

#endif /* BEEP_H_ */
