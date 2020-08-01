//#include "codetab.h"
#include <msp430.h> 
#include "adxl345.h"
#include "IIC.h"
#include "led.h"
#include "measure.h"
#include "beep.h"
#include "uart_self.h"
#include "double2str.h"
#include "communicate.h"
#include "state.h"
char str[20];
void System_Clock();

extern DroneRTInfo RT_Info;
int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // �ع�
    System_Clock(); //16M��Ƶ

 //====================INIT===========================
    IIC_Init();
    Buffer_Init();
    Init_ADXL345();
    init_led(); //��ʼ��led
    init_beep();
    UART_Init();

    __enable_interrupt();
    while(1)
    {

        on_led();
        make_angle();
//        Send_FeatureCode();
//        putstr("\r\n");
//        putstr("\r\n");

        //short_long_change();
//        make_angle();
//        putstr("Pitch: ");
//        int2str((int)RT_Info.Pitch,str);
//        putstr(str);
//        putstr(" Roll: ");
//        int2str((int)RT_Info.Roll,str);
//        putstr(str);
//        putstr(" Yaw: ");
//        int2str((int)RT_Info.Yaw,str);
//        putstr(str);
//        putstr("\r\n");
    }
}

void System_Clock()
{
    DCOCTL = 0x00;                          // Set DCOCLK to 16MHz
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
}


