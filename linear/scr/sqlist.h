/*
 * sqlist.h
 *
 *  Created on: 2017Äê6ÔÂ28ÈÕ
 *      Author: Dick
 */

#ifndef SQLIST_H_
#define SQLIST_H_

#define OK 1
#define OVERFLOW -1
#define LIST_INIT_SIZE 2
#define LISTINCREMENT 10
#define TRUE 1
#define FALSE 0
#define NOTEXIT 0
#define ERROR 0

typedef int Status;
typedef int ElemType;

struct Sqlist{
	ElemType *elem;
	int length;
	int listsize;
};

Status InitList_Sq(struct Sqlist &L);
void DestoryList_Sq(struct Sqlist &L);
void ClearList_Sq(struct Sqlist &L);
Status ListEmpty_Sq(struct Sqlist L);
Status ListLength_Sq(const struct Sqlist &L);
void GetElem_Sq(struct Sqlist L, int i, ElemType &e);
Status compare_equal_Sq(ElemType e1, ElemType e2);
Status LocateElem_Sq(struct Sqlist L, ElemType e, Status (*compare)(ElemType, ElemType));
Status PriorElem_Sq(struct Sqlist L, ElemType cur_e, ElemType &pre_e);
Status NexterElem_Sq(struct Sqlist L, ElemType cur_e, ElemType &next_e);
void ListInsert_Sq(struct Sqlist &L, int i, ElemType e);
void ListDelete_Sq_Sq(struct Sqlist &L, int i, ElemType &e);
Status ListTraverse_Sq(struct Sqlist L, Status (*visit)(ElemType));
Status visit_display_Sq(ElemType e);

void unionList_Sq(struct Sqlist &La, struct Sqlist Lb);
void MergeList_Sq(struct Sqlist La, struct Sqlist Lb, struct Sqlist &Lc);

#endif
