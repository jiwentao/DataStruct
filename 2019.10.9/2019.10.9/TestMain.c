#define _CRT_SECURE_NO_WARNINGS
#include"slist.h"
void menu()
{
	printf("************************************\n");
	printf("****1.push_back     2.push_front****\n");
	printf("****3.pop_back      4.pop_front ****\n");
	printf("****5.insert_val    6.delete_val****\n");
	printf("****7.find_val      8.reverse   ****\n");
	printf("****9.sort          10.length   ****\n");
	printf("****11.modify_val   12.show_list****\n");
	printf("****13.clear        14.destroy  ****\n");
	printf("***********  0.exit  ***************\n");
	printf("************************************\n");
}
int main()
{
	DataType input = 0;
	DataType item;
	Slist mylist;
	SlistInit(&mylist);
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
			printf("请输入你要插入的数据(-1结束):>");
			while(scanf("%d",&item) ==1 && item != -1)
			{ 
				Push_back(&mylist,item);
			}
			break;
		case PUSH_FRONT:
			break;
		case POP_BACK:
			break;
		case POP_FRONT:
			break;
		case INSERT_VAL:
			break;
		case DELETE_VAL:
			break;
		case FIND_VAL:
			break;
		case REVERSE:
			break;
		case SORT:
			break;
		case LENTH:
			break;
		case MODIFY_VAL:
			break;
		case SHOW_SLIST:
			Show_List(&mylist);
			break;
		case CLEAR:
			break;
		case DESTROY:
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
	}while(input);
}