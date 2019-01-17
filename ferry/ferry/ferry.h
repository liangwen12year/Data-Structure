#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

void queue_init(Queue* pQueue);
Status queue_enqueue(Queue* pQueue, int item);
Status queue_dequeue(Queue* pQueue);
Boolean queue_empty(Queue* pQueue);
int queue_front(Queue* pQueue);
void queue_destroy(Queue* pQueue);

#endif
