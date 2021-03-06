/*
 * double2str.c
 *
 *  Created on: 2020��7��31��
 *      Author: Ech0Potato
 */



#include "double2str.h"


double abs1(double a ){
    if( a>=0 ){
        return a;
    }else{
        return (- a);
    }
}

void float2str(double f,char * str,int n){
    f = abs1(f);
    int f_temp = (int) f;
    int cnt = 0;
    while(f_temp){
        f_temp /= 10;
        cnt ++;
    }
    int i;
    for(i=0; i<n-cnt; i++){
        f *= 10.0;
    }
    int f_int = (int) f;
    for(i=n; i>=cnt+1; i--){
        str[i] = f_int % 10 +'0';
        f_int /= 10;
    }

    str[cnt] = '.';
    for(i=cnt-1; i>=0; i--){
        str[i] = f_int % 10 +'0';
        f_int /= 10;
    }
    str[n+1] = '\0';
}

void  int2str(int num,char * str){
    if(num >=0 ){
    int num_temp = num;
    int cnt = 0;
    while(num_temp){
        num_temp /= 10;
        cnt ++;
    }
    if(cnt == 0){
        str[0] = '0';
        str[1] = '\0';
    }else{

    int i;
    for(i = cnt-1; i>=0; i--){
        str[i] = num % 10 + '0';
        num /= 10;
    }
    str[cnt] = '\0';
    }
    }
    else{
        num = -num;
        int num_temp = num;
            int cnt = 0;
            while(num_temp){
                num_temp /= 10;
                cnt ++;
            }

            int i;
            for(i = cnt; i>=1; i--){
                str[i] = num % 10 + '0';
                num /= 10;
            }
            str[cnt+1] = '\0';
            str[0] = '-';


    }
}


