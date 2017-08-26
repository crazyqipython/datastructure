#include <stdio.h>
#include <stdlib.h>
#include "sq_stack.h"

Status InitStack(SqStack &S){
	S.base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		return ERROR;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestroyStack(SqStack &S){
	free(S.base);
	S.base = NULL;
	S.stacksize = 0;
	return OK;
}

Status ClearStack(SqStack &S){
	S.top = S.base;
	return OK;
}

Status StackEmpty(SqStack &S){
	return S.top == S.base;
}

int StackLength(SqStack &S){
	return (S.top - S.base);
}

Status GetTop(SqStack &S, SElemType &e){
	if(StackEmpty(S))
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e){
	if(StackLength(S)>=S.stacksize){
		S.base = (SElemType *) realloc (S.base, (S.stacksize + StACKINCREMENT)*sizeof(SElemType));
		if (!S.base)
			return ERROR;
		S.stacksize += StACKINCREMENT;
	}
	*(S.top) = e;
	S.top++;
	S.stacksize += StACKINCREMENT;
	return OK;
}

Status Pop(SqStack &S, SElemType &e){
	if(StackEmpty(S))
		return ERROR;
	e = *(S.top - 1);
	S.top--;
	return OK;
}

Status StackTraverse(SqStack &S, Status(*visit)()){
	while(S.base<S.top){
		if(!visit())
			return ERROR;
		printf("%d ", *(S.base));
		S.base++;
	}
	return OK;
}

Status visit_stack(){
	return OK;
}
