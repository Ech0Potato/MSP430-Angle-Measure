/*
 * led.c
 *
 *  Created on: 2019��5��27��
 *      Author: ximikang
 */
#include "led.h"

void init_led(void) //��ʼ��led
{
    P1SEL &= ~BIT3;
    P1DIR |= BIT3;
    P1OUT |= BIT3; //Ĭ��Ϊ�ر�
}

void on_led(void) // ��led
{
    P1OUT &= ~BIT3;
}

void off_led(void) //�ر�led
{
    P1OUT |= BIT3;
}

void led_blink(void)
{
    P1OUT &= ~BIT3;
    Delay_ms(10);
    P1OUT |= BIT3;
}

