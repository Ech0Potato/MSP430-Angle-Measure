/*
 * IIC.h
 *
 *  Created on: 2019Äê3ÔÂ18ÈÕ
 *      Author: lenovo
 */
#include "MSP430G2553.h"
#ifndef IIC_H_
#define IIC_H_

#define CPU_F ((double)16000000)
#define Delay_us(x) _delay_cycles((long)(CPU_F*(double)x/1000000.0))
#define Delay_ms(x) _delay_cycles((long)(CPU_F*(double)x/1000.0))

#define IIC_SCL_1 (P2OUT |= BIT3)
#define IIC_SDA_1 (P2OUT |= BIT4)
#define IIC_SCL_0 (P2OUT &= ~(BIT3))
#define IIC_SDA_0 (P2OUT &= ~(BIT4))
#define IIC_SDA_OUT (P2DIR |= BIT4)
#define IIC_SDA_IN   (P2DIR &= ~BIT4)
#define IIC_READ_SDA (P2IN &= BIT4)

#define B_IIC_SCL_1 (P2OUT |= BIT0)
#define B_IIC_SDA_1 (P2OUT |= BIT1)
#define B_IIC_SCL_0 (P2OUT &= ~(BIT0))
#define B_IIC_SDA_0 (P2OUT &= ~(BIT1))
#define B_IIC_SDA_OUT (P2DIR |= BIT1)
#define B_IIC_SDA_IN   (P2DIR &= ~BIT1)
#define B_IIC_READ_SDA (P2IN &= BIT1)

void IIC_Init(void);
void IIC_SDAOut(void);
void IIC_SDAIn(void);
void IIC_Start(void);
void IIC_Stop(void);
unsigned char IIC_Waitack(void);
void IIC_Ack(void);
void IIC_Nack(void);
void IIC_Sendbyte(unsigned char IIC_Text);
unsigned char IIC_Readbyte(unsigned char IIC_ack);

void B_IIC_SDAOut(void);
void B_IIC_SDAIn(void);
void B_IIC_Start(void);
void B_IIC_Stop(void);
unsigned char B_IIC_Waitack(void);
void B_IIC_Ack(void);
void B_IIC_Nack(void);
void B_IIC_Sendbyte(unsigned char IIC_Text);
unsigned char B_IIC_Readbyte(unsigned char IIC_ack);
#endif /* IIC_H_ */
