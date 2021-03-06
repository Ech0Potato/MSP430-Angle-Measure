/*
 * communicate.h
 *
 *  Created on: 2020��7��31��
 *      Author: Ech0Potato
 */

#ifndef COMMUNICATE_H_
#define COMMUNICATE_H_

#include<msp430.h>
#include<uart_self.h>


void Add_StartCode(char * str);
void Add_EndCode(char * str);
void Add_FCS(char * str);
void Add_LengthAndData(char * str,char * data);
void Add_CommandCode(char *str,char CommandCode);
void Send_FeatureCode(void);
void Send_Angle_A(void);
void Send_Angle_B(void);
void Add_LengthAndData_Angle(char *str,char *data, int num);

#endif /* COMMUNICATE_H_ */
