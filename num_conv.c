//
// Created by tush17 on 5/8/21.
//
#include "num_conv.h"

int char_to_num_dec(char* char_num){
    int num = 0;
    short sign = 1;
//    if(char_num[0]=='-'){
//        sign = 0;
//    }
    for(int i = 1; i<(int)strlen(char_num); i++){
        switch(char_num[i-sign]){
            case '0': num+=0; break;
            case '1': num+=1* (int)pow(10,(double)strlen(char_num)-i);break;
            case '2': num+=2* (int)pow(10,(double)strlen(char_num)-i);break;
            case '3': num+=3* (int)pow(10,(double)strlen(char_num)-i);break;
            case '4': num+=4* (int)pow(10,(double)strlen(char_num)-i);break;
            case '5': num+=5* (int)pow(10,(double)strlen(char_num)-i);break;
            case '6': num+=6* (int)pow(10,(double)strlen(char_num)-i);break;
            case '7': num+=7* (int)pow(10,(double)strlen(char_num)-i);break;
            case '8': num+=8* (int)pow(10,(double)strlen(char_num)-i);break;
            case '9': num+=9* (int)pow(10,(double)strlen(char_num)-i);break;
            default:
                return 0;
        }
    }
//    if(char_num[0]=='-')
//        return num-2*num;
    return num;
}

int char_to_num_hex(char* char_num){
    int num = 0;
    int start;
    for(int i = 0; i<(int)strlen(char_num)-2; i++){
        start = i + 3;
        switch(char_num[i+2]){
            case '0': num+=0; break;
            case '1': num+=1* (int)pow(16,(double)strlen(char_num)-start);break;
            case '2': num+=2* (int)pow(16,(double)strlen(char_num)-start);break;
            case '3': num+=3* (int)pow(16,(double)strlen(char_num)-start);break;
            case '4': num+=4* (int)pow(16,(double)strlen(char_num)-start);break;
            case '5': num+=5* (int)pow(16,(double)strlen(char_num)-start);break;
            case '6': num+=6* (int)pow(16,(double)strlen(char_num)-start);break;
            case '7': num+=7* (int)pow(16,(double)strlen(char_num)-start);break;
            case '8': num+=8* (int)pow(16,(double)strlen(char_num)-start);break;
            case '9': num+=9* (int)pow(16,(double)strlen(char_num)-start);break;
            case 'A': num+=10* (int)pow(16,(double)strlen(char_num)-start);break;
            case 'B': num+=11* (int)pow(16,(double)strlen(char_num)-start);break;
            case 'C': num+=12* (int)pow(16,(double)strlen(char_num)-start);break;
            case 'D': num+=13* (int)pow(16,(double)strlen(char_num)-start);break;
            case 'E': num+=14* (int)pow(16,(double)strlen(char_num)-start);break;
            case 'F': num+=15* (int)pow(16,(double)strlen(char_num)-start);break;
            default:
                return 0;
        }
    }
    return num;
}

int char_to_num(char* char_num){
    if(char_num[1]=='x'){
        return char_to_num_hex(char_num);
    }else{
        return char_to_num_dec(char_num);
    }
}

char* bin_create(int num) {
    char *adr;
    adr = (char*)calloc(15,sizeof(char));
    for(int i = 14;i>=0;i--){
        if(i%5==0){
            adr[i] = ' ';
        }else {
            if (num != 0) {
                if (num % 2) {
                    adr[i] = '1';
                    num = num >> 1;
                } else {
                    adr[i] = '0';
                    num = num >> 1;
                }
            } else {
                adr[i] = '0';
            }
        }
    }
    return adr;
}

char* fix_p_to_bin(char *char_fix_p){

}

char* move_p_to_bin(char *char_move_p){

}

char* integer_to_bin16(char *char_int){
    int num = char_to_num(char_int);
    char *number;
    number = (char*)malloc(sizeof(char) * 17);
    for(int i = 15;i>=0;i--){
        if(num!=0) {
            if (num % 2) {
                number[i] = '1';
                num = num >> 1;
            } else {
                number[i] = '0';
                num = num >> 1;
            }
        }else{
            number[i] = '0';
        }
    }
    return number;
}

char* num_to_bin16(char *num){
    if(num[strlen(num)-1]=='m'){
        return move_p_to_bin(num);
    }
    if(strchr(num,',')!=NULL){
        return fix_p_to_bin(num);
    }
    return integer_to_bin16(num);
}

char* num_to_bin12(char *s_adr){
    unsigned int num = char_to_num(s_adr);
    char *adr;
    adr = (char*)malloc(sizeof(char)*13);
    for(int i = 11;i>=0;i--){
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