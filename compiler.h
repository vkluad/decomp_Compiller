//
// Created by tush17 on 5/6/21.
//

#ifndef DECOMP_COMPILLER_COMPILER_H
#define DECOMP_COMPILLER_COMPILER_H

#include "header.h"
#include "num_conv.h"

//char *num_to_bin(const char* num);

void load_to_decomp(const char *filename);

void load_to_file(const char *filename,char* new_line);

char *find_command(char *instr);



void compiler(const char * filename);



#endif //DECOMP_COMPILLER_COMPILER_H
