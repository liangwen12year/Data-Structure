#include <stdio.h>
#include "stack.h"

int main(int argc, char* argv[])
{
	STACK hStack = NULL;
	int i;
	hStack = stack_init_default();
	if (hStack == NULL)
	{
		printf("Failed to allocate memory\n");
		exit(1);
	}
	for (i = 0; i < 10; i++)
	{
		stack_push(hStack, i);
	}
	while (!stack_empty(hStack))
	{
		printf("%d\n", stack_top(hStack, NULL));
		stack_pop(hStack);
	}

	stack_destroy(&hStack);

	return 0;
}