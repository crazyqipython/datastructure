#ifndef CLINK_QUEUE_H_
#define CLINK_QUEUE_H_
typedef int ElemType;

typedef struct Cl_Queue{
	ElemType data;
	struct Cl_Queue *rear;
}CLQueue;

bool InitCLQueue(CLQueue *&q);
bool DestroyCLQueue(CLQueue *&q);
bool EmptyCLQueue(CLQueue *q);
bool EnCLQueue(CLQueue *&q, ElemType e);
bool EnCLQueue(CLQueue *&q, ElemType &e);



#endif /* CLINK_QUEUE_H_ */
