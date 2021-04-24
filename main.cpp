#include "Sqlist.h"
#include <stdio.h>

int main()
{
	Sqlist mylist;
	InitSqlist(&mylist);
	ElemType Item;
	int select = 1;
	int pos    = 0;
	while (select)
	{
		printf("*********************************\n");
		printf("* [1] push_back  [2] push_front *\n");
		printf("* [3] show_list  [4] pop_back   *\n");
		printf("* [5] pop_front  [6] insert_pos *\n");
		printf("* [7] find       [8] length     *\n");
		printf("* [9] delete_pos [10] delete_val*\n");
		printf("* [11] sort      [12] resver    *\n");
		printf("* [13] clear     [14] destroy   *\n");
		printf("* [0] quit                      *\n");
		printf("*********************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if(select == 0)
			break;
		
		switch(select)
		{
			case 1:
				printf("请输入要插入的数据（-1结束）：");
				while(scanf("%d", &Item), Item != -1)
				{
					push_back(&mylist, Item);
				}
				break;
			case 2:
				printf("请输入要插入的数据（-1结束）：");
				while(scanf("%d",&Item), Item != -1)
				{
					push_front(&mylist, Item);
				}
				break;
			case 3:
				show_list(&mylist);
				break;
			case 4:
				pop_back(&mylist);
				break;
			case 5:
				pop_front(&mylist);
				break;
			case 6:
				printf("请输入要插入的位置：");
				scanf("%d", &pos);
				printf("请输入要插入的数据：");
				scanf("%d", &Item);
				insert_pos(&mylist, pos, Item);
				break;
			case 7:			
				printf("请输入要查找的数据：");
				scanf("%d", &Item);
				pos = find(&mylist, Item);
				printf("%d\n", pos);
				break;
			case 8:
				printf("顺序表长度为：%d\n", length(&mylist));	
				break;
			case 9:
				printf("请输入要删除元素的位置：");
				scanf("%d", &pos);
				delete_pos(&mylist, pos);
				break;
			case 10:
				printf("请输入要删除的元素：");
				scanf("%d", &Item);
				delete_val(&mylist, Item);
				break;
			case 11:
				sort(&mylist);
				break;
			case 12:
				resver(&mylist);
				break;
			case 13:
				clear(&mylist);
				break;
			case 14:
				destroy(&mylist);
				break;
			default:
				break;	
		}
		//destroy(&mylist);
	}	
	return 0;
}	
