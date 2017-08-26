/*
 * double_link.h
 *
 *  Created on: 2017Äê7ÔÂ3ÈÕ
 *      Author: Dick
 */

#ifndef DOUBLE_LINK_H_
#define DOUBLE_LINK_H_

struct DNode{
	ElemType data;
	struct DNode *next;
	struct DNode *prior;
};

void InitList_D(struct DNode * &D);
void Destory_D(struct DNode * &D);
void ClearList_D(struct DNode * &D);
bool ListEmpty_D(struct DNode * &D);
int ListLength_D(struct DNode * &D);
Status GetElem_D(struct DNode * &D, int i, ElemType &e);
int LocateElem_D(struct DNode * &D, ElemType e, Status (*compare)(ElemType, ElemType));
Status PriorElem_D(struct DNode * &D, ElemType cur_e, ElemType &pre_e);
Status NextElem_D(struct DNode * &D, ElemType cur_e, ElemType &next_e);
Status ListInsert_D(struct DNode * &D, int i, ElemType e);
Status ListDelete_D(struct DNode * &D, int i, ElemType &e);
Status ListTraverse_D(struct DNode * &D, Status (*visit)(struct DNode * &));
Status visit_display_D(struct DNode * &D);
struct DNode* GetElem_Dul(struct DNode *&D, int i);




#endif /* DOUBLE_LINK_H_ */
