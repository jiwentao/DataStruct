#define _CRT_SECURE_NO_WARNINGS
#include"liststack.h"

void menu()
{
	printf("*********************************\n");
	printf("*****0.exit     1.stack_push*****\n");
	printf("*****2.stack_pop3.stack_show*****\n");
	printf("*****  4.get_stack_pop_val  *****\n");
	printf("*********************************\n");
}
int main()
{
	int input;
	ListStack plt;
	ListStack_Init(&plt);
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d",&input);
		switch(input)
		{
		case 0:
			break;
		case 1:
			ListStack_push(&plt);
			break;
		case 2:
			ListStack_pop(&plt);
			break;
		case 3:
			ListStack_show(plt);
			break;
		case 4:
			Get_Stack_Pop_Val(plt);
			break;
		default:
			printf("选择错误,重新选择!\n");
			break;
		}
	}while(input);
	return 0;
}