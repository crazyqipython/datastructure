/*
 * search.cpp
 *
 *  Created on: 2017Äê8ÔÂ12ÈÕ
 *      Author: Dick
 */

#include <stdio.h>
#include <stdlib.h>

int BinSearch(int *R, int low, int hign, int k){
	int mid = (low + hign)/2;
	if(low >= hign){
		return 0;
	}
	if(R[mid] == k){
		return mid;
	}
	if(k > R[mid]){
		 return BinSearch(R, mid + 1, hign, k);
	}
	if(k < R[mid]){
		return BinSearch(R, low + 1, mid, k);
	}
}

struct node *SearchNode(struct node *bt, int k){
	if(bt==NULL || bt->key == k){
		return bt;
	}
	if(k > bt->key){
		return SearchNode(bt->rchild,  k);
	}
	if(k < bt->key){
		return SearchNode(bt->lchild,  k);
	}
}

bool InsertNode(struct node *bt, struct node N){
	if(bt == NULL){
		bt = N;
		return true;
	}
	if(bt->key > N.key){
		return InsertNode(bt->lchild, N);
	}
	if(bt->key < N.key){
		return InsertNode(bt->rchild, N);
	}
}

int DeleteBST(struct node *&bt, int k){
	if(bt == NULL){
		return 0;
	}
	if(k > bt->key){
		return DeleteBST(bt->rchild, k);
	}else if(k < bt->key){
		return DeleteBST(bt->lchild, k);
	}else{
		Delete(bt);
		return 0;
	}
}

void Delete(struct node *&bt){
	struct node *q;
	if(bt->rchild == NULL && bt->lchild == NULL){
		free(bt);
	}
	if(bt->rchild == NULL){
		q = bt;
		bt = bt->lchild;
		free(q);
	}else if(bt->lchild == NULL){
		q = bt;
		bt = bt->rchild;
		free(q);
	}else{
		Delete1(bt, bt->lchild);
	}
}

void Delete1(struct node *bt, struct node *&r){
	struct node *q;
	if(r->rchild != NULL){
		Delete1(bt, r->rchild);
	}else{
		bt->key = r->key;
		bt->data = r->data;
		q = r;
		r = r->lchild;
		free(q);
	}
}
