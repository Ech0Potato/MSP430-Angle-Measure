//#include "codetab.h"
#include <msp430.h> 
#include "adxl345.h"
#include "IIC.h"
#include "led.h"
#include "measure.h"
#include "beep.h"
#include "Uart.h"
#include "uart_self.h"
#include "double2str.h"
void System_Clock();
extern DroneRTInfo RT_Info;
char double_buff[20];

double pitch_f;
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // �ع�
    System_Clock(); //16M��Ƶ

 //====================INIT===========================
    IIC_Init();
    Init_ADXL345();
    init_led(); //��ʼ��led
    init_beep();
//    UART_Init();
//    __enable_interrupt();

    while(1)
    {
        on_led();
        make_angle();
        pitch_f = RT_Info.B_Roll;
        float2str(pitch_f,double_buff,6);
        putstr(double_buff);
        putstr("\r\n");
    }
}

void System_Clock()
{
    DCOCTL = 0x00;                          // Set DCOCLK to 16MHz
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
}
