#include <stdio.h>
#include <stdlib.h>
#include "linktree.h"

//typedef struct TreeNode{
//	int data;
//	struct TreeNode *left;
//	struct TreeNode *right;
//}Tree;
//
//void destroy_tree(Tree *&T){
//	if(T==NULL){
//		printf("destroy");
//	}
//	else{
//		destroy_tree(T->left);
//		destroy_tree(T->right);
//		free(T);
//	}
//}
//
//bool find_node(Tree *&T,int x){
//	if(T==NULL){
//		return false;
//	}
//	if(T->data==x){
//		return true;
//	}
//	else{
//		if(find_node(T->left, x)){
//			return true;
//		}
//		else if(find_node(T->right,x)){
//			return true;
//		}
//		return false;
//	}
//}
//
//int tree_height(Tree *&T){
//	if(T==NULL){
//		return 0;
//	}
////	if(T->left==NULL&& T->right==NULL){
////		return 1;
////	}
//	else{
//		int h1, h2;
//		h1 = tree_height(T->left);
//		h2 = tree_height(T->right);
//		return (h1>h2?h1+1:h2+1);
//	}
//}

int main(){
	node *b;
	SqBTree sq;
	int sh[6] ={0,0,0,0,0,0};
	int i=0;
	char t[] = {'A','(', 'B', '(', 'D', '(',',', 'G', ')', ')', ',', 'C', '(', 'E', ',', 'F', ')', ')','\0'};
	CreateBTNode(b,t);
////	printf("%c\n",b->rchild->data);
//	p=FindNode(b, x);
//	printf("height is %d\n", BTNodeHeight(b));
//
//	printf("%c\n",p->data);
//
	DisplayBTNode(b);
//	printf("\n");
//	PreOrder(b);
//	printf("\n");
//	MidOrder(b);
//	printf("\n");
//	PostOrder(b);
//	printf("\n");
//	LevelOrder(b);
//	printf("%d",CountNodes(b));
//	printf("\n");
//	printf("%d ",LeafNodes(b));
//	printf("\n");
//	Copy(b,q);
//	DisplayBTNode(q);
//	printf("\nafasdf ");
//	AllPath(b);
	//先序中序构造树
//	char pre[7] = {'A','B','D','G','C','E','F'};
//	char post[7] = {'G','D','B','E','F','C','A'};
//	char in[] = {'D','G','B','A','E','C','F'};
//	printf(" %d",sizeof(in));
//	printf("size of %d ", sizeof(pre));
//	p = CreateBT1(post,in,7);
//	DisplayBTNode(p);
//	trans2(b, sq, 1);
	printf("%d ", dnodes(b));
	printf("\n");
	knumber(b, 1, 3,i);
	printf("%d \n", i);
	levelnumber(b, 1, sh);
	printf("%d \n",sizeof(sh));
	for(i=0; i<6; i++){
		printf("%d ", sh[i]);
	}

}
