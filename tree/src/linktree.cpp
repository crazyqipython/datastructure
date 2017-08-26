#include "linktree.h"
#include <stdlib.h>
#include <stdio.h>

void CreateBTNode(node *&b,char *str){
	node *St[MaxSize], *p;
	int top=-1,k,j=0;
	char ch;
	b=NULL;
	ch=str[j];

	while(ch!='\0'){
		switch(ch){
			case '(':
				top++; St[top]=p;
				k=1; break;
			case ')':
				top--;
				break;
			case ',':
				k=2;
				break;
			default:
				p = (node *)malloc(sizeof(node));
				p->data=ch;
				p->lchild = p->rchild = NULL;
				if(b==NULL){
					b = p;
				}
				else{
					switch(k){
						case 1:
							St[top]->lchild = p;
							break;
						case 2:
							St[top]->rchild = p;
							break;
				}
		}
	}
		j++;
		ch=str[j];
}
}


void DestoryBTNode(node *&b){
	if(b!=NULL){
		DestoryBTNode(b->lchild);
		DestoryBTNode(b->rchild);
		free(b);
	}
}

node *FindNode(node *b, ElemType &x){
	node *p;
	if(b==NULL){
		p=NULL;
		return p;
	}
	if(b->data==x){
		p=b;
		return p;
	}else{
		p=FindNode(b->lchild, x);
		if(p==NULL){
			p =FindNode(b->rchild,x);
		}
		return p;
	}
}

int BTNodeHeight(node *b){
	int hl, hr;
	if(b==NULL){
		return 0;
	}
	else{
		hl=BTNodeHeight(b->lchild);
		hr=BTNodeHeight(b->rchild);
		if(hl>hr)
			return hl+1;
		else
			return hr+1;
	}
}

node* LchildNode(node *p){
	return p->lchild;
}

void DisplayBTNode(node*b){
	if(b==NULL)
		return;
	else{
		printf("%c ", b->data);
		if(b->lchild!=NULL||b->rchild!=NULL){
			printf("(");
			DisplayBTNode(b->lchild);
			if(b->rchild){
						printf(",");
						DisplayBTNode(b->rchild);

					}
			printf(")");
		}

	}
}

void PreOrder(node *b){
	if(b==NULL){
		return;
	}
	else{
		printf("%c ", b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}

void MidOrder(node *b){
	if(b==NULL)
		return;
	else{
		MidOrder(b->lchild);
		printf("%c ", b->data);
		MidOrder(b->rchild);
	}
}

void PostOrder(node *b){
	if(b!=NULL){
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c ",b->data);
	}
}

void LevelOrder(node *b){
	node *p;
	node *qu[MaxSize];
	int front,rear;
	front=rear=0;
	rear++;
	qu[rear] = b;
	while(front!=rear){
		front = (front+1)%MaxSize;
		p = qu[front];
		printf("%c ", p->data);
		if(p->lchild !=NULL){
			rear = (rear+1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if(p->rchild!=NULL){
			rear =(rear+1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
}


node *CreateBT(char *pre, char *in, int n){
	node *s;
	char *p;
	int k;
	if(n<=0)return NULL;
	s = (node *)malloc(sizeof(node));
	s->data = *pre;
	for(p=in; p<in+n; p++){
		if(*p==*pre)
			break;
	}
	k=p-in;
	s->lchild = CreateBT(pre+1, in, k);
	s->rchild = CreateBT(pre+k+1, p+1, n-k-1);
	return s;
}

int CountNodes(node *b){
	if(b==NULL){
		return 0;
	}
	else{
		return CountNodes(b->lchild) + CountNodes(b->rchild) + 1;
	}
}

int LeafNodes(node *b){
	if(b==NULL){
		return 0;
	}
	else if(b->lchild==NULL && b->rchild==NULL){
		return 1;
	}
	else{
		return LeafNodes(b->lchild) + LeafNodes(b->rchild);
	}
}

void Copy(node *b, node *&t){
	t = (node *)malloc(sizeof(node));
	if(b==NULL){
		t=NULL;
	}else{
		t->data=b->data;
		Copy(b->lchild, t->lchild);
		Copy(b->rchild,t->rchild);
	}
}

int Level(node *b, ElemType x, int h){
	int l;
	if(b==NULL){
		return 0;
	}else if(b->data==x){
		return h;
	}else{
		l = Level(b->lchild, x, h+1);
		if(l==0){
			return Level(b->rchild, x, h+1);
		}
		return l;
	}
}

void AllPath(node *b){
	struct snode{
		node *n;
		int parent;
	}qu[MaxSize];
	node *q;
	int front,rear,p;
	front=rear=-1;
	rear=-1;
	qu[rear].n=b;
	qu[rear].parent = -1;

	while(front!=rear){
		front++;
		q=qu[front].n;
		if(q->lchild==NULL&&q->rchild==NULL){
			p=front;
			while(qu[p].parent !=-1){
				printf("%c->",qu[p].n->data);
				p=qu[p].parent;
			}
			printf("%c->", qu[p].n->data);
		}
		if(q->lchild!=NULL){
			rear++;
			qu[rear].n = q->lchild;
			qu[rear].parent = front;
		}
		if(q->rchild != NULL){
			rear++;
			qu[rear].n = q->rchild;
			qu[rear].parent = front;
		}
	}
}

node *CreateBT1(char *post, char *in, int n){
	node *s;
	char *p;
	int k;
	if(n<=0)return NULL;
	s = (node *)malloc(sizeof(node));
	s->data = *(post + n - 1);
	for(p=in; p<=in+n-1;p++){
		if(*p==*(post + n -1))
			break;
	}
	k=p-in;
	s->lchild = CreateBT1(post,in,k);
	s->rchild = CreateBT1(post+k,p+1,n-k-1);
	return s;

}

void trans2(node *b, SqBTree a, int i){
	if(b!=NULL){
		a[i] = b->data;
		trans2(b->lchild, a, 2*i);
		trans2(b->rchild, a, 2*i+1);
	}
}

int dnodes(node *b){
	if(b==NULL){
		return 0;
	}
	if(b->lchild && b->rchild){
		return dnodes(b->lchild) + dnodes(b->rchild) + 1;
	}else{
		return dnodes(b->lchild) + dnodes(b->rchild);
	}
}

void knumber(node *b,int h, int k, int &n){
	if(b==NULL){
		return;
	}
	if(h==k){
		n++;
	}
	else{
		knumber(b->lchild,h+1,k,n);
		knumber(b->rchild,h+1,k,n);
	}
}

void levelnumber(node *b, int h, int a[]){
	if(b==NULL){
		return;
	}
	else
	{
		a[h]++;
		levelnumber(b->lchild, h+1, a);
		levelnumber(b->rchild, h+1, a);
	}
}

int BTWidth2(node *b){
	struct{
		int lno;
		node *p;
	}qu[MaxSize];
	int front,rear;
	int lnum, width, i, n;
	front = rear = 0;
	if(b!=NULL){
		rear++;
		qu[rear].p = b;
		qu[rear].lno = 1;
		while(rear!=front){
			front++;
			b = qu[front].p;
			lnum = qu[front].lno;
			if(b->lchild !=NULL){
				rear++;
				qu[rear].p = b->lchild;
				qu[rear].lno = lnum+1;
			}
			if(b->rchild !=NULL){
				rear++;
				qu[rear].p = b->rchild;
				qu[rear].lno = lnum +1;
			}
		}
	width = 0; lnum=1; i=1;
	while(i<=rear){
		n = 0;
		while(i<=rear&&qu[i].lno==lnum){
			n++;
			i++;
		}
		lnum = qu[i].lno;
		if(n>width) width=n;
	}
	return width;
 }
	else return 0;
}
