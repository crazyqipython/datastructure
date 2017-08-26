/*
 * double_link.cpp
 *
 *  Created on: 2017Äê7ÔÂ3ÈÕ
 *      Author: Dick
 */
#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
#include "double_link.h"

void InitList_D(struct DNode * &D) {
	D = (struct DNode *) malloc(sizeof(struct DNode));
	if (!D) {
		exit(OVERFLOW);
	}
	D->next = D;
	D->prior = D;
}

void Destory_D(struct DNode * &D) {
	free(D);
	D->next = NULL;
}

void ClearList_D(struct DNode * &D) {
	D->next = NULL;
}

bool ListEmpty_D(struct DNode * &D) {
	if(D && D->next==D && D->prior == D)
		return TRUE;
	else
		return FALSE;
}

int ListLength_D(struct DNode * &D) {
	struct DNode *p;
	int count = 0;
	if(D){
		p=D;
		while(p->next !=D){
			count++;
			p=p->next;
		}
	}
	return count;
}

Status GetElem_D(struct DNode * &D, int i, ElemType &e) {
	struct DNode *p = D->next;
	int j=0;
	while (p && j < i) {
		j++;
		p = p->next;
	}
	if (p == NULL || j > i)
		return FALSE;
	e = p->data;
	return OK;
}

int LocateElem_D(struct DNode * &D, ElemType e,
		Status (*compare)(ElemType, ElemType)) {
	struct DNode *p = D->next;
	int i = 0;
	while (p != NULL) {
		i++;
		if (compare(p->data, e)) {
			return i;
		}
		p = p->next;
	}
	return FALSE;
}

struct DNode* GetElem_Dul(struct DNode *&D, int i) {

	int count;
	struct DNode *p;
	if (D && i > 0) {
		count = 1;
		p = D->next;
		while (p != D && count < i) {
			count++;
			p = p->next;
		}
		if (p != D)
			return p;
	}
	return NULL;
}
//	while (p != NULL && j < i-1) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL || j > i-1)
//		return ERROR;
//	N = (struct DNode *) malloc(sizeof(struct DNode));
//	if (!N)
//		return ERROR;
//	N->data = e;
//	N->prior = p;
//	if(p->next!=NULL)
//		p->next->prior = N;

Status ListInsert_D(struct DNode * &D, int i, ElemType e) {
//	struct DNode *N, *p = D;
//	int j=0;
//	while (p != NULL && j < i-1) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL || j > i-1)
//		return ERROR;
//	N = (struct DNode *) malloc(sizeof(struct DNode));
//	if (!N)
//		return ERROR;
//	N->data = e;
//	N->prior = p;
//	if(p->next!=NULL)
//		p->next->prior = N;
//
//	p->next = N;
//	return OK;
	struct DNode *p, *s;
	if (i < 1 || i > ListLength_D(D) + 1)
		return ERROR;
	p = GetElem_Dul(D, i);
	if (!p)
		p = D;
	s = (struct DNode *) malloc(sizeof(struct DNode));
	if (!s)
		exit(OVERFLOW);
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}

Status ListDelete_D(struct DNode * &D, int i, ElemType &e) {
//	struct DNode *p = D;
//	struct DNode *del_p;
//	int j = 0;
//	while (p && j < i) {
//		j++;
//		p = p->next;
//	}
//	if (p == NULL || j > i)
//		return ERROR;
//	del_p = p->next;
//	del_p->next->prior = del_p->prior;
//	del_p->prior->next = del_p->next;
//	e = del_p->data;
//	free(del_p);
//	del_p->next = NULL;
//	del_p->prior = NULL;
//	return OK;
	struct DNode *p;
	p = GetElem_Dul(D,i);
	if(!p)
		return ERROR;
	e=p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	p=NULL;
	return OK;
}

Status ListTraverse_D(struct DNode * &D, Status (*visit)(struct DNode * &)) {
	struct DNode *p = D->next;
	while (p != D) {
		if (!visit(p))
			return ERROR;
		p = p->next;
	}
	return OK;
}

Status visit_display_D(struct DNode * &D) {
	printf("%d ", D->data);
	return OK;
}
