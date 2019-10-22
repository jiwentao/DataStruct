#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
void menu()
{
	printf("*********************************\n");
	printf("****0.exit      1.stack_push*****\n");
	printf("****2.stack_pop 3.stack_show*****\n");
	printf("****      4.get_pop_val     *****\n");
	printf("*********************************\n");
}
int main()
{
	DataType val = 0,input = 0;
	SeqStack mystack;
	SeqStack_Init(&mystack,STACK_DEFAULT_SIZE);
	//SeqStack * pst = SeqStackCreate(STACK_DEFAULT_SIZE);
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
			printf("请输入入栈的值:>");
			scanf("%d",&val);
			SeqStack_push(&mystack,val);
			break;
		case 2:
			SeqStack_pop(&mystack);
			break;
		case 3:
			SeqStack_show(&mystack);
			break;
		case 4:
			Get_Pop_Val(&mystack);
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
	}while(input);
	
}