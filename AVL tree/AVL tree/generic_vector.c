#include "generic_vector.h"
#include <stdlib.h>

struct g_vector
{
	int size;
	int capacity;
	Item_ptr data;
	Status(*item_assignment)(Item_ptr, Item);
	void(*item_destroy)(Item_ptr);
};
typedef struct g_vector G_Vector;

G_VECTOR g_vector_init_default(Status(*item_assignment)(Item_ptr, Item),
	void(*item_destroy)(Item_ptr))
{
	G_Vector* pVector;
	int i;
	pVector = (G_Vector*)malloc(sizeof(G_Vector));
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->item_destroy = item_destroy;
		pVector->item_assignment = item_assignment;
		pVector->data = (void**)(malloc(sizeof(void*)*pVector->capacity));
		if (pVector->data == NULL)
		{
			free(pVector);
			pVector = NULL;
		}
		else
		{
			for (i = 0; i < pVector->capacity; i++)
			{
				pVector->data[i] = NULL;
			}
		}
	}
	return pVector;
}

void g_vector_destroy(G_VECTOR* phG_Vector)
{
	G_Vector* pVector = (G_Vector*)*phG_Vector;
	int i;
	for (i = 0; i < pVector->capacity; i++)
	{
		if (pVector->data[i] != NULL)
		{
			pVector->item_destroy(&pVector->data[i]);
		}
	}
	free(pVector->data);
	free(pVector);
	*phG_Vector = NULL;
}

Status g_vector_push_back(G_VECTOR hVector, Item item)
{
	G_Vector* pVector = (G_Vector*)hVector;
	//if there enouth space
	//if not- create space (resize)
	Item_ptr temp;
	int i;
	if (pVector->size >= pVector->capacity)
	{
		temp = (Item_ptr)malloc(sizeof(Item) * 2 * pVector->capacity);
		if (temp == NULL)
		{
			return FAILURE;
		}
		pVector->capacity *= 2;

		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		for (i = pVector->size; i < pVector->capacity; i++)
		{
			temp[i] = NULL;
		}
		free(pVector->data);
		pVector->data = temp;
	}
	//we have space 
	pVector->item_assignment(&pVector->data[pVector->size], item);
	pVector->size++;
	return SUCCESS;
}

Status g_vector_pop_back(G_VECTOR hVector)
{
	G_Vector* pVector = (G_Vector*)hVector;
	if (pVector->size <= 0)
	{
		return FAILURE;
	}
	pVector->size--;
	return SUCCESS;
}
Item g_vector_at(G_VECTOR hVector, int index)
{
	G_Vector* pVector = (G_Vector*)hVector;
	if (index < 0 || index >= pVector->size)
	{
		return NULL;
	}
	return pVector->data[index];
}
int g_vector_get_size(G_VECTOR hVector)
{
	G_Vector* pVector = (G_Vector*)hVector;
	return pVector->size;

}
int g_vector_get_capacity(G_VECTOR hVector)
{
	G_Vector* pVector = (G_Vector*)hVector;
	return pVector->capacity;

}