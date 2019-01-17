#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

Status int_assignment(Item_ptr phLeft, Item hRight);
void int_destroy(Item_ptr phInt);

int main(int argc, char* agrv[])
{
	G_VECTOR hVector = NULL;
	int x;
	int i;
	hVector = g_vector_init_default(int_assignment, int_destroy);
	if (hVector == NULL)
	{
		exit(1);
	}
	x = 10;
	g_vector_push_back(hVector, &x);
	x = 100;
	g_vector_push_back(hVector, &x);
	for (i = 0; i < g_vector_get_size(hVector); i++)
	{
		printf("%d: %d\n", i, *(int*)g_vector_at(hVector, i));
	}
	g_vector_pop_back(hVector);
	g_vector_destroy(&hVector);
	return 0;
}
Status int_assignment(Item_ptr phLeft, Item hRight)
{
	int* pLeft = (int*)*phLeft;
	int* pRight = (int*)hRight;
	if (pLeft == NULL)
	{
		pLeft = (int*)malloc(sizeof(int));
		if (pLeft == NULL)
		{
			return FAILURE;
		}
		*phLeft = pLeft;
	}
	*pLeft = *pRight;
	return SUCCESS;
}
void int_destroy(Item_ptr phInt)
{
	int* pInt = (int*)*phInt;
	free(pInt);
	*phInt = NULL;
}