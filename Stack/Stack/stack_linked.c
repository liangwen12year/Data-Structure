#include <stdio.h>
#include "stack.h"

struct node;
typedef struct node Node;
//self referential structua
struct node 
{
	int data;
	Node* next;
};
//known type
struct stack
{
	Node* head;
};
typedef struct stack Stack;

STACK stack_init_default(void)
{
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->head = NULL;
	}
	return pStack;
}

Status stack_push(STACK hStack, int item)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}
	temp->data = item;
	temp->next = pStack->head;
	pStack->head = temp;
	return SUCCESS;
}
Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp;
	if (pStack->head == NULL)
	{
		return FAILURE;
	}
	temp = pStack->head;
	pStack->head = pStack->head->next;
	free(temp);
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
	return pStack->head->data;
}

Boolean stack_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	/*if (pStack->head == NULL)
	{
		return TRUE;
	}
	else
		return FALSE;*/
	return (Boolean)(pStack->head == NULL);
}
void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	Node* temp;
		while (pStack->head!=NULL)//there is something to destroy
		{
			temp = pStack->head;
			pStack->head = pStack->head->next;
			free(temp);
		}
	free(pStack);
	*phStack = NULL;
	return ;
}