/***********************************************************
Author: Wen Liang
Date: 09/26/2017
Effort: 6h
Purpose: To be morefamiliar with the bitwise operation and shift operation,
increase the understanding toward pointer. Begin to understand the transformation of the form of parameters,
say transfer from bitwise to integer, from array to interger etc.

***********************************************************/



#include <stdio.h>


void set_flag(unsigned int flag_holder[], int flag_position) {
	
	unsigned int k ;
	unsigned int i = 2147483648;
	int aa = flag_position / 32;

	int tt = (flag_position - aa * 32);
	
	k = i>>tt;
	flag_holder[aa] = flag_holder[aa] | k;
}


int check_flag(unsigned int flag_holder[], int flag_position)
{
	
	unsigned int m;
	unsigned int c = 1;
	m = c << (31-flag_position);
	if ((flag_holder[0]&m) != 0)
		return 1;
	else
		return 0;
}

void display_32_flags_as_array(unsigned int flag_holder) {
	int j;
	{
		int i[1] = { 0 };
		i[0] = flag_holder;
		for (j = 0; j < 32; j++)
		{
			if ((j != 0) && (j % 4 == 0))
				printf(" ");
			printf("%d", check_flag(i, j));

		}
		printf("\n");
	}
}

void display_flags(unsigned int flag_holder[], int size) {

	int j,i;
	for (j = 0; j < size; j++) {

		i=flag_holder[j];
		display_32_flags_as_array(i);
	}
		

}


void unset_flag(unsigned int flag_holder[], int flag_position)	
{
	int y;
	int q;
	q = (flag_position / 32);
	int x = 1;
	y = ~(x<< 31-flag_position);
	flag_holder[q] = flag_holder[q] & y;
}



int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others to zero by default.
	
	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);
	display_flags(flag_holder, 5);
	printf("\n\n");
	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);
	display_flags(flag_holder, 5);


	return 0;
}

























