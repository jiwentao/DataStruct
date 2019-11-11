#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"

void menu()
{
	printf("************************************\n");
	printf("****1.heap_insert    2.heap-show****\n");
	printf("****3.heap_remove 4.heap_destroy****\n");
	printf("****5.heap_get_top_val 0.exit   ****\n");
	printf("************************************\n");
	printf("**** AdjustUp        AdjustDown ****\n");
	printf("************************************\n");
}
int main()
{
	int input = 0,i = 0;
	int arr[] = {27,15,19,18,28,34,65,49,25,37};
	int n = sizeof(arr)/sizeof(arr[0]);
	Heap hp;
	Heap_Init(&hp,n);
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
			for(i = 0;i < n; i++)
			{	
				Heap_Insert(&hp,arr[i]);
			}//小根堆
			break;
		case 2:
			Heap_Show(hp);
			break;
		case 3:
			Heap_Remove(&hp);
			break;
		case 4:
			Heap_Destroy(&hp);
			break;
		case 5:
			Heap_Get_Top_Val(hp);
			break;
		default:
			printf("选择错误,重新选择!\n");
			break;
		}
	}while(input);
	return 0;
}