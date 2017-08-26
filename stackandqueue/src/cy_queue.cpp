#include <stdio.h>
#include <stdlib.h>
#include "cy_queue.h"

void InitQueue(CyQueue *&q){
	q = (CyQueue *)malloc(sizeof(CyQueue));
	q->count=0;
	q->front = 0;
}

void DestroyQueue(CyQueue *&q){
	free(q);
}

bool EnQueue(CyQueue *&q, ElemType e){
	int rear;
	rear = (q->front + q->count + MaxSize)%MaxSize;
	if(q->count == MaxSize){
		return false;
	}
	q->data[(rear+1) %MaxSize] = e;
	q->count++;
	return true;
}

bool DeQueue(CyQueue *&q, ElemType &e){
	int rear;
	rear = (q->front + q->count + MaxSize)%MaxSize;
	if(rear == q->front){
		return false;
	}
	q->front = (q->front +1)%MaxSize;
	e = q->data[q->front];
	q->count--;
	return true;
}

bool QueueEmpty(CyQueue *&q){
	int rear;
	rear = (q->front + q->count + MaxSize)%MaxSize;
	if(rear==q->front){
		return true;
	}
	return false;
}
