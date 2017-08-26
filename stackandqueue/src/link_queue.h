
#ifndef LINK_QUEUE_H_
#define LINK_QUEUE_H_
#include <stdio.h>
typedef int ElemType;

typedef struct QNode{
	ElemType data;
	struct QNode *next;
};

typedef struct{
	struct QNode *front;
	struct QNode *rear;
}LQueue;

bool InitLinkQueue(LQueue *&q);
bool DestroyLinkQueue(LQueue *&q);
bool LQueueEmpty(LQueue *q);
bool EnLinkQueue(LQueue *&q, ElemType e);
bool DeLinkQueue(LQueue *&q, ElemType &e);


#endif /* LINK_QUEUE_H_ */
