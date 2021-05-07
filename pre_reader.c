//
// Created by tush17 on 5/6/21.
//

#include "pre_reader.h"

int pre_reader(const char* filename){
    char new_filename[32] = "";
    strcpy(new_filename, filename);
    strcat(new_filename,"_pre_comp");
    char line[STR] = "";
    char var[128][2][64];
    int var_count = 0;
    FILE *file_in = fopen(filename,"r");
    if(file_in == NULL){
        printf("You filename is incorrect\nprogram will be closed\n");
        fclose(file_in);
        return 1;
    }
    FILE *file_out = fopen(new_filename,"w");
    while (feof(file_in) == 0) {
        if (fgets(line, STR, file_in) != NULL) {
            if (line[0] != '\n') {
                char *instr = strtok(line, " \n\000");
                char *s_adr = strtok(NULL, " \n\000");
                if (instr[0] == '#') {
                    strcpy(var[var_count][0], instr);
                    strcpy(var[var_count][1], s_adr);
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
                    } else {
                        fprintf(file_out, "%s\n", instr);
                    }
                }
            }
        }
    }
    fclose(file_in);
    fclose(file_out);
    return 0;
}
// default