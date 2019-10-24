#define _CRT_SECURE_NO_WARNINGS
#include"queue.h"

void menu()
{
	printf("*********************************\n");
	printf("****0.exit       1.queue_in  ****\n");
	printf("****2.queue_out  3.queue_show****\n");
	printf("****4.get_front_val 5.destroy****\n");
	printf("*********************************\n");
}
int main()
{
	int input = 0;
	SeqQueue sq;
	SeqQueue_Init(&sq);
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
			SeqQueue_In(&sq);
			break;
		case 2:
			SeqQueue_Out(&sq);
			break;
		case 3:
			SeqQueue_show(&sq);
			break;
		case 4:
			Get_Front_Val(&sq);
			break;
		case 5:
			SeqQueue_Destroy(&sq);
			break;
		default:
			printf("选择错误,重新选择!\n");
			break;
		}
	}while(input);
}