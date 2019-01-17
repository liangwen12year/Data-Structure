#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue
{
	int size;
	int capacity;
	int* data;
	int front;
	int back;
};
typedef struct queue Queue;

QUEUE queue_init_default(void)
{
	Queue* pQueue;
	pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue != NULL)
	{
		pQueue->size = 0;
		pQueue->capacity = 5;
		pQueue->front = 0;
		pQueue->back = 0;
		pQueue->data = (int*)malloc(sizeof(int)*pQueue->capacity);
		if (pQueue->data == NULL)
		{
			free(pQueue);
			pQueue = NULL;
		}
	}
	return pQueue;
}

Status queue_enqueue(QUEUE hQueue, int item)
{
	Queue* pQueue = (Queue*)hQueue;
	int* temp;
	int i;
	if (pQueue->size >= pQueue->capacity)
	{
		//not enough space
		temp = (int*)malloc(sizeof(int) * 2 * pQueue->capacity);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pQueue->size; i++)
		{
			temp[i] = pQueue->data[(pQueue->front + i) % pQueue->capacity];
		}
		pQueue->front = 0;
		pQueue->back = pQueue->size;
		pQueue->capacity *= 2;
		free(pQueue->data);
		pQueue->data = temp;
	}
	pQueue->data[pQueue->back] = item;
	pQueue->back = (pQueue->back + 1) % pQueue->capacity;
	pQueue->size++;

	return SUCCESS;
}

Status queue_dequeue(QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	if (pQueue->size == 0)
	{
		return FAILURE;
	}
	pQueue->front = (pQueue->front + 1) % pQueue->capacity;
	pQueue->size--;
	return SUCCESS;
}

Boolean queue_empty(QUEUE hQueue)
{
	Queue* pQueue = (Queue*)hQueue;
	return (Boolean)(pQueue->size == 0);
}

int queue_front(QUEUE hQueue, Status* pStatus)
{
	Queue* pQueue = (Queue*)hQueue;
	if (queue_empty(pQueue))
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return INT_MIN;
	}
	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	return pQueue->data[pQueue->front];
}

void queue_destroy(QUEUE* phQueue) {
	Queue* pQueue = (Queue*)*phQueue;
	free(pQueue->data);
	free(*phQueue);
	*phQueue = NULL;
	return;
}