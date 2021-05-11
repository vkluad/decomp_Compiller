//
// Created by tush17 on 5/6/21.
//

#include "pre_reader.h"


int pre_reader(const char* filename){
    char new_filename[32] = "";
    strcpy(new_filename, filename);
    strcat(new_filename,"_pre_comp");
    char line[STR] = "";
    char var[128][3][32];
    int line_count = 0;

    int var_count = 0;
    FILE *file_in = fopen(filename,"r");
    if(file_in == NULL){
        printf("You filename is incorrect\nprogram will be closed\n");
        fclose(file_in);
        return 1;
    }
    FILE *file_out = fopen(new_filename,"w");
    strcat(new_filename,"_u");
    FILE *file_out_u = fopen(new_filename,"w");
    while (feof(file_in) == 0) {
        if (fgets(line, STR, file_in) != NULL) {
            if (line[0] != '\n') {
                char *instr = strtok(line, ": \n\000");
                char *s_adr = strtok(NULL, ": \n\000");
                char *s_value = strtok(NULL, ": \n\000");
                if (instr[0] == '#') {
                    strcpy(var[var_count][0], instr);
                    strcpy(var[var_count][1], s_adr);
                    strcpy(var[var_count][2], s_value);
                    var_count++;
                } else {
                    if (s_adr != NULL) {
                        if (s_adr[0] == '#') {
                            for (int i = 0; i < 128; i++) {
                                if (strcmp(s_adr, var[i][0]) == 0) {
                                    strcpy(s_adr, var[i][1]);
                                }
                            }
                        }
                        fprintf(file_out, "%s %s\n", instr, s_adr);
                        fprintf(file_out_u, "%s %s\n", instr, s_adr);
                    } else {
                        fprintf(file_out, "%s\n", instr);
                        fprintf(file_out_u, "%s\n", instr);
                    }
                    line_count++;
                }
            }
        }
    }

    for(int i = 0; i < var_count;i++){
        for(int j = i+1;j < var_count;j++){
            if(char_to_num(var[i][1]) > char_to_num(var[j][1])){
                char temp1[32];
                strcpy(temp1,var[i][1]);
                char temp2[32];
                strcpy(temp2,var[i][2]);

                strcpy(var[i][1],var[j][1]);
                strcpy(var[i][2],var[j][2]);

                strcpy(var[j][1],temp1);
                strcpy(var[j][2],temp2);
            }
        }
    }

    for(int i = 0; i < var_count; i++){
        if(line_count <= char_to_num(var[i][1])){
            for(int j = line_count; j < char_to_num(var[i][1]); j++){
                fprintf(file_out,"LOAD 0\n");
                line_count++;
            }
            fprintf(file_out,"%s\n",var[i][2]);
            line_count++;
        }
    }


    fclose(file_in);
    fclose(file_out);
    fclose(file_out_u);
    return 0;
}
