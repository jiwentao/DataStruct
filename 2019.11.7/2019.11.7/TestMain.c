#define _CRT_SECURE_NO_WARNINGS
#include"bst.h"

void menu()
{
	printf("****************************************\n");
	printf("*****1.tree_insert      2.tree_show*****\n");
	printf("*****3.tree_remove      4.tree_sort*****\n");
	printf("*****5.find_min         6.find_max *****\n");
	printf("*****7.tree_find        0.exit    ******\n");
	printf("****************************************\n");
}
int main()
{
	int input = 0;
	int arr[] = {0};
	int i = 0,j = 0;
	BSTree bst;
	BSTree_Init(&bst);
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
			printf("请输入要插入的值(-1结束):>");
			//45,10,24,53,12,38,21,90,30
			while(scanf("%d",&input) == 1 && input != -1)
			{
				BSTree_Insert(&bst,input);
			}
			break;
		case 2:
			BSTree_Show(bst);//(中序遍历)
			printf("\n");
			break;
		case 3:
			printf("请输入要移除的值:>");
			scanf("%d",&input);
			BSTree_Remove(&bst,input);
			break;
		case 4:
			BSTree_Sort(&bst,arr,&i);
			for(j = 0;j < i;j++)
			{
				printf("%d ",arr[j]);
			}
			printf("\n");
			break;
		case 5:
			BSTree_Find_Min(bst);
			break;
		case 6:
			BSTree_Find_Max(bst);
			break;
		case 7:
			printf("请输入你要查找的值:>");
			scanf("%d",&input);
			BSTree_Find(bst,input);
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
	return 0;
}