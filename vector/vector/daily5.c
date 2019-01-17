/***********************************************************
Author: Wen Liang
Date: 09/20/2017
Effort: 1h
Purpose: To be more familiar with the bitwise operation and shift operation,
increase the understanding toward pointer.

***********************************************************/



#include <stdio.h>


void set_flag(int* flag_holder, int flag_position) {
	int k;
	int b = 1;
	k = b << flag_position;
	*flag_holder = *flag_holder | k;
}



int check_flag(int flag_holder, int flag_position)
{
	unsigned int m;
	unsigned int c = 1;
	m = c << flag_position;
	if ((flag_holder&m) != 0)
		return 1;

	else
		return 0;
}

void display_32_flags(unsigned int flag_holder) {
	int i;
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}
void unset_flag(unsigned int * flag_holder, int flag_position)
{
	int y;
	int x = 1;
	y = ~(x << flag_position);
	*flag_holder = *flag_holder & y;
}



int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	display_32_flags(flag_holder);
	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);
	display_32_flags(flag_holder);
	return 0;
}



