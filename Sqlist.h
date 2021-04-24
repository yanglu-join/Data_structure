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

//头部插入
void push_front(Sqlist *list, ElemType x);

//显示顺序表
void show_list(Sqlist *list);

//尾部删除
void pop_back(Sqlist *list);

//头部删除
void pop_front(Sqlist *list);

//按位置插入
void insert_pos(Sqlist *list, int pos, ElemType x);

//按值查找，返回位置
int find(Sqlist *list, ElemType x);

//求顺序表长度
int length(Sqlist *list);

//按位置删除
void delete_pos(Sqlist *list, int pos);

//按值删除
void delete_val(Sqlist *list, ElemType x);

//排序（冒泡）
void sort(Sqlist *list);

//反转
void resver(Sqlist *list);

//清除
void clear(Sqlist *list);

//摧毁
void destroy(Sqlist *list);



#endif
