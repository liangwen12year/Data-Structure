/**********************************************************************
Program: Parenthesis Balance
Author: Wen Liang
Date: 10/11/2017
Time spent: 10h
Purpose: Be familiar with the theory of Last In First Out of Stack. Use opaque Object to access the data. Learn 
to use a linked list implementation of the stack. Be familiar with the operation of Stack,say stack_push, stack_pop etc.
***********************************************************************/




#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);

Status stack_push(STACK hStack, char item);

Status stack_pop(STACK hStack);

char stack_top(STACK hStack, Status* pStatus);

Boolean stack_empty(STACK hStack);

Status stack_check(STACK hStack, FILE* fp);

void stack_destroy(STACK* phStack);
#endif