#define _CRT_SECURE_NO_WARNINGS
#include"listqueue.h"

void menu()
{
	printf("***********************************\n");
	printf("*****0.exit         1.queue_in*****\n");
	printf("*****2.queue_out  3.queue_show*****\n");
	printf("*****4.get_front_val 5.destroy*****\n");
	printf("***********************************\n");
}
int main()
{
	int input = 0;
	ListQueue plq;
	ListQueue_Init(&plq);
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
			ListQueue_In(&plq);
			break;
		case 2:
			ListQueue_Out(&plq);
			break;
		case 3:
			ListQueue_Show(&plq);
			break;
		case 4:
			Get_Front_Val(&plq);
			break;
		case 5:
			ListQueue_Destroy(&plq);
			break;
		default:
			printf("选择错误,重新选择!\n");
			break;
		}
	}while(input);
	return 0;
}