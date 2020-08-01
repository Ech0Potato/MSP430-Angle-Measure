/*
 * led.h
 *
 *  Created on: 2019年5月27日
 *      Author: ximikang
 *
 *  初始化led和打开关闭led
 *  led Port port2 bin6
 *  (由于led的端口是时钟的xin口, 直接设置输出会无法输出电平，必须先选择模式)
 */

#ifndef LED_H_
#define LED_H_
#include<msp430.h> //引用常用端口
#include "IIC.h"

#define LED BIT6 //定义了led的bit


extern void init_led(void); // led初始化
extern void on_led(void); // 打开唯一的led
extern void off_led(void); // 关闭唯一的led
extern void led_blink(void);

#endif /* LED_H_ */
