/*
 * link_list2.cpp
 *
 *  Created on: 2017Äê7ÔÂ4ÈÕ
 *      Author: Dick
 */

#include <stdio.h>
#include <stdlib.h>
#include "sq_queue.h"

void InitQueue(SqQueue *&Q){
	Q = (SqQueue *)malloc (sizeof(SqQueue));
	Q->front = Q->rear = -1;
}

//void InitQueue(SqQueue *&q)
//{ q=(SqQueue *)malloc (sizeof(SqQueue));
//q->front=q->rear=-1;
//}

void DestroyQueue(SqQueue *&Q){
	free(Q);
}

bool QueueEmpty(SqQueue *Q){
	if(Q->front == Q->rear)
		return true;
	return false;
}

bool enQueue(SqQueue *&Q, ElemType e){
	if((Q->rear+1)%(MaxSize)==Q->front)
		return false;
	Q->rear = (Q->rear+1)%MaxSize;
	Q->data[Q->rear] = e;
	return true;
}

bool deQueue(SqQueue *&Q, ElemType &e){
	if(QueueEmpty(Q)){
		return false;
	}
	Q->front = (Q->front+1)%MaxSize;
	e = Q->data[Q->front];
	return Q;
}

bool QueueTraverse(SqQueue *Q){
	int i;
	if(QueueEmpty(Q)){
		return false;
	}
	for(i=Q->front+1; i<=Q->rear;i++){
		printf("%d ", Q->data[i]);
	}
	printf("\n\n");
	return true;
}
