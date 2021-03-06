// SingleLinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode {       //定义单链表结点类型
	ElemType data;           //数据域
	struct LNode *next;      //指针域,指向下一个结点
}LNode, *LinkList;

//头插法建立单链表
LinkList CreatList1(LinkList &L) {
	//从表尾到表头逆向建立单链表L,每次均在头结点之后插入元素
	LNode *s; int x;
	L = (LinkList)malloc(sizeof(LNode));    //创建头结点
	L->next = NULL;                         //初始为空链表
	scanf("%d", &x);                        //输入结点的值
	while (x!=9999)                         //输入9999表示结束
	{
		s = (LNode*)malloc(sizeof(LNode));  //申请类型空间，（LNode*）强制类型转换为int
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}                                       //while结束
	return L;
}

//尾插法建立单链表
LinkList CreateList2(LinkList &L) {          //list_tall_insert 尾插法标准命名
	//从表头到表尾正向建立单链表L,每次均在表尾插入元素
	int x;                                   //设元素类型为整型
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;                        //r为表尾指针
	scanf("%d", &x);                         //输入结点的值
	while (x!=9999){                         //输入9999表示结束
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;                               //r指向新的表尾结点
		scanf("%d", &x);
	}
	r->next = NULL;                          //尾结点指针置空
	return L;
}

//按序列号查找结点值
LNode *GetElem(LinkList L, int i) {
	//本算法取出单链表L (带头结点)中第i个位置的结点指针
	int j = 1;                               //计数，初始为1
	LNode *p = L->next;                      //头结点指针赋给p

	if (i==0)
	{
		return L;                            //若i等于0，则返回头结点
	}
	if (i<1)
	{
		return NULL;                         //若i无效，则返回NULL
	}
	while (p&&j<i)
	{
		p = p->next;
		j++;
	}
	return p;                                //返回第i个结点的指针，如果i大于表长，P
}

//按值查找表结点
LNode *LocateElem(LinkList L, ElemType e) {
	//本算法查找单链表L（带头结点）中数据域值等于e的结点指针，否则返回NULL
	LNode *p = L->next;
	while (p!=NULL&&p->data!=e)              //从第1个结点开始查找data域为e的结点
	{
		p = p->next;
	}
	return p;                                //找到后返回该结点指针，否则返回NULL
}

//新结点插入第i个位置,前插入操作
bool ListFrontInsert(LinkList L, int i,ElemType e) {
	LinkList p = GetElem(L, i - 1);
	if (NULL==p)
	{
		return false;
	}
	LinkList s = (LNode*)malloc(sizeof(LNode));  //为新插入的结点申请空间
	s->data = e;
	s->next = p->next;                           //先指向p结点的后继节点
	p->next = s;                                 //p的指针域指向新的插入的节点*s
	return true;
}

//后插操作
bool ListBackInsert(LinkList L, int i, ElemType e) {
	//将*s结点插入到*p之前
	
	return 0;
}

//C语言前插法
bool Insert(LinkList L, int i, ElemType e) {
	LinkList p, s;
	if (i==1)  //新结点插入在表头
	{
		s = (LNode*)malloc(sizeof(LNode));  //申请填装结点
		s->data = e;
		s->next = L;
		return s;
	}
	p = GetElem(L, i - 1);  //按值查找第i-1个结点
	if (p==NULL)            //第i-1个结点不存在，不能插入
	{
		printf("参数i错误");
		return NULL;
	}
	else
	{
		s = (LNode*)malloc(sizeof(LNode));  //申请、填装结点
		s->data = e;                        
		s->next = p->next;                  //新结点插入在第i-1个结点的后面
		p->next = s;
		return true;
	}
}
//删除第i个结点
bool ListDelete(LinkList L, int i) {

	LinkList p = GetElem(L, i - 1);          //查找插入位置的前驱结点
	if (NULL==p)
	{
		return false;
	}
	LinkList q;
	q = p->next;
	p->next = q->next;                      //断链
	free(q);
	return true;
}

//打印链表中每个结点的值
void PrintList(LinkList L) {

	L = L->next;
	while (L!=NULL)
	{
		printf("%3d", L->data);
		L = L->next;
	}
	printf("\n");
}
int main()
{
	LinkList L;                    //链表头          
	LinkList search;
	CreatList1(L);                 //输入数据可以为3 4 5 6 7 9999
	//CreateList2(L);              //输入数据可以为3 4 5 6 7 9999
	PrintList(L);
	search = GetElem(L, 2);
	if (search!=NULL)
	{
		printf("按序号查找成功\n");
		printf("%d\n", search->data);
	}
	search = LocateElem(L, 6);
	if (search!=NULL)
	{
		printf("按值查找成功\n");
		printf("%d\n", search->data);
	}
	//ListFrontInsert(L, 2, 99);
	Insert(L, 3, 10);
	PrintList(L);
	system("pause");
}


