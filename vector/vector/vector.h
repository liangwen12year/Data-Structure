#include "status.h"
typedef void* VECTOR;

VECTOR vector_init_default(void);
//check the size
int vector_get_size(VECTOR hVector);

//check capacity
int vector_get_capacity(VECTOR hVector);

//print data
//add item
Status vector_push_back(VECTOR hVector, int item);

//delete item
//output the value of particular item
Status vector_pop_back(VECTOR hVector);
int* vector_at(VECTOR hVector, int index);
void vector_destroy(VECTOR* phVector);