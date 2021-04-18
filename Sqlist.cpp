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
















