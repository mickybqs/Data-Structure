// DoubleLinkedList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//双链表在插入和删除操作的实现上，和单链表有着较大的不同
//（“链”变化时也需要对prior指针做出修改，其关键在修改的过程中不断链）
//插入、删除结点算法的时间复杂度为O(1)

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct DNode {             //定义双链表结点类型
	ElemType data;                 //数据域
	struct DNode *prior, *next;    //前驱和后继指针
}DNode,*DLinkList;

//双链表头插法,带头结点
DLinkList Dlist_head_insert(DLinkList &DL)
{
	DNode *s; int x;
	DL = (DLinkList)malloc(sizeof(DNode));//带头结点的链表,不带头结点
	DL->next = NULL;
	DL->prior = NULL;
	scanf("%d", &x);//从标准输入读取数据
	//3 4 5 6 7 9999
	while (x != 9999) {
		s = (DLinkList)malloc(sizeof(DNode));//申请一个空间空间，强制类型转换
		s->data = x;
		s->next = DL->next;
		if (DL->next != NULL)//插入第一个结点时，不需要这一步操作
		{
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d", &x);//读取标准输入
	}
	return DL;
}

//双向链表尾插法
DLinkList Dlist_tail_insert(DLinkList &DL)
{
	int x;
	DL = (DLinkList)malloc(sizeof(DNode));  //带头结点的链表
	DNode *s, *r = DL;
	DL->prior = NULL;
	//3 4 5 6 7 9999
	scanf("%d", &x);
	while (x!=9999)
	{
		s = (DNode*)malloc(sizeof(DNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;              //r指向新的表尾结点
		scanf("%d", &x);
	}
	r->next = NULL;  //尾结点的next指针赋值为NULL
	return DL;
}

//按序列号查找结点值
DNode *GetElem(DLinkList DL, int i)
{
	int j = 1;
	DNode *p = DL->next;
	if (i == 0)
		return DL;
	if (i < 1)
		return NULL;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}

	return p;
}

//新结点插入第i个位置
bool DLisFrontInsert(DLinkList DL, int i, ElemType e)
{
	DLinkList p = GetElem(DL, i - 1);
	if (NULL==p)
	{
		return false;
	}
	DLinkList s = (DLinkList)malloc(sizeof(DNode));   //为新插入的结点申请空间
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

//删除第i个结点
bool DListDelete(DLinkList DL, int i)
{
	DLinkList p = GetElem(DL, i - 1);
	if (NULL==p)
	{
		return false;
	}
	DLinkList q;
	q = p->next;
	if (q->next!=NULL)
	{
		q->next->prior = p;
	}

	free(q);  //释放对应结点空间
	return true;
}

//链表打印
void PrintDList(DLinkList DL)
{
	DL = DL->next;
	while (DL!=NULL)
	{
		printf("%3d", DL->data);
		DL = DL->next;
	}
	printf("\n");
}
int main()
{
	DLinkList DL;
	DLinkList search;
	//Dlist_head_insert(DL);
	Dlist_tail_insert(DL);
	//3 4 5 6 7 9999
	PrintDList(DL);
	search = GetElem(DL, 2);
	if (search!=NULL)
	{
		printf("按序号查找成功！\n");
		printf("%d\n", search->data);
	}
	DLisFrontInsert(DL, 3, 99);
	PrintDList(DL);
	DListDelete(DL, 2);
	PrintDList(DL);
	system("pause");
}


