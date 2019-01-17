#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[])
{
	STACK hStack = NULL;
	FILE* fp;	
	hStack = stack_init_default();
	if (hStack == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	fp = fopen("input.txt", "r");
	parentheses_check(hStack, fp);
	stack_destroy(&hStack);
	fclose(fp);
	return 0;
}