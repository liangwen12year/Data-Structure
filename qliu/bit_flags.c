#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

struct bit_flags
{
	int size;
	int capacity;
	unsigned int* data;
};
typedef struct bit_flags Bit_flags;
BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	Bit_flags* pBit_flags;
	pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	if (pBit_flags != NULL)
	{
		pBit_flags->size = number_of_bits;
		pBit_flags->capacity = number_of_bits + 1;
		pBit_flags->data = (unsigned int*)(malloc(sizeof(unsigned int)*pBit_flags->capacity));
		if (pBit_flags->data == NULL)
		{
			free(pBit_flags);
			pBit_flags = NULL;
		}
		unsigned int x = 0;
		unsigned int y;
		int i;
		int level;
		int level_position;
		level = number_of_bits / 32;
		level_position = number_of_bits - (level * 32);
		y = x << level_position;
		for (i = 0; i < level; i++)
		{
			pBit_flags->data[i] = 0;
		}
		pBit_flags->data[level] = 0;
		pBit_flags->data[level] = pBit_flags->data[level] | y;
		return pBit_flags;
	}
	else
		return NULL;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	unsigned int x = 1;
	unsigned int y;
	int level;
	int level_position;
	unsigned int* temp;
	int i;
	level = flag_position / 32;
	level_position = flag_position - (level * 32);
	if (flag_position > (pBit_flags->capacity))
	{
		temp = (unsigned int*)malloc(sizeof(unsigned int)*(flag_position + 1));
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < (((pBit_flags->size) / 32) + 1); i++)
		{
			temp[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->data = temp;
		pBit_flags->capacity = (flag_position + 1);
		for (i = (((pBit_flags->size) / 32) + 1); i <= level; i++)
		{
			pBit_flags->data[i] = 0;
		}
		pBit_flags->size = flag_position;
	}
	y = x << level_position;
	pBit_flags->data[level] = pBit_flags->data[level] | y;
	return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	unsigned int x = 1;
	unsigned int y;
	unsigned int z;
	int level;
	int level_position;
	unsigned int* temp;
	int i;
	level = flag_position / 32;
	level_position = flag_position - (level * 32);
	if (flag_position > (pBit_flags->capacity))
	{
		temp = (unsigned int*)malloc(sizeof(unsigned int)*(flag_position + 1));
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < (((pBit_flags->size) / 32) + 1); i++)
		{
			temp[i] = pBit_flags->data[i];
		}
		free(pBit_flags->data);
		pBit_flags->data = temp;
		pBit_flags->capacity = (flag_position + 1);
		for (i = (((pBit_flags->size) / 32) + 1); i <= level; i++)
		{
			pBit_flags->data[i] = 0;
		}
		pBit_flags->size = flag_position;
	}
	y = x << level_position;
	z = ~pBit_flags->data[level];
	z = z | y;
	pBit_flags->data[level] = ~z;
	return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	unsigned int m = 1;
	unsigned int n;
	unsigned int k;
	int level;
	int level_position;
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	if (flag_position > (pBit_flags->size))
	{
		return -1;
	}
	if (flag_position <= (pBit_flags->size))
	{
		level = flag_position / 32;
		level_position = flag_position - (level * 32);
		n = m << level_position;
		k = pBit_flags->data[level] & n;
		if (k != 0)
			return(1);
		else return(0);
	}
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
	Bit_flags* pBit_flags = (Bit_flags*)phBit_flags;
	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}

