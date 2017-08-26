/*
 * link_list2.cpp
 *
 *  Created on: 2017年7月4日
 *      Author: Dick
 */
#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"
#include "link_list2.h"

Status MakeNode(Link &p, ElemType e){
	p = (Link)malloc(sizeof(LNode2));
	if(!p)
		exit(OVERFLOW);
	p->data =e;
	p->next = NULL;
	return OK;
}

void FreeNode(Link &p){
	free(p);
	p->next = NULL;
}

Status InitList(LinkList &L){
	Link p;
	p = (Link)malloc(sizeof(LNode2));
	if(!p)
		exit(OVERFLOW);
	p->next = NULL;
	L.len = 0;
	L.head = L.tail = p;
	return OK;
}

Status ClearList(LinkList &L){
	Link p,q;
	p=L.head->next;
	L.head->next =NULL;
	while(p){
		q = p->next;
		free(p);
		p=q;
	}
	L.tail = L.head;
	L.len =0;
	return OK;
}

Status DestroyList(LinkList &L){
	ClearList(L);
	free(L.head);
	L.head = L.tail = NULL;
	L.len=0;
	return OK;
}

Status InsFirst(Link h, Link s){
	s->next = h->next;
	h->next = s;
	return OK;
}

Status DelFirst(Link h, Link &q){
	if(h->next == NULL)
		return ERROR;
	q = h->next;
	h->next = q->next;
	q->next = NULL;
	return OK;
}

Status Append(LinkList &L, Link s){
	Link p;
	L.tail->next = s;
	int i=1;
	while(NULL!=s->next){
		s =s->next;
		i++;
	}
	L.len += i;
	L.tail =s;
	return OK;
}

Status Remove(LinkList &L, Link &q){
	Link p;
	p = L.head->next;
	while(p->next!=L.tail){
		p = p->next;
	}
	q=L.tail;
	free(L.tail);
	L.tail=p;
	L.len--;
	return OK;
}

Status InsBefore(LinkList &L, Link &p, Link s){
	Link q;
	q = L.head->next;
	while(q->next!=p){
		q = q->next;
	}
	q->next = s;
	s->next = p;
	L.len++;
	return OK;
}

Status InsAfter(LinkList &L, Link &p, Link s){
	s->next = p->next;
	p->next = s;
	L.len++;
	return OK;
}

Status SetCurElem(Link &p, ElemType e){
	p->data =e;
	return OK;
}

ElemType GetCurElem(Link p){
	int e;
	e = p->data;
	return e;
}

Status ListEmpty(LinkList L){
	if(L.head->next == NULL)
		return TRUE;
	else
		return FALSE;
}

int ListLength(LinkList L){
	return L.len;
}

Position GetHead(LinkList L){
	return L.head->next;
}

Position GetLast(LinkList L){
	return L.tail;
}

Position PriorPos(LinkList L, Link p){
	Link q = L.head->next;
	if(p == L.head->next)
		return NULL;
	while(q->next != p){
		q = q->next;
	}
	return q;
}

Position NextPos(LinkList L, Link p){
	return p->next;
}

Status LocatePos(LinkList L, int i, Link &p){
	if(i<0 || i>L.len)
		return ERROR;
	p = L.head;
	while(i!=0){
		p = p->next;
		i--;
	}
	return 1;
}

Position LocateElem(LinkList L, ElemType e,
			 int (*compare)(ElemType, ElemType)){
	Link p;
	p = (Link)malloc(sizeof(struct LNode2));
	if(!p)
		exit(OVERFLOW);
	p = L.head->next;
	while(p){
		if(compare(p->data, e))
			return p;
		p = p->next;
	}
	return p;
}


Status ListTraverse(LinkList L,void (*visit)(Link)){
	Link p;
	p = L.head->next;
	while(p!=NULL){
		visit(p);
		p=p->next;
	}
	return OK;
}

void visit_display(Link p){
	printf("%d ", p->data);
}

Status ListInsert(LinkList &L, int i, ElemType e){
//	Link p,q;
//	int j=1;
//	p = (Link)malloc(sizeof(struct LNode2));
//	if(!p){
//		exit(OVERFLOW);
//	}
//	p->data=e;
//	q=L.head;
//	if(i<1 || i>L.len)
//		return ERROR;
//	while(p&&j<i){
//		q = q->next;
//		j++;
//	}
//	p->next = q->next;
//	q->next = p;
//	L.len++;
//	return OK;
	Link h, s;
	if (!LocatePos(L, i-1, h))
		return ERROR;
	if (!MakeNode(s, e))
		return ERROR;
	if (h == L.tail)
		L.tail = s;   // 修改尾指针
	InsFirst(h, s);       //对于从第不个结点开始的链表，第i-1个结点是它的头结点
	L.len++;
	return OK;
}

Status ListDelete(LinkList L, int i, ElemType &e){
	Link h,s;
	if(i<1 && i>L.len)
		return ERROR;
	if(!LocatePos(L,i-1,h))
		return ERROR;
	e = s->data;
	free(s);
	s = NULL;
	return OK;
}

Status MergeList(LinkList &La, LinkList &Lb, LinkList &Lc,
				int (*compare)(ElemType, ElemType)){
	Link p,q;
	p = La.head->next;
	q = Lb.head->next;
	while(p && q){
		if(compare(p->data,q->data)){
			Append(Lc,q);
			q = q->next;
		}
		else{
			Append(Lc,p);
		}
	}
	if(p){
		Append(Lc,p);
	}
	if(q){
		Append(Lc,q);
	}
	return OK;
}

int compare(ElemType e1, ElemType e2){
	if(e1>e2)
		return TRUE;
	else
		return FALSE;
}
