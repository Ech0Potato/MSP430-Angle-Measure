/*
 * led.h
 *
 *  Created on: 2019��5��27��
 *      Author: ximikang
 *
 *  ��ʼ��led�ʹ򿪹ر�led
 *  led Port port2 bin6
 *  (����led�Ķ˿���ʱ�ӵ�xin��, ֱ������������޷������ƽ��������ѡ��ģʽ)
 */

#ifndef LED_H_
#define LED_H_
#include<msp430.h> //���ó��ö˿�
#include "IIC.h"

#define LED BIT6 //������led��bit


extern void init_led(void); // led��ʼ��
extern void on_led(void); // ��Ψһ��led
extern void off_led(void); // �ر�Ψһ��led
extern void led_blink(void);

#endif /* LED_H_ */
