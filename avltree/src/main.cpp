#include <stdio.h>
#include "avl.h"

int main(){
	struct Node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	printf("Preorder traversal of the constructed AVL"
	         " tree is \n");
	preOrder(root);
	return 0;
}
