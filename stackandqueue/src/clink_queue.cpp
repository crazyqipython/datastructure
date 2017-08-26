#include <stdio.h>
#include <stdlib.h>
#include "clink_queue.h"

bool InitCLQueue(CLQueue *&q){
	q=NULL;
	return true;
}

bool EmptyCLQueue(CLQueue *q){
	return (q==NULL);
}

//bool DestroyCLQueue(CLQueue *&q){
//	CLQueue *p = q->rear, r;
//	if(q==NULL){
//		return true;
//	}
//	r = p;
//	q->rear->rear = NULL;
//	while(!r){
//		free(p);
//		p = r;
//		r = p->rear;
//	}
//	free(p);
//	free(q);
//	return true;
//}

bool EnCLQueue(CLQueue *&q, ElemType e){
	CLQueue *p;
	p = (CLQueue *)malloc(sizeof(CLQueue));
	p->data = e;
	if(q==NULL){
		p->rear = p;
		q=p;
	}else{

	}
	return true;
}
