/*
 * sqlist.cpp
 *
 *  Created on: 2017Äê6ÔÂ28ÈÕ
 *      Author: Dick
 */

#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

Status InitList_Sq(struct Sqlist &L) {
	L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

void DestoryList_Sq(struct Sqlist &L) {
	free(L.elem);
	L.elem = NULL;
}

Status ListLength_Sq(const struct Sqlist &L) {
	return L.length;
}

Status ListEmpty_Sq(struct Sqlist L) {
	if (0 == L.length) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void GetElem_Sq(struct Sqlist L, int i, ElemType &e) {
	e = *(L.elem + i - 1);
}

Status compare_equal_Sq(ElemType e1, ElemType e2) {
	if (e1 == e2) {
		return TRUE;
	} else
		return FALSE;
}

Status LocateElem_Sq(struct Sqlist L, ElemType e,
		Status (*compare)(ElemType, ElemType)) {
	ElemType * p = L.elem;
	int i;
	for (i = 1; i <= L.length; i++) {
		if (compare(e, *(p + i - 1)))
			return i;
	}
	return 0;
}

Status PriorElem_Sq(struct Sqlist L, ElemType cur_e, ElemType &pre_e) {
	int pos;
	pos = LocateElem_Sq(L, cur_e, compare_equal_Sq);
	if (!pos || 1 == pos)
		return NOTEXIT;
	else
		return *(L.elem + pos - 2);

}

Status NexterElem_Sq(struct Sqlist L, ElemType cur_e, ElemType &next_e) {
	int pos;
	pos = LocateElem_Sq(L, cur_e, compare_equal_Sq);
	if (!pos || pos == L.length)
		return NOTEXIT;
	else
		return *(L.elem + pos);
}

void ListInsert_Sq(struct Sqlist &L, int i, ElemType e) {
	int j;
	ElemType * newbase;
	if (L.length + 1 > L.listsize) {
		newbase = (ElemType *) malloc(LISTINCREMENT * sizeof(ElemType));
		if (!newbase) {
			exit(OVERFLOW);
		}
		L.listsize += LISTINCREMENT;
	}
	for (j = L.length; j >= i; j--) {
		*(L.elem + j) = *(L.elem + j - 1);
	}
	*(L.elem + i - 1) = e;
	L.length++;
}

void ListDelete_Sq_Sq(struct Sqlist &L, int i, ElemType &e) {
	int j;
	e = *(L.elem + i - 1);
	for (j = i; j < L.length; j++) {
		*(L.elem + j - 1) = *(L.elem + j);
	}
	L.length--;
}

void ClearList_Sq(struct Sqlist &L){
	L.length = 0;
}

Status ListTraverse_Sq(struct Sqlist L, Status (*visit)(ElemType)) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (!visit(*(L.elem + i)))
			return FALSE;
	}
	return TRUE;
}

Status visit_display_Sq(ElemType e) {
	printf("%d\n", e);
	return TRUE;
}

void unionList_Sq(struct Sqlist &La, struct Sqlist Lb) {
	int i;
	ElemType e;
	int La_len = ListLength_Sq(La);
	for (i = 1; i < Lb.length; i++) {
		GetElem_Sq(Lb, i, e);
		if (!LocateElem_Sq(La, e, compare_equal_Sq))
			ListInsert_Sq(La, ++La_len, e);
	}
}

void MergeList_Sq(struct Sqlist La, struct Sqlist Lb, struct Sqlist &Lc) {
	InitList_Sq(Lc);
	int i = 1, j = 1, k = 1;
	ElemType a, b;
	int La_len = La.length;
	int Lb_len = Lb.length;
	while (i < La_len && j < Lb_len) {
		GetElem_Sq(La, i, a);
		GetElem_Sq(Lb, j, b);
		if (a > b) {
			ListInsert_Sq(Lc, k++, b);
			j++;
		} else {
			ListInsert_Sq(Lc, k++, a);
			i++;
		}
	}
	while (i <= La_len) {
		GetElem_Sq(La, i++, a);
		ListInsert_Sq(Lc, k++, a);
	}
	while (j <= Lb_len) {
		GetElem_Sq(Lb, j++, b);
		ListInsert_Sq(Lc, k++, b);
	}
}
