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

#include "bit_flags.h"
#include <stdio.h>
#include <stdlib.h>


struct bit_flags {
	int size;
	int capacity;
	int* data;
};

typedef struct bit_flags Bit_flags;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	
		int i;
		Bit_flags* pBit_flags;
		pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
		if (pBit_flags != NULL)
		{
			pBit_flags->size = number_of_bits;
			pBit_flags->capacity = ((number_of_bits-1)/32+1)*32;
			pBit_flags->data = (int*)(malloc(sizeof(int)*(pBit_flags->capacity)/32));
			
			if (pBit_flags->data == NULL)
			{
				free(pBit_flags);
				pBit_flags = NULL;
				return pBit_flags;
			}

			for (i = 0; i < (pBit_flags->capacity) / 32; i++)
			{
				pBit_flags->data[i] = 0;
			}
			
		}
		return pBit_flags;
	
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int q, i;
	unsigned int m = 2147483648;
	int* temp;
	if ((flag_position / 32 + 1) > (pBit_flags->capacity) / 32)
	{
		temp = (int*)malloc(sizeof(int)*(flag_position / 32 + 1));
		if (temp == NULL) {
			return FAILURE;
		}
		for (i = 0; i < (flag_position / 32 + 1); i++) {

			temp[i] = 0;
		}
		for (q = 0; q < (pBit_flags->capacity) / 32; q++)
		{
			temp[q] = pBit_flags->data[q];
		}
		free(pBit_flags->data);
		pBit_flags->data = NULL;
		pBit_flags->data = temp;
		pBit_flags->size = flag_position + 1;
		pBit_flags->capacity = (flag_position / 32 + 1)*32;
	}
	pBit_flags->data[flag_position /32] = pBit_flags->data[flag_position / 32] | m >> (flag_position % 32);
	return SUCCESS;
}



Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position) 
{
		Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
		int q, i;
		unsigned int m = 2147483648;
		m = ~(m >> (flag_position % 32));
		int* temp;
		if ((flag_position / 32 + 1) > (pBit_flags->capacity) / 32)
		{
			temp = (int*)malloc(sizeof(int)*(flag_position / 32 + 1));
			if (temp == NULL) {
				return FAILURE;
			}
			for (i = 0; i < (flag_position / 32 + 1); i++) {

				temp[i] = 0;
			}
			for (q = 0; q < (pBit_flags->capacity) / 32; q++)
			{
				temp[q] = pBit_flags->data[q];
			}

			free(pBit_flags->data);
			pBit_flags->data = temp;
			pBit_flags->size = flag_position  + 1;
			pBit_flags->capacity = (flag_position / 32 + 1) * 32;
		}
		pBit_flags->data[flag_position / 32] = pBit_flags->data[flag_position / 32] & m;
		return SUCCESS;
	}


int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{	
	int i, j;
	unsigned int m = 2147483648;
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	if (flag_position < 0 || flag_position >= (pBit_flags->capacity))
		return -1;
	if (((pBit_flags->data[flag_position / 32]) & (m >>(flag_position % 32)))!= 0)
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



/*int main(int agrc, char* argv[])
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
		if (i != 0 && ((i - 31) % 32) == 0) {
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
*/