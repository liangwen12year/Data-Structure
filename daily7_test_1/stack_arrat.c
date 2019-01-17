#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*struct stack
{
	int size;
	int capacity;
	char* data;
};

typedef struct stack Stack;

STACK stack_init_default(void)
{
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->size = 0;
		pStack->capacity = 1;
		pStack->data = (char*)(malloc(sizeof(char)*pStack->capacity));
		if (pStack->data == NULL)
		{
			free(pStack);
			pStack = NULL;
		}
	}
	return pStack;
}

Status stack_push(STACK hStack, char item)
{
	Stack* pStack = (Stack*)hStack;
	char* temp;
	int i;
	if (pStack->size >= pStack->capacity)
	{
		temp = (char*)malloc(sizeof(char) * 2 * pStack->capacity);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pStack->size; i++)
		{
			temp[i] = pStack->data[i];
		}
		free(pStack->data);
		pStack->data = temp;
		pStack->capacity *= 2;
	}
	pStack->data[pStack->size] = item;
	pStack->size++;
	return SUCCESS;
}

Status stack_pop(STACK hStack) {
	Stack* pStack = (Stack*)hStack;
	if (pStack->size <= 0)
	{
		return FAILURE;
	}
	pStack->size--;
	return SUCCESS;
}

char stack_top(STACK hStack, Status* pStatus)
{	
	char X = 'F';
	Stack* pStack = (Stack*)hStack;
	if (stack_empty(hStack))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return X;
	}
	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	return pStack->data[pStack->size - 1];
}

Boolean stack_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	if (pStack->size == 0)
	{
		return TRUE;
	}
	return FALSE;
}


Status stack_check(STACK hStack, FILE* fp)
{
	Stack* pStack = (Stack*)hStack;
	int check_count;
	int flag = 0;
	char check_char;
	fscanf(fp, "%d", &check_count);

	if (fgetc(fp) != '\n')
	{
		return FAILURE;
	}
	
	while (check_count >0 )
	{
		check_char = fgetc(fp);
		if (check_char == EOF)
		{
			return FAILURE;
		}
		if (check_char == '\n')
		{
			printf("Yes\n");
			flag = 2;
		}
		while (check_char != '\n' && check_char != EOF)
		{
			if (check_char == '(' || check_char == '[' || check_char == '{')
			{
				stack_push(pStack, check_char);
				check_char = fgetc(fp);
			}
			if (check_char == ')')
			{
				if (stack_top(pStack, NULL) == '(')
				{
					check_char = fgetc(fp);
					stack_pop(pStack);
					
				}
				else
				{
					flag = 1;
					printf("No\n");
					while (pStack->size >0)
						stack_pop(pStack);
					while (check_char != '\n' && check_char != EOF)
					{
						check_char = fgetc(fp);
					}
					break;
				}
			}
			if (check_char == ']')
			{
				if (stack_top(pStack, NULL) == '[')
				{
					check_char = fgetc(fp);
					stack_pop(pStack);
					
				}
				else
				{
					flag = 1;
					printf("No\n");
					while (pStack->size >0)
						stack_pop(pStack);
					while (check_char != '\n' && check_char != EOF)
					{
						check_char = fgetc(fp);
					}
					break;
				}
			}
			if (check_char == '}')
			{
				if (stack_top(pStack, NULL) == '{')
				{
					check_char = fgetc(fp);
					stack_pop(pStack);
					
				}
				else
				{
					flag = 1;
					printf("No\n");
					while (pStack->size >0)
						stack_pop(pStack);
					while (check_char != '\n' && check_char != EOF)
					{
						check_char = fgetc(fp);
					}
					break;
				}
			}
		}
		if (pStack->size == 0 && flag== 0)
		{
			printf("Yes\n");
			flag = 0;
		}
		if (pStack->size != 0)
		{
			printf("No\n");
			flag = 0;
		}
		flag = 0;
		check_count--;
		while (pStack->size >0)
			stack_pop(pStack);
	}
	return SUCCESS;
}


void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	free(pStack->data);
	free(pStack);
	*phStack = NULL;
}