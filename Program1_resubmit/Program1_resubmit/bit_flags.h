/************************************
Author:Wen Liang
Date:10/18/2017
Effort: 4h
Purpose:Be familiar with struct operation, bitwise operation,
and relocate memory space when capacity is not enough.

Interface proposal: I think we might be missing the bit_flags_display
function, which could be used to display bits. This function could be used to display the return value from bit_flags_check_flag function.

By the way, I Comment out the main funtion, which could be used to test my code if anything wrong with my code. Thank you!

***********************************/



#ifndef BIT_FLAGS_H
#define BIT_FLAGS_H
#include "status.h"


typedef void* BIT_FLAGS;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits);

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position);

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);

int bit_flags_get_size(BIT_FLAGS hBit_flags);

int bit_flags_get_capacity(BIT_FLAGS hBit_flags);

void bit_flags_destroy(BIT_FLAGS* phBit_flags);


#endif 
