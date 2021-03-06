/*
 * beep.c
 *
 *  Created on: 2019年5月28日
 *      Author: ximikang
 */
#include "beep.h"
#include "IIC.h"

void init_beep(void)
{
    //P2SEL &= ~BEEP;
    P1DIR |= BEEP;
    P1OUT &= ~BEEP; //默认为关闭
}
void on_beep(void)
{
    P1OUT |= BEEP;
}
void off_beep(void)
{
    P1OUT &= ~BEEP;
}
void beep(void)
{
    on_beep();
    Delay_ms(1000);
    off_beep();
}

