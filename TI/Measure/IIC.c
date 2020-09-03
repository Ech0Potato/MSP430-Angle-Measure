/*
 * IIC.c
 *
 *  Created on: 2019年3月18日
 *      Author: lenovo
 */
#include "IIC.h"
//初始化IIC
void IIC_Init(void)
{
    P2DIR |= BIT3;    //SCL
    P2DIR |= BIT4;    //SDA

    P2DIR |= BIT0;    //SCL
    P2DIR |= BIT1;    //SDA
    //将二者置高
    IIC_SCL_1;
    IIC_SDA_1;

    B_IIC_SCL_1;
    B_IIC_SDA_1;

}

//数据输出
void IIC_SDAOut(void)
{
    P2DIR |= BIT4;
}


//数据输入
void IIC_SDAIn(void)
{
    P2DIR &= ~BIT4;
}


void IIC_Start(void)
{
    IIC_SDA_OUT;
    IIC_SDA_1;
    IIC_SCL_1;
    Delay_us(5);
    IIC_SDA_0;
    Delay_us(5);
    IIC_SCL_0;
}


void IIC_Stop(void)
{
    IIC_SDA_OUT;

    IIC_SCL_0;
    IIC_SDA_0;
    Delay_us(5);
    IIC_SCL_1;
    IIC_SDA_1;
    Delay_us(5);
}


unsigned char IIC_Waitack(void)
{
    unsigned char IIC_Waitlimit=0;
    IIC_SDA_IN;
    IIC_SDA_1;
    Delay_us(1);
    IIC_SCL_1;
    Delay_us(1);
    while(IIC_READ_SDA)
    {
        IIC_Waitlimit++;
        if(IIC_Waitlimit>250)
        {
            IIC_Stop();
            return 1;
        }
    }
    IIC_SCL_0;
    return 0;
}



void IIC_Ack(void)
{
    IIC_SCL_0;
    IIC_SDA_OUT;
    IIC_SDA_0;

    Delay_us(2);
    IIC_SCL_1;
    Delay_us(5);
    IIC_SCL_0;
}


void IIC_Nack(void)
{
    IIC_SCL_0;
    IIC_SDA_OUT;
    IIC_SDA_1;

    Delay_us(2);
    IIC_SCL_1;
    Delay_us(2);
    IIC_SCL_0;
}



void IIC_Sendbyte(unsigned char IIC_Text)
{
    unsigned char IIC_Temp;
    IIC_SDA_OUT;
    IIC_SCL_0;

    for(IIC_Temp=0;IIC_Temp<8;IIC_Temp++)
    {
        if(IIC_Text&0x80)
            IIC_SDA_1;
        else
            IIC_SDA_0;
        IIC_Text<<=1;
        //Delay_us(2);
        IIC_SCL_1;
        Delay_us(2);
        IIC_SCL_0;
        Delay_us(2);
    }
}


unsigned char IIC_Readbyte(unsigned char IIC_ack)
{
    unsigned char IIC_Temp,IIC_Reseave=0;
    IIC_SDA_IN;
    for(IIC_Temp=0;IIC_Temp<8;IIC_Temp++)
    {
        IIC_SCL_0;
        Delay_us(2);
        IIC_SCL_1;
        IIC_Reseave<<=1;
        if(IIC_READ_SDA)
            IIC_Reseave++;
        Delay_us(1);
    }
    if(!IIC_ack)
        IIC_Nack();
    else
        IIC_Ack();
    return IIC_Reseave;
}
/****************************************************************************************/
//数据输出
void B_IIC_SDAOut(void)
{
    P2DIR |= BIT1;
}


//数据输入
void B_IIC_SDAIn(void)
{
    P2DIR &= ~BIT1;
}


void B_IIC_Start(void)
{
    B_IIC_SDA_OUT;
    B_IIC_SDA_1;
    B_IIC_SCL_1;
    Delay_us(5);
    B_IIC_SDA_0;
    Delay_us(5);
    B_IIC_SCL_0;
}


void B_IIC_Stop(void)
{
    B_IIC_SDA_OUT;

    B_IIC_SCL_0;
    B_IIC_SDA_0;
    Delay_us(5);
    B_IIC_SCL_1;
    B_IIC_SDA_1;
    Delay_us(5);
}


unsigned char B_IIC_Waitack(void)
{
    unsigned char IIC_Waitlimit=0;
    B_IIC_SDA_IN;
    B_IIC_SDA_1;
    Delay_us(1);
    B_IIC_SCL_1;
    Delay_us(1);
    while(B_IIC_READ_SDA)
    {
        IIC_Waitlimit++;
        if(IIC_Waitlimit>250)
        {
            B_IIC_Stop();
            return 1;
        }
    }
    B_IIC_SCL_0;
    return 0;
}



void B_IIC_Ack(void)
{
    B_IIC_SCL_0;
    B_IIC_SDA_OUT;
    B_IIC_SDA_0;

    Delay_us(2);
    B_IIC_SCL_1;
    Delay_us(5);
    B_IIC_SCL_0;
}


void B_IIC_Nack(void)
{
    B_IIC_SCL_0;
    B_IIC_SDA_OUT;
    B_IIC_SDA_1;

    Delay_us(2);
    B_IIC_SCL_1;
    Delay_us(2);
    B_IIC_SCL_0;
}



void B_IIC_Sendbyte(unsigned char IIC_Text)
{
    unsigned char IIC_Temp;
    B_IIC_SDA_OUT;
    B_IIC_SCL_0;

    for(IIC_Temp=0;IIC_Temp<8;IIC_Temp++)
    {
        if(IIC_Text&0x80)
            B_IIC_SDA_1;
        else
            B_IIC_SDA_0;
        IIC_Text<<=1;
        //Delay_us(2);
        B_IIC_SCL_1;
        Delay_us(2);
        B_IIC_SCL_0;
        Delay_us(2);
    }
}


unsigned char B_IIC_Readbyte(unsigned char IIC_ack)
{
    unsigned char IIC_Temp,IIC_Reseave=0;
    B_IIC_SDA_IN;
    for(IIC_Temp=0;IIC_Temp<8;IIC_Temp++)
    {
        B_IIC_SCL_0;
        Delay_us(2);
        B_IIC_SCL_1;
        IIC_Reseave<<=1;
        if(B_IIC_READ_SDA)
            IIC_Reseave++;
        Delay_us(1);
    }
    if(!IIC_ack)
        B_IIC_Nack();
    else
        B_IIC_Ack();
    return IIC_Reseave;
}








