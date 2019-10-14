#define _CRT_SECURE_NO_WARNINGS
#include"dclist.h"
void menu()
{
	printf("****************************************\n");
	printf("*****1.push_back       2.push_front*****\n");
	printf("*****3.pop_back        4.pop_front *****\n");
	printf("*****5.show_list       6.find_val  *****\n");
	printf("*****7.insert_val      8.delete_val*****\n");
	printf("*****9.modify_val      10.lenth    *****\n");
	printf("*****11.sort           12.reverse  *****\n");
	printf("*****13.clear          14.destroy  *****\n");
	printf("**************   0.exit   **************\n");
	printf("****************************************\n");
}
int main()
{
	DataType input = 0,item = 0;
	DCListNode * ret = NULL;
	DCList mylist;
	DCList_Init(&mylist);
	do 
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d",&input);
		switch(input)
		{
		case EXIT:
			break;
		case PUSH_BACK:
			printf("请输入你要插入的值:>");
			while(scanf("%d",&item) == 1 && item != -1)
			{
				Push_back(&mylist,item);
			}
			break;
		case PUSH_FRONT:
			printf("请输入你要插入的值:>");
			while(scanf("%d",&item) == 1 && item != -1)
			{
				Push_front(&mylist,item);
			}
			break;
		case POP_BACK:
			Pop_back(&mylist);
			break;
		case POP_FRONT:
			Pop_front(&mylist);
			break;
		case SHOW_LIST:
			Show_list(&mylist);
			break;
		case FIND_VAL:
			printf("请输入你要查找的值:>");
			scanf("%d",&item);
			ret = Find_val(&mylist,item);
			if(ret == NULL)
				printf("查找的值不存在!\n");
			else
				printf("%p\n",ret);
			break;
		case INSEART_VAL:
			printf("请输入你要插入的值:>");
			scanf("%d",&item);
			Insert_val(&mylist,item);
			break;
		case DELETE_VAL:
			printf("请输入你要删除的值:>");
			scanf("%d",&item);
			Delete_val(&mylist,item);
			break;
		case MODIFY_VAL:
			printf("请输入修改前的值:>");
			scanf("%d",&item);
			Modify_val(&mylist,item);
			break;
		case LENTH:
			item = Lenth_list(&mylist);
			printf("该链表的大小为:>%d\n",item);
			break;
		case SORT:
			break;
		case REVERSE:
			break;
		case CLEAR:
			break;
		case DESTROY:
			break;
		default:
			printf("选择错误，请重新选择!\n");
			break;
		}
	}while(input);
	return 0;
}