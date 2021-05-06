//
// Created by tush17 on 5/6/21.
//

#ifndef DECOMP_COMPILLER_COMPILER_H
#define DECOMP_COMPILLER_COMPILER_H

#include "header.h"
void load_to_file(const char *filename,char* new_line);

char * find_command(char *instr);

char *num_to_bin(const char* num);

void compiler(const char * filename);



#endif //DECOMP_COMPILLER_COMPILER_H
