
#ifndef CY_QUEUE_H_
#define CY_QUEUE_H_

#define MaxSize 10

typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int front;
	int count;
}CyQueue;

void InitQueue(CyQueue *&q);
void DestroyQueue(CyQueue *&q);
bool EnQueue(CyQueue *&q, ElemType e);
bool DeQueue(CyQueue *&q, ElemType &e);
bool QueueEmpty(CyQueue *&q);

#endif
