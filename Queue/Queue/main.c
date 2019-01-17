#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[])
{
	QUEUE hQueue = NULL;  //declare a handle
	int i;
	hQueue = queue_init_default();
	if (hQueue == NULL)
	{
		printf("failed to creat Queue\n");
		exit(1);
	}
	for (i = 0; i < 10; i++)
	{
		queue_enqueue(hQueue, i);
	}
	while (!queue_empty(hQueue))
	{
		printf("%d\n", queue_front(hQueue, NULL));
		queue_dequeue(hQueue);
	}
	queue_destroy(&hQueue);
	return 0;
}