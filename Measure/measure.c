/*
 * measure.c
 *
 *  Created on: 2019年5月28日
 *      Author: ximikang
 */
#include "measure.h"
#define PI 3.1415
DroneRTInfo RT_Info;

int get_mean(int *int_vector)
{
    int sum =0 , i = 0;
    for(i = 0; i < 5; ++i)
    {
        sum+= int_vector[i];
    }
    return (int)(sum / 5);
}

void get_raw_value(int *Raw_Value)
{
    int i;
    int raw_x[5];//取平均值
    int raw_y[5];
    int raw_z[5];
    for(i = 0; i < 5; ++i)//取平均值
    {
        Multiple_read_ADXL345(&raw_x[i],&raw_y[i],&raw_z[i]);
        Delay_ms(5);
    }
    Raw_Value[0] = get_mean(raw_x);
    Raw_Value[1] = get_mean(raw_y);
    Raw_Value[2] = get_mean(raw_z);
}

void B_get_raw_value(int *Raw_Value)
{
    int i;
    int raw_x[5];//取平均值
    int raw_y[5];
    int raw_z[5];
    for(i = 0; i < 5; ++i)//取平均值
    {
        B_Multiple_read_ADXL345(&raw_x[i],&raw_y[i],&raw_z[i]);
        Delay_ms(5);
    }
    Raw_Value[0] = get_mean(raw_x);
    Raw_Value[1] = get_mean(raw_y);
    Raw_Value[2] = get_mean(raw_z);
}


//获取值  为带符号的float
void make_g_float(float *data,int *raw_data)
{
    int index;
    for (index = 0; index < 3;++index)
    {
        data[index] = (float)((raw_data[index]*9.8)/256);
    }
}


void make_angle(void)
{
    int Raw_Value[3];
    float g_data[3];

    int B_Raw_Value[3];
    float B_g_data[3];

    get_raw_value(Raw_Value);
    make_g_float(g_data,Raw_Value);

    get_raw_value(B_Raw_Value);
    make_g_float(B_g_data,B_Raw_Value);



    RT_Info.Yaw   = ((atan(sqrt( g_data[0]*g_data[0] + g_data[1]*g_data[1] ) / g_data[2])) /PI) * 180;
    RT_Info.Pitch = ((atan(g_data[0]/sqrt( g_data[1]*g_data[1] + g_data[2]*g_data[2]))) /PI) * 180;
    RT_Info.Roll  = ((atan(g_data[1]/sqrt( g_data[0]*g_data[0] + g_data[2]*g_data[2]))) /PI) * 180;

    RT_Info.B_Yaw   = ((atan(sqrt( B_g_data[0]*B_g_data[0] + B_g_data[1]*B_g_data[1] ) / B_g_data[2])) /PI) * 180;
    RT_Info.B_Pitch = ((atan(B_g_data[0]/sqrt( B_g_data[1]*B_g_data[1] + B_g_data[2]*B_g_data[2]))) /PI) * 180;
    RT_Info.B_Roll  = ((atan(B_g_data[1]/sqrt( B_g_data[0]*B_g_data[0] + B_g_data[2]*B_g_data[2]))) /PI) * 180;
}









