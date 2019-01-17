/**********************************************************************
Program: <ferry loading>
Author: <Wen Liang>
Date: <10/25/2017>
Time spent: <10h>
Purpose: Learn how to implement queue with linked list, learn how to use the fisrt in first out principle 
of queue to solve practical problems. Learn to analyze problems from different perspective.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>


enum status { FAILURE, SUCCESS };
typedef enum status Status;
enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;

typedef struct node Node;
typedef struct queue Queue;

void queue_init(Queue* pQueue);
Status queue_enqueue(Queue* pQueue, int item);
Status queue_dequeue(Queue* pQueue);
Boolean queue_empty(Queue* pQueue);
int queue_front(Queue* pQueue);
void queue_destroy(Queue* pQueue);

struct node
{
	int data;
	Node* next;
};

struct queue
{
	Node* front;
	Node* back;
};



int main()
{
	FILE* fp;
	Queue left;
	Queue right;
	int test, l, number, length, container, i, j;
	char x[10];
	int count = 0;

	queue_init(&left);
	queue_init(&right);
	fp=fopen("a.txt", "r");
	//fp = stdin;
	fscanf(fp, "%d", &test);
	for (i = 0; i < test; i++)
	{
		fscanf(fp, "%d %d", &l, &number);
		l = l * 100;
		container = l;
		for (j = 0; j < number; j++)
		{
			fscanf(fp, "%d %s", &length, &x);
			if (x[0] == 'l')
			{
				queue_enqueue(&left, length);
			}
			if (x[0] == 'r')
			{
				queue_enqueue(&right, length);
			}
		}

		while (!queue_empty(&left) || !queue_empty(&right))
		{
			if (queue_empty(&left) && !queue_empty(&right))
			{
					count++;
				while ((l >= queue_front(&right)) && !queue_empty(&right))
				{
					l = l - queue_front(&right);
					queue_dequeue(&right);
				}
					count++;
					l = container;
			}

			if (!queue_empty(&left) && queue_empty(&right))
			{
				while ((l >= queue_front(&left)) && !queue_empty(&left))
				{
					l = l - queue_front(&left);
					queue_dequeue(&left);
				}
					count++;
					l = container;
				if (!queue_empty(&left))
				{
					count++;
				}
			}

			if (!queue_empty(&left) && !queue_empty(&right))
			{
				while ((l >= queue_front(&left)) && !queue_empty(&left))
				{
					l = l - queue_front(&left);
					queue_dequeue(&left);
				}
					count++;
					l = container;
				while ((l >= queue_front(&right)) && !queue_empty(&right))
				{
					l = l - queue_front(&right);
					queue_dequeue(&right);
				}
					count++;
					l = container;
			}
		}
		printf("%d\n", count);
		
		queue_destroy(&left);
		queue_destroy(&right);
		count = 0;
	}
	fclose(fp);
	return 0;
}


void queue_init(Queue* pQueue)
{
	pQueue->front = NULL;
	pQueue->back = NULL;
}


Status queue_enqueue(Queue* pQueue, int item)
{
	Node* temp;
	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}
	temp->data = item;
	temp->next = NULL;
	if (pQueue->back == NULL)
	{
		pQueue->front = temp;
		pQueue->back = temp;
	}
	else
	{
		pQueue->back = pQueue->back->next = temp;
	}
	return SUCCESS;
}


Status queue_dequeue(Queue* pQueue)
{
	Node* temp;
	if (pQueue->front == NULL)
	{
		printf("This is empty Queue, can not dequeue.\n");
		return FAILURE;
	}
	temp = pQueue->front;
	pQueue->front = temp->next;
	if (pQueue->front == NULL)
	{
		pQueue->back = NULL;
	}
	free(temp);
	return SUCCESS;
}

int queue_front(Queue* pQueue)
{
	if (pQueue->front == NULL)
	{
		return 0;
	}
	return pQueue->front->data;
}


Boolean queue_empty(Queue* pQueue)
{
	if (pQueue->front == NULL)
	{
		return TRUE;
	}
	else
		return FALSE;
}


void queue_destroy(Queue* pQueue)
{
	Node* temp;
	temp = pQueue->front;
	while (temp != NULL)
	{
		pQueue->front = pQueue->front->next;
		free(temp);
		temp = pQueue->front;
	}
	pQueue->back = NULL;
}