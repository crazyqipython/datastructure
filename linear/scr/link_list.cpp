#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
#include "link_list.h"

void InitList_L(struct LNode * &L) {
	L = (struct LNode *) malloc(sizeof(LNode));
	L->next = NULL;
}

void Destory_L(struct LNode * &L) {
	free(L);
	L = NULL;
}

void ClearList_L(struct LNode * &L) {
	L->next = NULL;
}

bool ListEmpty_L(struct LNode * &L) {
	return L->next == NULL;
}

int ListLength_L(struct LNode * &L) {
	int len = 0;
	struct LNode *p = L->next;
	while (p) {
		len++;
		p = p->next;
	}
	return len;
}

Status GetElem_L(struct LNode * &L, int i, ElemType &e) {
	struct LNode *p = L->next;
	int j = 1;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	if (p == NULL || j > i)
		return FALSE;
	e = p->data;
	return OK;
}

int LocateElem_L(struct LNode * &L, ElemType e,
		Status (*compare)(ElemType, ElemType)) {
	struct LNode *p = L->next;
	int i = 0;
	while (p) {
		i++;
		if (compare(p->data, e))
			return i;
		p = p->next;
	}
	return 0;
}

Status PriorElem_L(struct LNode * &L, ElemType cur_e, ElemType &pre_e) {
	struct LNode *p = L->next;
	int i = 0;
	while (NULL != p) {
		i = LocateElem_L(L, cur_e, compare_equal_Sq);
		if (0 != i && 1 != i) {
			GetElem_L(L, i - 1, pre_e);
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

Status NextElem_L(struct LNode * &L, ElemType cur_e, ElemType &next_e) {
	struct LNode *p = L->next;
	int i = 0;
	while (p) {
		i = LocateElem_L(L, cur_e, compare_equal_Sq);
		if (i<ListLength_L(L)) {
			GetElem_L(L, i+1, next_e);
			return OK;
		}
		p = p->next;
	}
	return ERROR;
}

Status ListInsert_L(struct LNode * &L, int i, ElemType e){
	struct LNode *newnode;
	struct LNode *p = L;
	int j=0;
	//look up pos
	while(p && j<i-1){
		j++;
		p = p->next;
	}
	if(p==NULL || j>i-1)
		return FALSE;
	newnode = (struct LNode *)malloc(sizeof(LNode));
	newnode->data = e;
	newnode->next = p->next;
	p->next = newnode;
	return OK;
}

Status ListDelete_L(struct LNode * &L, int i, ElemType &e){
	struct LNode *p = L;
	struct LNode *del_p;
	int j = 0;
	while(p->next !=NULL && j<i-1){
		j++;
		p = p->next;
	}
	if(p->next == NULL || j>i-1)
		return ERROR;
	del_p = p->next;
	p->next = del_p->next;
	e = del_p ->data;
	free(del_p);
	del_p=NULL;
	return OK;
}

Status ListTraverse_L(struct LNode * &L, Status (*visit)(struct LNode * &)){
	struct LNode *p = L->next;
	while(p){
		if(ERROR == visit(p))
			return ERROR;
		p = p->next;
	}
	return OK;
}

Status visit_display_L(struct LNode * &L){
	printf("%d\n", L->data);
	return OK;
}

void MergeList_L(struct LNode * &La, struct LNode * &Lb, struct LNode * &Lc){
	struct LNode * pa = La->next;
	struct LNode * pb = Lb->next;
	struct LNode * pc = Lc = La;
	while(!pa && !pb){
		if(pa->data<pb->data){
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
		else{
			pc->next = pb;
			pc = pc->next;
			pb = pb->next;
		}
	}
	if(NULL == pa){
		pc->next = pb;
	}
	else
		pc->next = pa;
	free(pb);
	Lb = NULL;
}
