
#ifndef LINKTREE_H_
#define LINKTREE_H_
#define ElemType char
#define MaxSize 20

struct node{
	ElemType data;
	struct node *lchild, *rchild;
};

typedef  char SqBTree[MaxSize];


void CreateBTNode(node *&b,char *str);
void DestoryBTNode(node *&b);
node *FindNode(node *b, ElemType &x);
int BTNodeHeight(node *b);
node * LchildNode(node*p);
void DisplayBTNode(node *b);
//先序遍历
void PreOrder(node *b);
void MidOrder(node *b);
void PostOrder(node *b);
void LevelOrder(node *b);
//applications
int CountNodes(node *b);
int LeafNodes(node *b);
void Copy(node *b, node *&t);
int Level(node *b, ElemType x, int h);

//由先序中序构造二叉树
node *CreateBT(char *pre, char *in, int n);
node *CreateBT1(char *post, char *in, int n);

//顺序遍历
void AllPath(node *b);

//二叉链和顺序的转换
void trans2(node *b, SqBTree a, int i);
//void trans1(SqBTree a, int i);

int dnodes(node *b);
void knumber(node*b, int h, int k, int &n);
void levelnumber(node *b, int h, int a[]);
int BTWidth2(node *b);

#endif /* LINKTREE_H_ */
