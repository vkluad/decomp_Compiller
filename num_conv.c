//
// Created by tush17 on 5/8/21.
//
#include "num_conv.h"

int char_to_num_dec(char* char_num){
    int num = 0;
    short sign = 1;
    if(char_num[0]=='-'){
        sign = 0;
        char_num = char_num+1;
    }
    for(int i = 1; i<(int)strlen(char_num); i++){
        switch(char_num[i-1]){
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
    if(sign==0)
        return num-2*num;
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

double char_to_double(char* char_float){
    double num = 0;
    short sign = 1;
    if(char_float[0]=='-'){
        sign = 0;
        char_float = char_float+1;
    }
    char *integer = strtok(char_float,".\n\000");
    char *frac = strtok(NULL,".\n\000");
    for(int i = 1; i<(int)strlen(integer); i++){
        switch(integer[i-1]){
            case '0': num+=0; break;
            case '1': num+=1* (int)pow(10,(double)strlen(integer)-i);break;
            case '2': num+=2* (int)pow(10,(double)strlen(integer)-i);break;
            case '3': num+=3* (int)pow(10,(double)strlen(integer)-i);break;
            case '4': num+=4* (int)pow(10,(double)strlen(integer)-i);break;
            case '5': num+=5* (int)pow(10,(double)strlen(integer)-i);break;
            case '6': num+=6* (int)pow(10,(double)strlen(integer)-i);break;
            case '7': num+=7* (int)pow(10,(double)strlen(integer)-i);break;
            case '8': num+=8* (int)pow(10,(double)strlen(integer)-i);break;
            case '9': num+=9* (int)pow(10,(double)strlen(integer)-i);break;
            default:
                return 0;
        }
    }
    if(frac!=NULL){
        for(int i = -1; i>=-(int)strlen(frac); i--){
            switch(frac[-i-1]){
                case '0': num+=0; break;
                case '1': num+=1* (double)pow(10,i);break;
                case '2': num+=2* (double)pow(10,-i);break;
                case '3': num+=3* (double)pow(10,-i);break;
                case '4': num+=4* (double)pow(10,-i);break;
                case '5': num+=5* (double)pow(10,i);break;
                case '6': num+=6* (double)pow(10,-i);break;
                case '7': num+=7* (double)pow(10,-i);break;
                case '8': num+=8* (double)pow(10,-i);break;
                case '9': num+=9* (double)pow(10,-i);break;
                default:
                    return 0;
            }
        }
    }
    if(sign==0)
        return num-2*num;
    return num;
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
    double num_double = char_to_double(char_fix_p);
    int integer = (int)(num_double*0x10);
    char *number = (char*)calloc(17,sizeof(char));

    if(num_double<0){
        strcat(number,"11");
//        number[0] = '1';
//        number[1] = '1';
    }else{
        strcat(number,"00");
//        number[0] = '0';
//        number[1] = '0';
    }
    for(int i = 15;i>=2;i--){
        if(integer!=0) {
            if (integer % 2) {
                number[i] = '1';
                integer = integer >> 1;
            } else {
                number[i] = '0';
                integer = integer >> 1;
            }
        }else{
            number[i] = '0';
        }
    }
    return number;
}

char* move_p_to_bin(char *char_move_p) {
    double num_double = char_to_double(char_move_p);
    char *number = (char *) calloc(17, sizeof(char));
    char mantissa[8 + 1] = "";
    char order[4 + 1] = "";
    int i_order = 0;

    if (num_double < 0) {
        strcat(number,"11");
    } else {
        strcat(number,"00");
    }

    while (1) {
        if (fabs(num_double) > 1) {
            num_double /= 0x2;
            i_order += 1;
            continue;
        } else {
            if ((fabs(num_double)< 1) && (int) fabs((num_double * 2)) < 1) {
                num_double *= 0x2;
                i_order -= 1;
                continue;
            } else {
                break;
            }
        }
    }
    if(i_order>0){
        strcat(number,"00");
    }else{
        strcat(number,"11");
    }

    if((int)fabs((double)i_order)>15){
        return "!!!OVERFLOW!!!";
    }

    num_double*=0x100;
    int num = (int)num_double;

    for(int i = 7;i>=0;i--){
        if(num!=0) {
            if (num % 2) {
                mantissa[i] = '1';
                num = num >> 1;
            } else {
                mantissa[i] = '0';
                num = num >> 1;
            }
        }else{
            mantissa[i] = '0';
        }
    }

    for(int i = 3;i>=0;i--){
        if(i_order!=0) {
            if (i_order % 2) {
                order[i] = '1';
                i_order = i_order >> 1;
            } else {
                order[i] = '0';
                i_order = i_order >> 1;
            }
        }else{
            order[i] = '0';
        }
    }


    strcat(number,order);
    strcat(number,mantissa);
    return number;
}

char* integer_to_bin16(char *char_int){
    int num = char_to_num(char_int);
    char *number;
    number = (char*)calloc(17,sizeof(char));

    if(num<0){
        number[0] = '1';
        number[1] = '1';
        //    num-=2*num; //????????????????
    }else{
        number[0] = '0';
        number[1] = '0';
    }

    for(int i = 15;i>=2;i--){
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
        return move_p_to_bin(strtok(num,"m"));
    }
    if(strchr(num,'.')!=NULL){
        return fix_p_to_bin(num);
    }
    return integer_to_bin16(num);
}

char* num_to_bin12(char *s_adr){
    unsigned int num = char_to_num(s_adr);
    char *adr;
    adr = (char*)calloc(13,sizeof(char));
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
