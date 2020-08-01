/*
 * communicate.c
 *
 *  Created on: 2020��7��31��
 *      Author: Ech0Potato
 */


#include<communicate.h>
#include<string.h>
#include<measure.h>
#include<communicate.h>

extern DroneRTInfo RT_Info;
char FeatureCode[10] = "XD1010001";
const char START_CODE[2] = {0xE5};
const char END_CODE[2] = {0xE6};
char Command_Help[2] = {0x00};
char FCS_Help[2] = {0x00};
char LEN_Help[2] = {0x00};


void Add_StartCode(char * str){
    strcat(str,START_CODE);
}

void Add_EndCode(char * str){
    strcat(str,END_CODE);
}

void Add_CommandCode(char *str,char CommandCode){
    Command_Help[0] = CommandCode;
    strcat(str,Command_Help);
}
void Add_FCS(char * str){
    int length = strlen(str);
    int sum = 0;
    int i=0;
    for(i = 1 ; i<length; i++){
        sum += str[i];
    }
     // With Origin , FCS and EndCode
    sum %= 256;
    FCS_Help[0] = (char) sum;
    strcat(str,FCS_Help);
}

void Add_LengthAndData(char * str,char * data){
    int length = strlen(data);
    LEN_Help[0] = (char) length;
    strcat(str,LEN_Help);
    strcat(str,data);
}

void Send_FeatureCode(void){
    char str[60];
    memset(str,'\0',60);

    Add_StartCode(str);
    Add_CommandCode(str,0x05);
    Add_LengthAndData(str,FeatureCode);
    Add_FCS(str);
    Add_EndCode(str);
    putstr(str);
}


void Send_Angle_A(void){
    char str[40];
    memset(str,'\0',40);

    Add_StartCode(str);
    Add_CommandCode(str,0x41);
    make_angle();
    putstr("This is Angle_A \r\n");
    //
}

void Send_Angle_B(void){
    char str[40];
    memset(str,'\0',40);

    Add_StartCode(str);
    Add_CommandCode(str,0x42);
    make_angle();
    putstr("This is Angle_B \r\n");

    //
}


