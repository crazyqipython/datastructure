/*
 * sq_queue.h
 *
 *  Created on: 2017Äê7ÔÂ9ÈÕ
 *      Author: Dick
 */

#ifndef SQ_QUEUE_H_
#define SQ_QUEUE_H_
#define MaxSize 10

typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue *&Q);
void DestroyQueue(SqQueue *&Q);
bool QueueEmpty(SqQueue *Q);
bool enQueue(SqQueue *&Q, ElemType e);
bool deQueue(SqQueue *&Q, ElemType &e);
bool QueueTraverse(SqQueue *Q);




#endif /* SQ_QUEUE_H_ */
