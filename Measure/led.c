/*
 * led.c
 *
 *  Created on: 2019年5月27日
 *      Author: ximikang
 */
#include "led.h"

void init_led(void) //初始化led
{
    P1SEL &= ~BIT3;
    P1DIR |= BIT3;
    P1OUT |= BIT3; //默认为关闭
}

void on_led(void) // 打开led
{
    P1OUT &= ~BIT3;
}

void off_led(void) //关闭led
{
    P1OUT |= BIT3;
}

void led_blink(void)
{
    P1OUT &= ~BIT3;
    Delay_ms(10);
    P1OUT |= BIT3;
}

