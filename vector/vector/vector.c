#include "vector.h"
#include <stdlib.h>

struct vector
{
	int size;
	int capacity;
	*char data;
};

typedef struct vector Vector;

VECTOR vector_init_default(void)
{
	Vector* pVector;
	pVector = (Vector*)malloc(sizeof(Vector));
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (*char[])(malloc(sizeof(int)*pVector->capacity));
		if (pVector->data == NULL)
		{
			free(pVector);
			pVector = NULL;
		}
	}
	return pVector;
}

int vector_get_size(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	return pVector->size;

}
int vector_get_capacity(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	return pVector->capacity;

}

Status vector_push_back(VECTOR hVector, int item)
{
	Vector* pVector = (Vector*)hVector;
	//if there enouth space
	//if not- create space (resize)
	int* temp;
	int i;
	if (pVector->size >= pVector->capacity)
	{
		temp = (int*)malloc(sizeof(int) * 2 * pVector->capacity);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		free(pVector->data);
		pVector->data = temp;
		pVector->capacity *= 2;
	}
	//we have space 
	pVector->data[pVector->size] = item;
	pVector->size++;
	return SUCCESS;
}
Status vector_pop_back(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	if (pVector->size <= 0)
	{
		return FAILURE;
	}
	pVector->size--;
	return SUCCESS;
}

int* vector_at(VECTOR hVector, int index)
{
	Vector* pVector = (Vector*)hVector;
	if (index < 0 || index >= pVector->size)
	{
		return NULL;
	}
	return &pVector->data[index];
}
void vector_destroy(VECTOR* phVector)
{
	Vector* pVector = (Vector*)*phVector;
	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}

