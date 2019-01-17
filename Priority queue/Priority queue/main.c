
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
	PRIORITY_QUEUE hQueue = NULL;  //declare a handle
	//int i;
	hQueue = priority_queue_init_default();
	if (hQueue == NULL)
	{
		printf("failed to creat Queue\n");
		exit(1);
	}
	priority_queue_insert(hQueue, 21, 10);
	priority_queue_insert(hQueue, 35, 5);
	priority_queue_insert(hQueue, 48, 1);
	priority_queue_insert(hQueue, 50, 3);
	priority_queue_insert(hQueue, 24, 6);

	//Priority_queue* pPriority_queue;
	//for (i = 0; i < 5; i++)
	//{
		printf("%d\n", priority_queue_front(hQueue, NULL));
	//}
		priority_queue_service(hQueue);
		printf("%d\n", priority_queue_front(hQueue, NULL));
		priority_queue_service(hQueue);
		printf("%d\n", priority_queue_front(hQueue, NULL));
		priority_queue_service(hQueue);
		printf("%d\n", priority_queue_front(hQueue, NULL));
		priority_queue_service(hQueue);
		printf("%d\n", priority_queue_front(hQueue, NULL));
		priority_queue_destroy(&hQueue);
	return 0;
}
