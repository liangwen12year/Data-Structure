#ifndef STACK_H
#define STACK_H
typedef void* STACK;
STACK stack_init_default(void);
enum status { FAILURE, SUCCESS };
typedef enum status Status;
enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;
Status stack_push(STACK hStack, char item);
Status stack_pop(STACK hStack);
char stack_top(STACK hStack, Status* pStatus);
Boolean stack_empty(STACK hStack);
Status parentheses_check(STACK hStack, FILE* fp);
void stack_destroy(STACK* phStack);
#endif