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


void insert_pos(Sqlist *list, int pos, ElemType x)
{
	if(pos < 0 || pos > list->size)
	{
		printf("要插入的位置不合法，无法插入数据\n");
		return;
	}
	for(int i = list->size; i > pos; --i)
	{
		list->base[i] = list->base[i - 1]; 
	}
	list->base[pos] = x;
	list->size++;
}


int find(Sqlist *list, ElemType x)
{
	for(int i = 0; i < list->size; i++)
	{
		if(list->base[i] == x)
		{
			return i;
		}
	}
	return -1;
}



int length(Sqlist *list)
{
	return list->size;
}


void delete_pos(Sqlist *list, int pos)
{
	if(pos < 0 || pos > list->size)
	{
		printf("要删除的位置无效，无法删除\n");
		return;
	}
	for(int i = pos; i < list->size; i++)
	{
		list->base[i] = list->base[i + 1];
	}
	list->size--;
}


void delete_val(Sqlist *list, ElemType x)
{
	int i = find(list, x);
	if(i == -1)
	{
		printf("没有该元素，无法删除\n");
		return;
	}
	delete_pos(list, i);
}


void sort(Sqlist *list)
{
	for(int i = 0; i < list->size -1; i++)
	{
		for(int j = 0; j < list->size - 1 - i; j++)
		{
			if(list->base[j] > list->base[j + 1])
			{
				ElemType tmp	   = list->base[j];
				list->base[j]      = list->base[j + 1]; 			
				list->base[j + 1]  = tmp;
			}
		}
	}
	return;
}


void resver(Sqlist *list)
{
	if(list->size == 0 || list->size == 1)
		return;
	int low  = 0;
	int high = list->size - 1;
	while(low != high)
	{
		ElemType tmp     = 0;
		tmp              = list->base[low];
		list->base[low]  = list->base[high];
		list->base[high] = tmp;
		low++;
		high--;
	} 
	return;
}
	

void clear(Sqlist *list)
{
	list->size = 0;
}



void destroy(Sqlist *list)
{
	free(list->base);
	list->base    = NULL;
	list->capcity = 0;
	list->size    = 0;
}


	
