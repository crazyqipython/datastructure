/*
 * avl.h
 *
 *  Created on: 2017Äê8ÔÂ12ÈÕ
 *
 */

#ifndef AVL_H_
#define AVL_H_

struct Node{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

struct Node *insert(struct Node *node, int key);

//get maximum of two integers
int max(int a, int b);

//a utility function to get height of the tree
int height(struct Node *node);

//a helper function to create a node
struct Node* newNode(int key);

//a function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y);

//a function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x);

//get balance factor of node N
int getBalance(struct Node *N);

void preOrder(struct Node *root);


#endif /* AVL_H_ */
