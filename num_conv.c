//
// Created by tush17 on 5/8/21.
//
#include "num_conv.h"

unsigned int char_to_num_dec(char* char_num){
    unsigned int num = 0;
    for(int i = 1; i<(int)strlen(char_num); i++){
        switch(char_num[i-1]){
            case '0': num+=0; break;
            case '1': num+=1* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '2': num+=2* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '3': num+=3* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '4': num+=4* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '5': num+=5* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '6': num+=6* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '7': num+=7* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '8': num+=8* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            case '9': num+=9* (unsigned int)pow(10,(double)strlen(char_num)-i);break;
            default:
                return 0;
        }
    }
    return num;
}

unsigned int char_to_num_hex(char* char_num){
    unsigned int num = 0;
    int start;
    for(int i = 0; i<(int)strlen(char_num)-2; i++){
        start = i + 3;
        switch(char_num[i+2]){
            case '0': num+=0; break;
            case '1': num+=1* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '2': num+=2* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '3': num+=3* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '4': num+=4* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '5': num+=5* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '6': num+=6* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '7': num+=7* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '8': num+=8* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case '9': num+=9* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case 'A': num+=10* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case 'B': num+=11* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case 'C': num+=12* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case 'D': num+=13* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case 'E': num+=14* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            case 'F': num+=15* (unsigned int)pow(16,(double)strlen(char_num)-start);break;
            default:
                return 0;
        }
    }
    return num;
}

unsigned int char_to_num(char* char_num){
    if(char_num[1]=='x'){
        return char_to_num_hex(char_num);
    }else{
        return char_to_num_dec(char_num);
    }
}

char* num_to_bin16(unsigned int num){
    char *adr;
    adr = (char*)malloc(sizeof(char)*16);
    for(int i = 15;i>=0;i--){
        if(num!=0) {
            if (num % 2) {
                adr[i] = '1';
                num = num >> 1;
            } else {
                adr[i] = '0';
                num = num >> 1;
            }
        }else{
            adr[i] = '0';
        }
    }
    return adr;
}
