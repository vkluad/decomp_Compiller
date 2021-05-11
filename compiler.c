//
// Created by tush17 on 5/6/21.
//
#include "compiler.h"

void load_to_decomp(const char *filename){
    char temp[FILENAME_SIZE] = "";
    char new_filename[FILENAME_SIZE] = "";
    strcpy(temp, filename);
    strcpy(new_filename, strtok(temp,"."));
    strcat(new_filename,".comp");
    char line[STR_DE] = "";
    int i = 0;
    FILE *decomp_prg = fopen("DeComp.prg","w");
    FILE *file_in = fopen(new_filename,"r");
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
    char new_filename[FILENAME_SIZE] = "";
    strcpy(temp, filename);
    strcpy(new_filename, strtok(temp,".\000\n"));
    strcat(new_filename,".comp");
    static _Bool delete_file = 0;
    FILE *file_comp = NULL;
    if(delete_file==0){
        file_comp = fopen(new_filename,"w");
        delete_file = 1;
    }else {
        file_comp = fopen(new_filename, "a+");
    }
    for(int i = 0;i<strlen(new_line);i++) {
        if((i%4==0)&&(i!=0)) {
            fputc(' ',file_comp);
            fputc(new_line[i], file_comp);
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
    char *command_b;
    command_b = (char*)calloc(STR_DE,sizeof(char));
    if(file_decode!=NULL) {
        while (feof(file_decode) == 0) {
            fgets(line, STR_DE, file_decode);
            if (memcmp(instr, line, strlen(instr)) == 0) {
                strtok(line, ":\n");
                strcpy(command_b,strtok(NULL, ":\n"));
                return command_b;
            }
        }
    }else{
        printf("Program file decomp.lib is not available");
    }
    return "";
}


void compiler(const char * filename){
    FILE *file_in = fopen(filename,"r");
    char line[STR] = "";
    char new_line[STR_DE] = "";
    while(feof(file_in)==0) {
        strncpy(line,"\000",120);
        strncpy(new_line,"\000",30);
        if(fgets(line, STR, file_in)!=NULL) {
            if(line[0]!='\n') {
                char *instr = strtok(line, " \n\000");
                char *s_adr = strtok(NULL, " \n\000");
                strcpy(new_line, find_command(instr));
                if ((strlen(new_line) < 16) && (s_adr != NULL) && strcmp(new_line,"")!=0) {
                    printf("%s ", instr);
                    printf("%s\n", s_adr);
                    strcat(new_line, num_to_bin12(s_adr));
                } else {
//                    printf("")
                    printf("%s\n", instr);
                    if(strcmp(new_line,"")==0) {
                        strcpy(new_line, num_to_bin16(instr));
                    }
                }
                printf("%s\n\n", new_line);
                load_to_file(filename, new_line);
            }
        }
    }
    fclose(file_in);
}
