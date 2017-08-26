/*
 * main.cpp
 *
 *  Created on: 2017年6月28日
 *      Author: Dick
 */
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "sqlist.h"
#include "link_list2.h"
#include <iostream>
using namespace std;

//template<class T>
//T sum(T val) {
//	return val;
//}
//
//struct stuff {
//	char job[20];
//	int age;
//	float height;
//} Huqinwei;
//int m_value = 1;
//void func(int *&p) {
//	*p = m_value;
//
//}

//int main() {
/* sequence list
 int i;
 struct Sqlist l,l1,l2;
 ElemType e;
 InitList_Sq(l);
 printf("aaa  %d\n", ListEmpty_Sq(l));
 for(i=1;i<10;i++){
 ListInsert_Sq(l,i,i-1);
 }
 printf("size%d\n",l.listsize);
 printf("sie%d\n",l.length);
 printf("%d\n",l.length);
 printf("%d\n", ListEmpty_Sq(l));
 ListTraverse_Sq(l,visit_display_Sq);
 GetElem_Sq(l,4,e);
 printf("%d", e);
 //	printf("%d\n",LocateElem_Sq(l,7,compare_equal_Sq));
 ListInsert_Sq(l,13,e);
 printf("%d\n",l.listsize);
 printf("%d\n",l.length);
 //	ListTraverse_Sq(l,visit_display_Sq);
 ListDelete_Sq_Sq(l,8,e);
 ListTraverse_Sq(l,visit_display_Sq);
 printf("%d",e);
 printf("hello");
 InitList_Sq(l1);
 for(i=20;i<=25;i++){
 int b;
 b=i-19;
 ListInsert_Sq(l1,b,i-1);
 }
 //	ListTraverse_Sq(l1,visit_display_Sq);
 //	DestoryList_Sq(l);
 //	printf("size%d\n",l.listsize);
 //	printf("sie%d\n",l.length);
 //	unionList_Sq(l,l1);
 //	ListTraverse_Sq(l,visit_display_Sq);
 InitList_Sq(l2);
 MergeList_Sq(l, l1, l2);
 ListTraverse_Sq(l2,visit_display_Sq);
 DestoryList_Sq(l2);
 printf("sie%d\n",l.length);
 //return 0;
 */

//reference
//	struct stuff &t1 = test;
//	printf("%d\n",t1.age);
//	t1.age=27;
//	printf("t1 %d\n",t1.age);
//	printf("test %d\n", t1.age);
////pointer
//	struct stuff *t2 = &test;
//	printf("job %s\n", t2->job);
//	t2->job[0] = 's';
//	t2->job[1] = 't';
//	t2->job[2] = 'u';
//	t2->job[3] = '\0';
//	printf("job t2 %s \n", t2->job);
//	printf("job test %s \n", test.job);
//	struct LNode *t;
//	int l,e;
//	bool b;
//	InitList_L(t);
//	b = ListEmpty_L(t);
//	l = ListLength_L(t);
//	printf("%d\n",b);
//	printf("%d\n",l);
//	b =ListInsert_L(t, 1, 11);
//	printf("%d\n", b);
//	ListInsert_L(t,2,14);
//	ListInsert_L(t,2,20);
//	printf("length %d\n", ListLength_L(t));
//	ListInsert_L(t,2,33);
//	GetElem_L(t,4,e);
//	printf("e %d\n",e);
//	ListDelete_L(t,2,e);
//	printf("e %d\n",e);
//	printf("length %d\n", ListLength_L(t));
//	ListTraverse_L(t,visit_display_L);
////	ClearList_L(t);
////	b =ListInsert_L(t, 1, 11);
////	printf("&&&&&&");
////	ListTraverse_L(t,visit_display_L);
//	LocateElem_L(t,5,compare_equal_Sq);
//	printf("prior %d\n", e);
//}
//	struct DNode *p;
//	InitList_D(p);
//	printf("empty %d \n", ListEmpty_D(p));
//	printf("length %d\n",ListLength_D(p));
//	printf("list %d\n",ListInsert_D(p,1,13));
////	ListInsert_D(p,2,23);
////	ListInsert_D(p,2,33);
//	printf("length %d\n",ListLength_D(p));
////	ListTraverse_D(p, visit_display_D);
////	printf("%d ", p->next->data);
//	struct DNode *L;
//	int i;
//	int e;
//	printf("\n 函数init测试\n");
//	{
//		printf("初始化双循环链表L...\n");
//		InitList_D(L);
//		printf("\n");
//	}
//	printf("\n 函数empty 测试\n");
//	{
//		ListEmpty_D(L) ? printf("L 为空\n"):printf(" L 不为空\n");
//	}
//	printf("\n LinstInsert_D 测试、\n");
//	{
//		int i;
//		for(i=1;i<=6;i++){
//			printf("在%d位置插入%d...\n",i,2*i);
//			ListInsert_D(L,i,2*i);
//		}
//		printf("\n\n");
//	}
//	printf("\n函数listtrave测试。。、\n");
//	{
//		printf("L中的元素为：L= ");
//		ListTraverse_D(L,visit_display_D);
//		printf("\n\n");
//	}
//	printf("\n 函数listlength测试...\n");
//	{
//		printf("L 的长度为：%d\n",ListLength_D(L));
//		printf("\n");
//	}
//	printf("\n 函数listdelete测试。。。。\n");
//	{
//		ListDelete_D(L,6,e);
//		printf("删除元素%d,位于6\n",e);
//		printf("L中的元素为L= ");
//		ListTraverse_D(L,visit_display_D);
//		printf("\n");
//	}
//	printf("\n");
//
//	LinkList L;
//	Link p,q,s;
////	Position r;
//	int i;
////	ElemType e;
//	printf("makenode 测试。。\n");
//	{
//		MakeNode(p, 5);
//		printf("\n");
//	}
//	printf("visit display 测试。。\n");
//	{
//		visit_display(p);
//		printf("\n");
//	}
//
//	printf("Initlist 测试...\n");
//	{
//		printf("初始化扩展的单链表L...\n");
//		InitList(L);
//		printf("\n");
//	}
//	printf("LintEmpth 测试。。。。\n");
//	{
//		ListEmpty(L)?printf("L为空\n"):printf("L不为空\n");
//		printf("\n");
//	}
//	printf("ListInsert测试。。。\n");
//	{
//		for(i=1; i<=6; i++){
//			printf("在%d的位置插入%d...\n",i,2*i);
//			ListInsert(L,i, 2*i);
//		}
//		printf("\n");
//	}
//
//	printf("listTravel测试。。。\n");
//	{
//		printf("L 中的元素为 L = ");
//		ListTraverse(L,visit_display);
//		printf("\n\n");
//	}
//	printf("listlength测试...\n");
//	{	i = ListLength(L);
//		printf("L的长度为%d",i);
//		printf("\n\n");
//	}
//
//	printf("locatepos测试。。。\n");
//	{
//		LocatePos(L,3,s);
//		printf("L中第三个与元素为%d位于%d", s->data,s);
//		printf("\n\n");
//	}
//}
class BOX {
	protected:
		int a;
	private:
		int b;
	public:
		float lenght;
		float height;
		float width;
		float get_volume(void);
		void set_lenght(float len);
		friend void printWidth( BOX box );
		void set_height(float);
		void set_width(float);
		int compare(BOX box);
		BOX(float height); //constructor
		BOX( const BOX &obj);//copy constructor
		~BOX();
};

void printWidth(BOX box){
	 cout << "Width of box : " << box.width <<endl;
}

int BOX::compare(BOX box){
	return this->width >box.width;
}

BOX::BOX(const BOX &obj){
	printf("调用拷贝构造函数\n");
	width = 4.0;
	height = 5.0;
}

BOX::BOX(float h){
	printf("object created!\n");
	height = h;
}

BOX::~BOX(){
	printf("object destoryed!");
}

float BOX::get_volume() {
	float v;
	v = lenght * height * width;
	return v;
}

void BOX::set_lenght(float len) {
	lenght = len;
}

void BOX::set_height(float h) {
	height = h;
}

void BOX::set_width(float w) {
	width = w;
}

//class SHAPE: public BOX {
//public:
//	float get_area();
//	SHAPE(float);
//};
//
//SHAPE::SHAPE(float){
//	pass;
//}
//float SHAPE::get_area(){
//	return lenght * width;
//}
void display(BOX obj)
{
   cout << "line 大小 : " << obj.get_volume() <<endl;
   cout << "line 大小 : " << obj.height <<endl;
}

int main() {
	BOX box1(3.4);
	BOX box2 = box1;
//	printf("%d", box1.a);
//	SHAPE s;
	printWidth(box1);
	float volumn = 0.0;
	box1.set_lenght(6.0);
	box1.set_height(3.0);
	box1.set_width(2.0);
	volumn = box1.get_volume();
	display(box1);

	printf("%f\n", box1.height);
//	s.set_height(4.0);
//	s.set_lenght(2.0);
//	s.set_width(4.4);
//	a = s.get_area();
//	printf("%f",a);
}
