#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack
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
	char err = 'F';
	Stack* pStack = (Stack*)hStack;
	if (stack_empty(hStack))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return err;
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

void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	free(pStack->data);
	free(pStack);
	*phStack = NULL;
}




Status parentheses_check(STACK hStack, FILE* fp)
{
	int flag = 0;
	int m;
	int line_num;
	int get_line;
	char par_char;
	Stack* pStack = (Stack*)hStack;
	get_line = fscanf(fp, "%d", &line_num);
	if (fget(fp) != '\n')
	{
		return FAILURE;
	}
	m = line_num;
	while (m > 0)
	{
		par_char = fgetc(fp);
		while (par_char != '\n'&&par_char != EOF &&m > 0)
		{
			if (par_char == '(' || par_char == '[' &&par_char == '{')
			{
				stack_push(pStack, par_char);
				par_char = fgetc(fp);
			}
			if (par_char == ')')
			{
				if (stack_top(pStack, NULL) == '(')
				{
					par_char = fgetc(fp);
					stack_pop(pStack);
				}
				else
				{
					flag = 1;
					printf("NO\n");
					m--;
					while (pStack->size > 0)
						stack_pop(pStack);
					while (par_char != '\n')
					{
						par_char = fgetc(fp);
					}
					par_char = fgetc(fp);
				}
			}

			if (par_char == ']')
			{
				if (stack_top(pStack, NULL) == '[')
				{
					par_char = fgetc(fp);
					stack_pop(pStack);
				}
				else
				{
					flag = 1;
					printf("NO\n");
					m--;
					while (pStack->size > 0)
						stack_pop(pStack);
					while (par_char != '\n')
					{
						par_char = fgetc(fp);
					}
					par_char = fgetc(fp);
				}
			}

			if (par_char == '}')
			{
				if (stack_top(pStack, NULL) == '{')
				{

					par_char = fgetc(fp);
					stack_pop(pStack);
				}
				else
				{
					flag = 1;
					printf("NO\n");
					m--;
					while (pStack->size > 0)
						stack_pop(pStack);
					while (par_char != '\n')
					{
						par_char = fgetc(fp);
					}
					par_char = fgetc(fp);
				}
			}
		}
		if (pStack->size == 0 && flag == 0)
		{
			printf("YES\n");
			m--;
		}
		return SUCCESS;

	}

	}

/*Status parentheses_check(STACK hStack, FILE* fp)
{
	int m;
	int line_num;
	int get_line;
	char par_char;
	Stack* pStack = (Stack*)hStack;
	get_line = fscanf(fp,"%d",&line_num);
	if (fgetc(fp) != '\n')
	{
		return FAILURE;
	}
	m = line_num;
	while (m >0)
	{
		par_char = fgetc(fp);
		while (par_char != '\n'&&par_char != EOF&&m >0)
		{
			if (par_char != '(' && par_char != '[' && par_char != '{'&&par_char != ')' && par_char != ']' && par_char != '}')
			{
				par_char = fgetc(fp);
			}
			if (par_char == '(' || par_char == '[' || par_char == '{')
			{
				stack_push(pStack, par_char);
				par_char = fgetc(fp);
			}
			if (par_char == ')')
			{
				if (stack_top(pStack, NULL) == '(')
				{
					par_char = fgetc(fp);
					stack_pop(pStack);
				}
				else
				{
					printf("NO\n");
					m--;
					while (pStack->size >0)
						stack_pop(pStack);
					while (par_char != '\n')
					{
						par_char = fgetc(fp);
					}
					par_char = fgetc(fp);										
				}
			}
			if (par_char == ']')
			{
				if (stack_top(pStack, NULL) == '[')
				{
					par_char = fgetc(fp);
					stack_pop(pStack);
				}
				else
				{
					printf("NO\n");
					m--;
					while (pStack->size >0)
						stack_pop(pStack);
					while (par_char != '\n')
					{
						par_char = fgetc(fp);
					}
					par_char = fgetc(fp);					
				}
			}
			if (par_char == '}')
			{
				if (stack_top(pStack, NULL) == '{')
				{
					par_char = fgetc(fp);
					stack_pop(pStack);
				}
				else
				{
					printf("NO\n");
					m--;
					while (pStack->size >0)
						stack_pop(pStack);
					while (par_char != '\n')
					{
						par_char = fgetc(fp);
					}
					par_char = fgetc(fp);
				}
			}
		}
		if (pStack->size == 0&&)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
		m--;
		while (pStack->size >0)
			stack_pop(pStack);		
	}
	return SUCCESS;
}
*/