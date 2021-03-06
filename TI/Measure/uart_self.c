/*
 * uart_self.c
 *
 *  Created on: 2020年7月31日
 *      Author: Ech0Potato
 */

#include "uart_self.h"


void UART_Init(){
      P1SEL |= BIT1 + BIT2 ;                     // P1.1 = RXD, P1.2=TXD
      P1SEL2 |= BIT1 + BIT2 ;                    // P1.1 = RXD, P1.2=TXD
      P1DIR |= BIT0;                             //p1.0外接LED为输出状态
      P1OUT &= ~BIT0;
      UCA0CTL1 |= UCSSEL_2;                     // SMCLK
      UCA0BR0 = 130;                            // 1MHz 9600
      UCA0BR1 = 6;                              // 1MHz 9600
      UCA0MCTL = UCBRS0;                        // Modulation UCBRSx = 1
      UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
      IE2 |= UCA0RXIE;                     // Enable USCI_A0 RX interrupt
      putchar('1');
//      __bis_SR_register(LPM0_bits+GIE);
}


void putchar(unsigned char tx_data) //发送字符函数
{
    while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready? 等待TX buffer为空
    UCA0TXBUF = tx_data;// TX -> RXed character? 发送字符c
}

void putstr(char *s)//发送字符串函数
{
IE2 &= ~UCA0RXIE;//发送时先关闭接收中断，不接收
//如果没有发完，就继续循环发送
while((*s)!='\0')
{
putchar(*s);
s++;
}
IE2 |= UCA0RXIE; //发送完了打开接收中断
}

void receive(char x){
   putchar(x);
}


#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void){
    while (!(IFG2&UCA0TXIFG));
    char RX_DATA=UCA0RXBUF;
    receive(RX_DATA);
}

