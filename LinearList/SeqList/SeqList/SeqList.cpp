// SeqList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//顺序表

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MaxSize 50              //定义线性表的最大长度
typedef int ElemType;           //定义类型

//静态分配
typedef struct {
	ElemType data[MaxSize];     //顺序表的元素
	int length;                 //顺序表的当前长度
}SqList;                        //顺序表的类型定义

//动态分配
#define InitSize 100            //表长度的初始定义
typedef struct {
	ElemType *data;             //指示动态分配数组的指针
	int capacity;               //动态数组的最大容量
	int length;                 
}SeqList;                       //动态分配数组顺序表的类型定义

//i代表插入的位置，从1开始
//时间复杂度为 O(n)
bool ListInsert(SqList &L, int i, ElemType e) {  //&为引用
	if (i<1||i>L.length+1)        //判断i的范围是否有效
	{
		return false;
	}
	if (L.length>=MaxSize)      //当前存储空间已满，不能插入
	{
		return false;
	}
	for (int j = L.length; j >=i; j--)  //将第i个元素及之后的元素后移
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;          //在位置i处放入e
	L.length++;                 //线性表长度加1
	return true;
}
 
//删除操作
//时间复杂度为 O(n)
bool ListDelete(SqList &L, int i, ElemType &e) {
	//本算法实现删除顺序表L中第i个位置的元素
	if (i<1||i>L.length)        //判断i的范围是否有效
	{
		return false;
	}
	e = L.data[i - 1];          //将被删除的元素赋值给e
	for (int j = i; j < L.length; j++)  //将第i个位置之后的元素前移
		L.data[j - 1] = L.data[j];
	L.length--;                 //线性表的长度-1
	return true;
}

//按值查找（顺序查找）
int LocateElem(SqList L, ElemType e) {
	//本算法实现查找顺序表中值为e的元素，如果查找成功，返回元素位序，否则返回0
	int i;
	for(i=0;i<L.length;i++)
		if (L.data[i]==e)
		{
			return i + 1;        //下标为i的元素值等于e，返回其位序i+1 
		}
	return 0;                    //退出循环，说明查找失败
}

//打印顺序表元素
void PrintList(SqList &L) {
	for (int i = 0; i < L.length; i++)
	{
		printf("%4d", L.data[i]);
	}
	printf("\n");
}

int main()
{
	SqList L;            //顺序表的名称
	bool ret;            //查看返回值
	ElemType del;        //要删除的元素

	//首先手动在顺序表中赋值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;         //总计三个元素
	ret = ListInsert(L, 2, 60);
	if (ret)
	{
		printf("插入成功\n");
		PrintList(L);
	}
	else
	{
		printf("插入失败\n");
	}
	ret = ListDelete(L, 1, del);
	if (ret)
	{
		printf("删除成功\n");
		printf("删除元素值为 %d\n", del);
		PrintList(L);
	}
	else
	{
		printf("删除失败\n");
	}
	ret = LocateElem(L, 60);
	if (ret)
	{
		printf("查找成功\n");
		printf("元素位置为%d\n", ret);
	}
	else
	{
		printf("查找失败\n");
	}
	system("pause");  //停在控制台窗口
}


