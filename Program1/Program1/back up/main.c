

#include "status.h"
#include <stdio.h>
#include <stdlib.h>


typedef void* BIT_FLAGS;

struct bit_flags {
	int size;
	int capacity;
	int* data;
};

typedef struct bit_flags Bit_flags;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	{
		int i;
		Bit_flags* pBit_flags;
		pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
		if (pBit_flags != NULL)
		{
			pBit_flags->size = number_of_bits;
			pBit_flags->capacity = number_of_bits;
			pBit_flags->data = (int*)(malloc(sizeof(int)*pBit_flags->capacity));
			for (i = 0; i < number_of_bits; i++)
			{
				pBit_flags->data[i] = 0;
			}
			if (pBit_flags->data == NULL)
			{
				free(pBit_flags);
				pBit_flags = NULL;

			}
		}
		return pBit_flags;
	}
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int q, i,m;
	int* temp;
	if (flag_position >= pBit_flags->capacity)
	{
		temp = (int*)malloc(sizeof(int)*((flag_position / 32 + 1) * 32));
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < (flag_position / 32 + 1) * 32; i++) {

			temp[i] = 0;
		}
		for (q = 0; q < pBit_flags->size; q++)
		{
			temp[q] = pBit_flags->data[q];
		}
		/*for (m = 0; m < pBit_flags->capacity; m++) {

			pBit_flags->data[m] = 0;
		}*/

		free(pBit_flags->data);
		pBit_flags->data = temp;
		pBit_flags->size = (flag_position / 32 + 1) * 32;
		pBit_flags->capacity = (flag_position / 32 + 1) * 32;
		/*for (i = 0; i < pBit_flags->capacity; i++) {

			pBit_flags->data[i] = 0;
		}*/

	}
	//we have space
	pBit_flags->data[flag_position] = 1;

	return SUCCESS;
}



Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) {
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	unsigned int k;
	unsigned int i = 2147483648;
	int q;
	unsigned int* temp;
	if (flag_position >= pBit_flags->capacity)
	{
		temp = (unsigned int*)malloc(sizeof(unsigned int)*((flag_position / 32 + 1) * 32));
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < pBit_flags->capacity; i++) {

			temp[i] = 0;
		}
		for (q = 0; q < pBit_flags->size; q++)
		{
			temp[q] = pBit_flags->data[q];
		}
		free(pBit_flags->data);
		pBit_flags->data = temp;
		pBit_flags->size = (flag_position / 32 + 1) * 32;
		pBit_flags->capacity = (flag_position / 32 + 1) * 32;
	}
	//we have space
	if (pBit_flags->data[flag_position] = 1)
	{
		pBit_flags->data[flag_position] = 0;
	}


	return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	if (pBit_flags->data[flag_position] != 0)
		return 1;
	else
		return 0;
}


int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;
	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}

display_flags(BIT_FLAGS hBit_flags) {
	int i;
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	for (i = 0; i < pBit_flags->capacity; i++)
	{
		printf("%d", bit_flags_check_flag(hBit_flags, i));
		if ((i + 1) % 4 == 0)
		{
			printf(" ");
		}
		if ((i - 31) % 32 == 0)
		{
			printf("\n");
		}
	}
}



int main(int agrc, char* argv[])
{
	BIT_FLAGS hBit_flags = NULL;
	hBit_flags = bit_flags_init_number_of_bits(32);
	bit_flags_set_flag(hBit_flags, 78);
	bit_flags_set_flag(hBit_flags, 36);
	bit_flags_set_flag(hBit_flags, 31);
	bit_flags_set_flag(hBit_flags, 3);
	bit_flags_set_flag(hBit_flags, 96);
	display_flags(hBit_flags);
	bit_flags_unset_flag(hBit_flags, 36);
	bit_flags_unset_flag(hBit_flags, 78);
	display_flags(hBit_flags);



}