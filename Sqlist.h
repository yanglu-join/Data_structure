#ifndef _SQLIST_H_
#define _SQLIST_H_

#include <stdio.h>

#define SQLIST_INIT_SIZE 8
typedef int ElemType;

typedef struct Sqlist
{
	ElemType *base;
	int       capcity;
	int       size;
}Sqlist;

//初始化
void InitSqlist(Sqlist *list);

//尾部插入
void push_back(Sqlist *list, ElemType x);

//显示顺序表
void show_list(Sqlist *list);

#endif
