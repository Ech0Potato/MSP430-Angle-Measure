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
#include<stdint.h>


extern DroneRTInfo RT_Info;
char FeatureCode[10] = "XD1040036";
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

void Add_LengthAndData_Angle(char *  str,char *data, int num){
    LEN_Help[0] = (char) num;
    strcat(str,LEN_Help);
    int cur_len = strlen(str);
    while(cur_len --){
         str ++ ;
    }
    int i ;
    for(i=0; i<num; i++,data++,str++){
        *str = *data;
    }
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

    int16_t Pitch,Roll,Yaw;
    Pitch = (int16_t) RT_Info.Pitch;
    Roll  = (int16_t) RT_Info.Roll;
    Yaw   = (int16_t) RT_Info.Yaw;

    char  TempData[7];
    memset(TempData,'\0',7);

    if(Yaw < 0){
        TempData[0] = 0xFF;}
    else{
        TempData[0] = 0x00;
    }
    TempData[1] = Yaw & 0xFF;

    if(Pitch <0 ){
    TempData[2] = 0xFF;
    }else{
        TempData[2] = 0x00;
    }
    TempData[3] = Pitch & 0xFF;

    if(Roll <0){
        TempData[4] = 0xFF;
    }else{
        TempData[4] = 0x00;
    }

    TempData[5] = Roll & 0xFF;

    Add_LengthAndData_Angle(str,TempData,6);

    int i,sum;
    for(i=1,sum=0; i<9;i++){
        sum += str[i];
    }
    sum %= 256;
    str[i++] = sum;

    str[i] = 0xE6;

    for(i=0; i<11; i++){
        putchar(str[i]);
    }

    //
}


void Send_Angle_B(void){
    char str[40];
    memset(str,'\0',40);

    Add_StartCode(str);
    Add_CommandCode(str,0x42);
    make_angle();

    int16_t Pitch,Roll,Yaw;
    Pitch = (int16_t) RT_Info.B_Pitch;
    Roll  = (int16_t) RT_Info.B_Roll;
    Yaw  = (int16_t) RT_Info.B_Yaw;

    char  TempData[7];
    memset(TempData,'\0',7);


    if(Yaw < 0){
        TempData[0] = 0xFF;}
    else{
        TempData[0] = 0x00;
    }
    TempData[1] = Yaw & 0xFF;

    if(Pitch <0 ){
    TempData[2] = 0xFF;
    }else{
        TempData[2] = 0x00;
    }
    TempData[3] = Pitch & 0xFF;

    if(Roll <0){
        TempData[4] = 0xFF;
    }else{
        TempData[4] = 0x00;
    }

    TempData[5] = Roll & 0xFF;

    Add_LengthAndData_Angle(str,TempData,6);

    int i,sum;
    for(i=1,sum=0; i<9;i++){
        sum += str[i];
    }
    sum %= 256;
    str[i++] = sum;

    str[i] = 0xE6;

    for(i=0; i<11; i++){
        putchar(str[i]);
    }

    //
}













//
//void Send_Angle_B(void){
//    char str[40];
//    memset(str,'\0',40);
//
//    Add_StartCode(str);
//    Add_CommandCode(str,0x42);
//    make_angle();
//    putstr("This is Angle_B \r\n");
//
//    //
//}


