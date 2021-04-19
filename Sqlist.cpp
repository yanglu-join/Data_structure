#include "Sqlist.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>



void InitSqlist(Sqlist *list)
{
	list->base    = (ElemType*)malloc(sizeof(ElemType)*SQLIST_INIT_SIZE); 
	assert(list->base != NULL); 
	list->capcity = SQLIST_INIT_SIZE;
	list->size    = 0;
}


void push_back(Sqlist *list, ElemType x)
{
	//判断能否插入输入
	if(list->size >= list->capcity)
	{
		printf("顺序表空间已满，不能尾部插入数据");
		return;
	}
	list->base[list->size] = x;
	list->size++;	
	

}


void show_list(Sqlist *list)
{
	for(int i = 0; i < list->size; i++)
	{
		printf("%d ", list->base[i]);	
	}
	printf("\n");

}


void push_front(Sqlist *list, ElemType x)
{
	if(list->size >= list->capcity)
	{
		printf("顺序表已满，不能头部插入\n");
		return;
	}
	//所有的元素往后移动
	for(int i = list->size; i > 0; --i)
	{
		list->base[i] = list->base[i-1];
	}
	list->base[0] = x;
	list->size++;
}


void pop_back(Sqlist *list)
{
	if(list->size == 0)
	{
		printf("顺序表已空，无法尾部删除\n");
		return;
	}
	list->size--;
}


void pop_front(Sqlist *list)
{
	if(list->size == 0)
	{
		printf("顺序表已空，无法头部删除\n");
		return;
	}
	for(int i = 0; i < list->size-1; i++)
	{
		list->base[i] = list->base[i + 1];
	}
	list->size--;
}










