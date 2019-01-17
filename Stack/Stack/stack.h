#ifndef STACK_H
#define STACK_H

#include "status.h"

typedef void* STACK;
//init stack
STACK stack_init_default(void);

//push
//Precondition: hStack is handle a valid stuck object
//Postcondition: return SUCCUSS if item was added successfuly, FAILURE otherwise
Status stack_push(STACK hStack, int item);

//pop
// Precondition: hStack is handle a valid stuck object
//Postcondition: return SUCCUSS if item was removed
Status stack_pop(STACK hStack);

//return top
int stack_top(STACK hStack, Status* pStatus);

Boolean stack_empty(STACK hStack);

void stack_destroy(STACK* phStack);
#endif