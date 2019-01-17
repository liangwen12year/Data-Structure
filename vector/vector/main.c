#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


int main(int argc, char* agrv[])
{
	//step1: Declare the handle 
	VECTOR hVector = NULL;
	int i;
	int* p;
	//step 2: Init object
	hVector = vector_init_default();
	//step 3: use the object
	printf("size=%d\n", vector_get_size(hVector));
	printf("capacity=%d\n", vector_get_capacity(hVector));
	for (i = 0; i < 10; i++) {
		if (vector_push_back(hVector, rand()) == FAILURE)
		{
			printf("Cannot add item\n");
			exit(1);
		}
		printf("size=%d capacity=%d\n", vector_get_size(hVector), vector_get_capacity(hVector));
	}
	vector_pop_back(hVector);
	printf("%d %d\n", vector_at(hVector, 2), *vector_at(hVector, 2));
	p = vector_at(hVector, 2);
	*p = 34; p = NULL;
	printf("%d %d\n", vector_at(hVector, 2), *vector_at(hVector, 2));
	//step 4: destroy object
	vector_destroy(&hVector);
	if (hVector == NULL)
	{
		printf("Done\n");
	}
	return 0;
}