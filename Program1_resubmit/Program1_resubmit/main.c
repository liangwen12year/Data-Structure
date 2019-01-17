#include <stdio.h>
#include "bit_flags.h"



int main(int agrc, char* argv[])
{
	int i;
	BIT_FLAGS hBit_flags = NULL;
	hBit_flags = bit_flags_init_number_of_bits(22);
	bit_flags_set_flag(hBit_flags, 78);
	bit_flags_set_flag(hBit_flags, 36);
	bit_flags_set_flag(hBit_flags, 31);
	bit_flags_set_flag(hBit_flags, 444);
	bit_flags_set_flag(hBit_flags, 96);
	for (i = 0; i < 448; i++) {
		printf("%d", bit_flags_check_flag(hBit_flags, i));
		if ((i + 1) % 4 == 0) {
			printf(" ");
		}
		if (i!=0 && ((i-31)% 32) == 0){
			printf("\n");
		}

	}


printf("********************************\n");
bit_flags_unset_flag(hBit_flags, 36);
bit_flags_unset_flag(hBit_flags, 31);
bit_flags_unset_flag(hBit_flags, 444);

for (i = 0; i < 448; i++) {
	printf("%d", bit_flags_check_flag(hBit_flags, i));
	if ((i + 1) % 4 == 0) {
		printf(" ");
	}
	if (i != 0 && ((i - 31) % 32) == 0) {
		printf("\n");
	}

}



bit_flags_destroy(&hBit_flags);
}


