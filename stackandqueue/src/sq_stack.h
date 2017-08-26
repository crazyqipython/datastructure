#ifndef SQ_STACK_H_
#define SQ_STACK_H_

#define STACK_INIT_SIZE 100
#define StACKINCREMENT 10
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0

typedef int SElemType;
typedef int Status;

typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

Status InitStack(SqStack &S);
Status DestroyStack(SqStack &S);
Status ClearStack(SqStack &S);
Status StackEmpty(SqStack &S);
int StackLength(SqStack &S);
Status GetTop(SqStack &S, SElemType &e);
Status Push(SqStack &S, SElemType e);
Status Pop(SqStack &S, SElemType &e);
Status StackTraverse(SqStack &S, Status(*visit)());
Status visit_stack();


#endif /* SQ_STACK_H_ */
