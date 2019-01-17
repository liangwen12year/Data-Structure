/**********************************************************************
Program: Sorting List
Author: Wen Liang
Date: 11/05/2017
Time spent: 3h
Purpose: The purpose of this program is to use vector to restore distinct numbers,and
use sorting method to sort the list.
***********************************************************************/


#include <stdlib.h>
#include <stdio.h>
int c,j;
enum status { FAILURE, SUCCESS };
typedef enum status Status;
struct vector
{
	int size;
	int capacity;
	int* data;
};


typedef struct vector Vector;
typedef void* VECTOR;
VECTOR vector_init_default(void);
void swap(int* a, int* b);
void quick_sort(int a[], int size);
Status vector_push_back(VECTOR hVector, int item);
int vector_get_size(VECTOR hVector);

int c, i, j;


int main(int argc, char* argv[]) {
	//int c, j, i;
	//int j = 0;
	VECTOR hVector = NULL;
	hVector = vector_init_default();
	Vector* pVector = (Vector*)hVector;
	scanf("%d", &c);
	//printf("%d",c);
	while (c != -1) {
		
		for (j = 0; j < vector_get_size(hVector); j++) {
			if (c == pVector->data[j])
				break;
		}
	
		if (j == vector_get_size(hVector)) {
			
			vector_push_back(hVector, c);
			//printf("n");
		}
		scanf("%d", &c);
	}

	
	// for (i = 0; i <vector_get_size(hVector); i++) {
	//	 j = i;
	//	 while (j - 1 >= 0 && pVector->data[j] < pVector->data[j - 1]) {
	//		 swap(&(pVector->data[j - 1]), &(pVector->data[j]));
	//		 j--;
	//	 }

	// }
	quick_sort(pVector->data, vector_get_size(hVector));
	  for (i = 0; i < vector_get_size(hVector); i++) {
		printf("%d\n", pVector->data[i]);
	}
	// scanf("%d", &c);
	 
	 return 0;
}

VECTOR vector_init_default(void)
{
	Vector* pVector;
	pVector = (Vector*)malloc(sizeof(Vector));
	if (pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->data = (int*)(malloc(sizeof(int)*pVector->capacity));
		if (pVector->data == NULL)
		{
			free(pVector);
			pVector = NULL;
		}
	}
	return pVector;
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

int vector_get_size(VECTOR hVector)
{
	Vector* pVector = (Vector*)hVector;
	return pVector->size;

}

void quick_sort(int a[], int size) {
	int* left;
	int* right;
	int* pivot;
	pivot = &a[0];
	left = a;
	right = a + size - 1;
	if (size < 2) {
		return;
	}
	while (left < right) {
		while (right > left && *right > *pivot) {
			right--;
		}

		while (left < right && *left <= *pivot) {
			left++;
		}
		if (left != right)
			swap(left, right);
	}
	swap(pivot, left);
	quick_sort(a, left - a);
	quick_sort(&a[left - a + 1], &a[size - 1] - right);
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}


