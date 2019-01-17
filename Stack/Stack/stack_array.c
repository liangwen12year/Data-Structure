#include <stdio.h>
#include "stack.h"

struct stack
{
	int size;
	int capacity;
	int* data;
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
		pStack->data = (int*)(malloc(sizeof(int)*pStack->capacity));
		if (pStack->data == NULL)
		{
			free(pStack);
			pStack = NULL;
		}
	}
	return pStack;
}

Status stack_push(STACK hStack, int item)
{
	Stack* pStack = (Stack*)hStack;
	//if there enouth space
	//if not- create space (resize)
	int* temp;
	int i;
	if (pStack->size >= pStack->capacity)
	{
		temp = (int*)malloc(sizeof(int) * 2 * pStack->capacity);
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
	//we have space 
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

int stack_top(STACK hStack, Status* pStatus)
{
	Stack* pStack = (Stack*)hStack;
	if (stack_empty(hStack))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return INT_MIN;
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