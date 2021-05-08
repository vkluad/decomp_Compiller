//
// Created by tush17 on 5/8/21.
//

#ifndef DCC_NUM_CONV_H
#define DCC_NUM_CONV_H

#include "header.h"
#include <math.h>

int char_to_num_dec(char* char_num);

int char_to_num_hex(char* char_num);

int char_to_num(char* char_num);

char* fix_p_to_bin(char *char_fix_p);

char* move_p_to_bin(char *char_move_p);

char* integer_to_bin16(char *char_int_dec);

char* num_to_bin16(char *num);

char* num_to_bin12(char *num);

char* bin_create(int num);

#endif //DCC_NUM_CONV_H
