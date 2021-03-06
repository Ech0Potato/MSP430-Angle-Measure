#include<msp430.h>
#include "IIC.h"
#include "adxl345.h"

/*单字节写入*/
void Single_Write_ADXL345(unsigned char REG_Address,unsigned char REG_data)
{

   IIC_Start();
   IIC_Sendbyte(SlaveAddress);
   IIC_Waitack();
   IIC_Sendbyte(REG_Address);
   IIC_Waitack();
   IIC_Sendbyte(REG_data);
   IIC_Waitack();
   IIC_Stop();
}


/*单字节读取*/
unsigned char Single_Read_ADXL345(unsigned char REG_Address)
{
   unsigned char REG_data=0;
   IIC_Start();
   IIC_Sendbyte(SlaveAddress);
   REG_data=IIC_Waitack();
   IIC_Sendbyte(REG_Address);
   REG_data=IIC_Waitack();
   IIC_Start();
   IIC_Sendbyte(SlaveAddress + 1);
   REG_data=IIC_Waitack();
   REG_data = IIC_Readbyte(0);
   IIC_Stop();
   return REG_data;
}




/*连续读取ADXL345内部加速度数据*/
void Multiple_read_ADXL345(int *x,int *y,int*z)
{
    //unsigned char k;
    char BUF[6];
    IIC_Start();
    IIC_Sendbyte(SlaveAddress);
    IIC_Waitack();
    IIC_Sendbyte(0x32);
    IIC_Waitack();

    IIC_Start();
    IIC_Sendbyte(SlaveAddress + 1);
    IIC_Waitack();

    BUF[0]=IIC_Readbyte(1);
    BUF[1]=IIC_Readbyte(1);
    BUF[2]=IIC_Readbyte(1);
    BUF[3]=IIC_Readbyte(1);
    BUF[4]=IIC_Readbyte(1);
    BUF[5]=IIC_Readbyte(0);


    IIC_Stop();
    *x=(BUF[1]<<8)+BUF[0];
    *y=(BUF[3]<<8)+BUF[2];
    *z=(BUF[5]<<8)+BUF[4];
}
/******************************************/
void B_Single_Write_ADXL345(unsigned char REG_Address,unsigned char REG_data)
{

   B_IIC_Start();
   B_IIC_Sendbyte(SlaveAddress);
   B_IIC_Waitack();
   B_IIC_Sendbyte(REG_Address);
   B_IIC_Waitack();
   B_IIC_Sendbyte(REG_data);
   B_IIC_Waitack();
   B_IIC_Stop();
}


/*单字节读取*/
unsigned char B_Single_Read_ADXL345(unsigned char REG_Address)
{
   unsigned char REG_data=0;
   B_IIC_Start();
   B_IIC_Sendbyte(SlaveAddress);
   REG_data=B_IIC_Waitack();
   B_IIC_Sendbyte(REG_Address);
   REG_data=B_IIC_Waitack();
   B_IIC_Start();
   B_IIC_Sendbyte(SlaveAddress + 1);
   REG_data=B_IIC_Waitack();
   REG_data = B_IIC_Readbyte(0);
   B_IIC_Stop();
   return REG_data;
}




/*连续读取ADXL345内部加速度数据*/
void B_Multiple_read_ADXL345(int *x,int *y,int*z)
{
    //unsigned char k;
    char BUF[6];
    B_IIC_Start();
    B_IIC_Sendbyte(SlaveAddress);
    B_IIC_Waitack();
    B_IIC_Sendbyte(0x32);
    B_IIC_Waitack();

    B_IIC_Start();
    B_IIC_Sendbyte(SlaveAddress + 1);
    B_IIC_Waitack();

    BUF[0]=B_IIC_Readbyte(1);
    BUF[1]=B_IIC_Readbyte(1);
    BUF[2]=B_IIC_Readbyte(1);
    BUF[3]=B_IIC_Readbyte(1);
    BUF[4]=B_IIC_Readbyte(1);
    BUF[5]=B_IIC_Readbyte(0);


    B_IIC_Stop();
    *x=(BUF[1]<<8)+BUF[0];
    *y=(BUF[3]<<8)+BUF[2];
    *z=(BUF[5]<<8)+BUF[4];
}



void Init_ADXL345()
{

    Single_Write_ADXL345(0x31,0x0B);  //测量范围   正负16g
    Single_Write_ADXL345(0x2C,0x04);  //速率设定
    Single_Write_ADXL345(0x2D,0x08);  //选择电源模式
    Single_Write_ADXL345(0x2E,0x80);  //使能DATA_READY 中断
    Single_Write_ADXL345(0x1E,0xFC);  //X偏移量
    Single_Write_ADXL345(0x1F,0x02);  //Y偏移量
    Single_Write_ADXL345(0x20,0x04);  //Z偏移量

    B_Single_Write_ADXL345(0x31,0x0B);  //测量范围   正负16g
    B_Single_Write_ADXL345(0x2C,0x04);  //速率设定
    B_Single_Write_ADXL345(0x2D,0x08);  //选择电源模式
    B_Single_Write_ADXL345(0x2E,0x80);  //使能DATA_READY 中断
    B_Single_Write_ADXL345(0x1E,0xFC);  //X偏移量
    B_Single_Write_ADXL345(0x1F,0x02);  //Y偏移量
    B_Single_Write_ADXL345(0x20,0x04);  //Z偏移量

}


