//
// Created by tush17 on 5/6/21.
//
#include "compiler.h"

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

void load_to_decomp(const char *filename){
    char temp[FILENAME_SIZE] = "";
    strcpy(temp, filename);
    strcpy(temp, strtok(temp,"."));
    strcat(temp,".comp");
    char line[STR_DE];
    int i = 0;
    FILE *decomp_prg = fopen("DeComp.prg","w");
    FILE *file_in = fopen(temp,"r");
    if(file_in!=NULL){
        while(fgets(line,STR_DE,file_in)!=NULL){
            fprintf(decomp_prg,"%s  %s", bin_create(i),line);
            i++;
        }
    }
    fclose(file_in);
    fclose(decomp_prg);
}

void load_to_file(const char *filename,char* new_line){
    char temp[FILENAME_SIZE] = "";
    strcpy(temp, filename);
    strcpy(temp, strtok(temp,"."));
    strcat(temp,".comp");
    static _Bool delete_file = 0;
    FILE *file_comp;
    if(delete_file==0){
        file_comp = fopen(temp,"w");
        delete_file = 1;
    }else {
        file_comp = fopen(temp, "a+");
    }
    for(int i = 0;i<strlen(new_line);i++) {
        if((i+1)%4==0) {
            fputc(new_line[i], file_comp);
            fputc(' ',file_comp);
        }else{
            fputc(new_line[i], file_comp);
        }
    }
    fputc('\n',file_comp);
    fclose(file_comp);
}

char * find_command(char *instr){
    FILE *file_decode = fopen("./data/decomp.lib","r");
    char line[STR_DE] = "";
    while(feof(file_decode)==0) {
        fgets(line, STR_DE, file_decode);
        if (memcmp(instr, line, strlen(instr)) == 0) {
            strtok(line,":\n");
            return strtok(NULL,":\n");
        }
    }
    return "";
}

char *num_to_bin(const char* num){
    FILE *file_decode = fopen("./data/decomp.num_lib","r");
    char line[STR_DE] = "";
    while(feof(file_decode)==0) {
        fgets(line, STR_DE, file_decode);
        char *temp1 = strtok(line,":\n");
        char *temp2 = strtok(NULL,":\n");
        if((temp1!=NULL)&&(temp2!=NULL)) {
            if ((strcmp(num, temp1) == 0) || (strcmp(num, temp2) == 0)) {
                return strtok(NULL, ":\n");
            }
        }
    }
    return "";
}

void compiler(const char * filename){
    FILE *file_in = fopen(filename,"r");
    char line[STR] = "";
    char new_line[17] = "";
    while(feof(file_in)==0) {
        if(fgets(line, STR, file_in)!=NULL) {
            if(line[0]!='\n') {
                char *instr = strtok(line, " \n\000");
                char *s_adr = strtok(NULL, " \n\000");
                strcpy(new_line, find_command(instr));
                if ((strlen(new_line) != 16) && (s_adr != NULL)) {
                    printf("%s ", instr);
                    printf("%s\n", s_adr);
                    strcat(new_line, num_to_bin(s_adr));
                } else {
                    printf("%s\n", instr);
                }
                printf("%s\n\n", new_line);
                load_to_file(filename, new_line);
            }
        }
    }
    fclose(file_in);
}

