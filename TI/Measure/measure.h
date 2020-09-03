/*
 * measure.h
 *
 *  Created on: 2019Äê5ÔÂ28ÈÕ
 *      Author: ximikang
 */
#ifndef MEASURE_H_
#define MEASURE_H_
#include "math.h"
#include "IIC.h"
#include "adxl345.h"
#include "beep.h"

typedef struct
{
    float Pitch;
    float Roll;
    float Yaw;

    float B_Pitch;
    float B_Roll;
    float B_Yaw;
}DroneRTInfo;

void make_angle(void);
extern DroneRTInfo RT_Info;
#endif /* MEASURE_H_ */
