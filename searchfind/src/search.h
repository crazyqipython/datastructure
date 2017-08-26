/*
 * search.h
 *
 *  Created on: 2017��8��12��
 *      Author: Dick
 */

#ifndef SEARCH_H_
#define SEARCH_H_

struct node{
	int key;
	int data;
	struct node *lchild, *rchild;
};

struct node *SearchNode(struct node *bt, int k);
bool InsertNode(struct node *bt, struct node N);
//ɾ�������������е�һ��Ԫ��
int DeleteBST(struct node *&bt, int k);
void Delete(struct node *&bt);
void Delete1(struct node *bt, struct node *&r);
int BinSearch(int *R, int low, int hign, int k);



#endif /* SEARCH_H_ */
