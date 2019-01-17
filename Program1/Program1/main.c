#include <stdio.h>
#include "bit_flags.h"



int main(int agrc, char* argv[])
{
	BIT_FLAGS hBit_flags = NULL;
	hBit_flags = bit_flags_init_number_of_bits(32);
	bit_flags_set_flag(hBit_flags, 78);
	bit_flags_set_flag(hBit_flags, 36);
	bit_flags_set_flag(hBit_flags, 31);
	bit_flags_set_flag(hBit_flags, 444);
	bit_flags_set_flag(hBit_flags, 96);
	bit_flags_display(hBit_flags);
	printf("\n");
	bit_flags_unset_flag(hBit_flags, 96);
	bit_flags_unset_flag(hBit_flags, 36);
	bit_flags_unset_flag(hBit_flags, 78);
	bit_flags_display(hBit_flags);



}