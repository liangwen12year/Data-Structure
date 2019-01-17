/**********************************************************************
Program: Parenthesis Balance
Author: Wen Liang
Date: 10/11/2017
Time spent: 10h
Purpose: Be familiar with the theory of Last In First Out of Stack. Use opaque Object to access the data. Learn
to use a linked list implementation of the stack. Be familiar with the operation of Stack,say stack_push, stack_pop etc.
***********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



struct node;
typedef struct node Node;

struct node 
{
	char data;
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

Status stack_push(STACK hStack, char item)
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
char stack_top(STACK hStack, Status* pStatus)
{
	char error = 'F';
	Stack* pStack = (Stack*)hStack;
	if (stack_empty(hStack))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return error;
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
	
	return (Boolean)(pStack->head == NULL);
}
void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	Node* temp;
		while (pStack->head!=NULL)
		{
			temp = pStack->head;
			pStack->head = pStack->head->next;
			free(temp);
		}
	free(pStack);
	*phStack = NULL;
	return ;
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

	while (check_count >0)
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
					while (stack_empty(hStack)==FALSE)
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
					while (stack_empty(pStack)==FALSE)
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
					while (stack_empty(pStack)==FALSE)
						stack_pop(pStack);
					while (check_char != '\n' && check_char != EOF)
					{
						check_char = fgetc(fp);
					}
					break;
				}
			}
		}
		if (stack_empty(pStack)==TRUE && flag == 0)
		{
			printf("Yes\n");
			flag = 0;
		}
		if (stack_empty(pStack)==FALSE)
		{
			printf("No\n");
			flag = 0;
		}
		flag = 0;
		check_count--;
		while (stack_empty(hStack)==FALSE)
			stack_pop(pStack);
	}
	return SUCCESS;
}
