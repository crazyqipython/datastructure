#include <stdio.h>
#include <stdlib.h>
#include "queue_maze.h"

////int main(){
//	SqStack S;
//
//	printf("test init stack function...\n");
//	{
//		InitStack(S);
//		printf("\n");
//	}
//
//	printf("test stack empty function...\n");
//	{
//		StackEmpty(S)?printf("S is empty!\n"):printf("s is not empty!\n");
//		printf("\n");
//	}
//
//	printf("test stack length function...\n");
//	{
//		printf("The S of Length is %d\n", StackLength(S));
//		printf("\n");
//	}
//
//	printf("test stack push function...\n");
//	{
//		int i;
//		for(i=1; i<=8; i++){
//			Push(S,2*i);
//		}
//		printf("the S of length is %d\n", StackLength(S));
//		printf("\n");
//	}
//
//	printf("test stack gettop function...\n");
//	{
//		int e;
//		GetTop(S,e);
//		printf("the top of stack element is %d\n", e);
//		printf("\n");
//	}
//
//	printf("test stack pop function....\n");
//	{
//		int e;
//		Pop(S,e);
//		printf("pop top element %d\n", e);
//		printf("the lenght of stack is %d\n", StackLength(S));
//		printf("\n");
//	}
//
//	printf("test stack traverse fuction...\n");
//	{
//		StackTraverse(S,visit_stack);
//		printf("\n\n");
//	}
//
//	printf("test stack clear stack function...\n");
//	{
//		ClearStack(S);
//		StackTraverse(S,visit_stack);
//		printf("the lenght of stack is %d\n", StackLength(S));
//		S.base==NULL?printf("S  destroyed!\n"):printf("S not destroyed\n");
//		printf("\n\n");
//	}
//
//	printf("test destroy function...\n");
//		{
//			DestroyStack(S);
//			S.base==NULL?printf("S  destroyed!\n"):printf("S not destroyed\n");
//			printf("%d ",S.stacksize);
//			printf("\n\n");
//		}
//	printf("hello world!");
//}
//
//void coversion(){
//	SqStack S;
//	InitStack(S);
//	int e;
//	int N;
//	printf("Input: ");
//	scanf("%d",&N);
//	while(N){
//		Push(S,N%8);
//		N = N/8;
//	}
//	while(!StackEmpty(S)){
//		Pop(S,e);
//		printf("%d",e);
//	}
//}


//int main(){
//	CyQueue *Q;
//	int i;
//	printf("test init queue ....\n");
//	{
//		InitQueue(Q);
//		printf("\n");
//	}
//	printf("test empty queue...\n");
//	{
//		QueueEmpty(Q)? printf("queue is empty!\n"):printf("queue is not empty\n");
//		printf("\n");
//	}
//	printf("test insert queue...\n");
//	{
//		for(i=0; i<MaxSize-1;i++){
//			EnQueue(Q,2*i);
//		}
//		QueueEmpty(Q)? printf("queue is empty!\n"):printf("queue is not empty\n");
////		QueueTraverse(Q);
//		printf("\n\n");
//	}
//	printf("test de queue...\n");
//	{
//		DeQueue(Q,i);
//		printf("de queue %d\n",i);
////		QueueTraverse(Q);
//		printf("\n");
//		DeQueue(Q,i);
//		printf("de queue %d\n",i);
////		QueueTraverse(Q);
//	}
//}

int main(){

//	LQueue *q;
//	int i;
//	printf("test init queue ....\n");
//	{
//		InitLinkQueue(q);
//		printf("\n");
//	}
//	printf("test empty queue...\n");
//	{
//		LQueueEmpty(q)? printf("queue is empty!\n"):printf("queue is not empty\n");
//		printf("\n");
//	}
//	printf("test insert queue...\n");
//	{
//		for(i=6; i>0;i--){
//			EnLinkQueue(q,2*i);
//		}
//		LQueueEmpty(q)? printf("queue is empty!\n"):printf("queue is not empty\n");
////		QueueTraverse(Q);
//		printf("\n\n");
//	}
//	printf("test de queue...\n");
//	{
//		DeLinkQueue(q,i);
//		printf("de queue %d\n",i);
////		QueueTraverse(Q);
//		printf("\n");
//		DeLinkQueue(q,i);
//		printf("de queue %d\n",i);
////		QueueTraverse(Q);
//	}
//	printf("test destroy queue...\n");
//		{
//			DestroyLinkQueue(q);
////			printf("de queue %d\n",i);
//	//		QueueTraverse(Q);
//			printf("\n");
//			LQueueEmpty(q)? printf("queue is empty!\n"):printf("queue is not empty\n");
////			DeLinkQueue(q,i);
////			printf("de queue %d\n",i);
//	//		QueueTraverse(Q);
//			DeLinkQueue(q,i);
//			printf("de queue %d\n",i);
//		}
	if(!mgpath1(1,1,8,8)){
		printf("√‘π¨ŒﬁΩ‚");
	}

}
