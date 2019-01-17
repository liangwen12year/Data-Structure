/**********************************************************************
Program: Parenthesis Balance
Author: Wen Liang
Date: 10/11/2017
Time spent: 10h
Purpose: Be familiar with the theory of Last In First Out of Stack. Use opaque Object to access the data. Learn
to use a linked list implementation of the stack. Be familiar with the operation of Stack,say stack_push, stack_pop etc.
***********************************************************************/





#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[])
{
	FILE* fp;
	STACK hStack = NULL;
	hStack = stack_init_default();
	if (hStack == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	fp = fopen("input.txt", "r");
	stack_check(hStack, fp);
	stack_destroy(&hStack);
	fclose(fp);
	return 0;
}