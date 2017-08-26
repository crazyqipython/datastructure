#include <stdio.h>
#include <stdlib.h>
#include "link_queue.h"

bool InitLinkQueue(LQueue *&q){
	q = (LQueue *)malloc(sizeof(LQueue));
	if(!q){
		exit(-1);
	}
	q->front = NULL;
	q->rear = NULL;
	return true;
}

bool DestroyLinkQueue(LQueue *&q){
	QNode *p = q->front, *r;
	if(!p){
		r = p->next;
		while(r!=NULL){
			free(p);
			p = r;
			r = p->next;
		}
	}
	free(p);
	free(q);
	q->front = q->rear =NULL;
	return true;
}

bool LQueueEmpty(LQueue *q){
	return (q->front == NULL && q->rear == NULL);
}

bool EnLinkQueue(LQueue *&q, ElemType e){
	struct QNode *p;
	p = (struct QNode *)malloc(sizeof(struct QNode));
	if(!p)
		return false;
	p->data = e;
	if(LQueueEmpty(q)){
		p->next = q->front;
		q->front = p;
		q->rear =p;
		return true;
	}
	else{
		q->rear->next = p;
		q->rear = p;
		return true;
	}
}

bool DeLinkQueue(LQueue *&q, ElemType &e){
	struct QNode *p;
	if(LQueueEmpty(q)){
		return false;
	}
	else if((q->front==q->rear) && (q->front != NULL)){
		e = q->front->data;
		free(q->front);
		q->rear = q->front = NULL;
		return true;
	}
	else{
		p = q->front;
		e = p->data;
		q->front = p->next;
		free(p);
		p = NULL;
		return true;
	}
}
