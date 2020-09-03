#include<msp430.h>
#include "IIC.h"
#include "adxl345.h"

/*���ֽ�д��*/
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


/*���ֽڶ�ȡ*/
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




/*������ȡADXL345�ڲ����ٶ�����*/
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


/*���ֽڶ�ȡ*/
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




/*������ȡADXL345�ڲ����ٶ�����*/
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

    Single_Write_ADXL345(0x31,0x0B);  //������Χ   ����16g
    Single_Write_ADXL345(0x2C,0x04);  //�����趨
    Single_Write_ADXL345(0x2D,0x08);  //ѡ���Դģʽ
    Single_Write_ADXL345(0x2E,0x80);  //ʹ��DATA_READY �ж�
    Single_Write_ADXL345(0x1E,0xFC);  //Xƫ����
    Single_Write_ADXL345(0x1F,0x02);  //Yƫ����
    Single_Write_ADXL345(0x20,0x04);  //Zƫ����

    B_Single_Write_ADXL345(0x31,0x0B);  //������Χ   ����16g
    B_Single_Write_ADXL345(0x2C,0x04);  //�����趨
    B_Single_Write_ADXL345(0x2D,0x08);  //ѡ���Դģʽ
    B_Single_Write_ADXL345(0x2E,0x80);  //ʹ��DATA_READY �ж�
    B_Single_Write_ADXL345(0x1E,0xFC);  //Xƫ����
    B_Single_Write_ADXL345(0x1F,0x02);  //Yƫ����
    B_Single_Write_ADXL345(0x20,0x04);  //Zƫ����

}

