#include "bit_flags.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	BIT_FLAGS hBit_flags = NULL;
	hBit_flags=bit_flags_init_number_of_bits(55);//test

	bit_flags_set_flag(hBit_flags, 187);	
	bit_flags_set_flag(hBit_flags, 3);
	bit_flags_set_flag(hBit_flags, 39);

	printf("%d \n", bit_flags_check_flag(hBit_flags, 30));
	printf("%d \n", bit_flags_check_flag(hBit_flags, 39));
	printf("%d \n", bit_flags_check_flag(hBit_flags, 339));

	printf("size is %d, capacity is %d \n", bit_flags_get_size(hBit_flags), bit_flags_get_capacity(hBit_flags));
	bit_flags_unset_flag(hBit_flags, 187);
	bit_flags_unset_flag(hBit_flags, 39);
	bit_flags_unset_flag(hBit_flags, 3);
	printf("%d \n", bit_flags_check_flag(hBit_flags, 30));
	printf("%d \n", bit_flags_check_flag(hBit_flags, 39));
	printf("%d \n", bit_flags_check_flag(hBit_flags, 439));


	//bit_flags_destroy(&hBit_flags);//something strange here.
	return 0;
}
