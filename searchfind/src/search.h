/*
 * search.h
 *
 *  Created on: 2017年8月12日
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
//删除二叉搜索树中的一个元素
int DeleteBST(struct node *&bt, int k);
void Delete(struct node *&bt);
void Delete1(struct node *bt, struct node *&r);
int BinSearch(int *R, int low, int hign, int k);



#endif /* SEARCH_H_ */
