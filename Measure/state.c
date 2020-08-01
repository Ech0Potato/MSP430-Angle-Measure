/*
 * state.c
 *
 *  Created on: 2020��8��1��
 *      Author: Ech0Potato
 */
#include<string.h>
#include<msp430.h>
#include<state.h>
#include<measure.h>
#include<uart_self.h>
#include<beep.h>

const char OUTER_READY[6] = {0xE5,0x01,0x00,0x01,0xE6};
const char OUTER_READY_2[7] = {0xE5,0x06,0x01,0x04,0x0A,0xE6};
const char ONLY_A[7] = {0xE5,0x49,0x01,0x01,0x4B,0xE6};
const char TOTAL_A_B[7] = {0xE5,0x49,0x01,0x02,0x4C,0xE6};
const char MISSION_BACK[6] = {0xE5,0x4B,0x00,0x4B,0xE6};
const char MISSION_NEXT[8] = {0xE5,0x4C,0x02,0x01,0x00,0x4F,0xE6};
const char MISSION_END[6] = {0xE5,0x4D,0x00,0x4D,0xE6};
const char STEP_END[7]= {0xE5,0x4A,0x01,0x01,0x4C,0xE6};



char state ;
const char PLATFORM_UNREADY = 0;
const char PLATFORM_READY = 1;

//void StateMeachine(void){
//    switch state:
//
//    case PLATFORM_UNREADY :
//        break;
//
//    case PLATFORM_READY :
//
//
//}

char buffer[40];
const int END = 1;
const int NOT_END = 0;
int buffer_index = 0;

void Buffer_Init(void){
    buffer_index = 0;
}




void Command_Handler(char * command){
    if(strcmp(command,OUTER_READY) == 0){
         putstr("OUTER_READY\r\n");
    }else if(strcmp(command,OUTER_READY_2) == 0){
         putstr("OUTER_READY_2\r\n");
    }else if(strcmp(command,ONLY_A) == 0){
         putstr("ONLY_A\r\n");
    }else if(strcmp(command,TOTAL_A_B) == 0){
         putstr("TOTAL_A_B\r\n");
    }else if(strcmp(command,MISSION_BACK) == 0){
         putstr("MISSION_BACK\r\n");
         long_beep();
    }else if(strcmp(command,MISSION_NEXT) == 0){
         putstr("MISSION_NEXT\r\n");
    }else if(strcmp(command,MISSION_END) == 0){
         putstr("MISSION_END\r\n");
    }else if(strcmp(command,STEP_END) == 0){
         putstr("STEP_END\r\n");
         short_beep();
    }
    else{
        putstr("FUCK U!\r\n");
    }
}


#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void){
    while (!(IFG2&UCA0TXIFG));
    char RX_DATA=UCA0RXBUF;
    buffer[buffer_index] = RX_DATA;
    if(buffer_index == 40){
        putstr("BUFFER FULL! \r\n");
        memset(buffer,'\0',40);
        buffer_index= 0;
    }
    if(RX_DATA == 0xE6){
        buffer_index = 0;
        Command_Handler(buffer);
        memset(buffer,'\0',40);
    }else{
        buffer_index ++ ;
    }
}
