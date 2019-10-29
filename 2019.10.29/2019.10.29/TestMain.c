#define _CRT_SECURE_NO_WARNINGS
#include"bintree.h"
//int main()
//{
//	BinTree bt;
//	BinTree_Init(&bt);
//	BinTree_Creat_By_Input(&bt);
//
//	printf("VLF:>");
//	BinTree_PreOrder(&bt);
//	printf("\n");
//}
void menu()
{
	printf("******************************************\n");
	printf("****0.exit        1.tree_createbyinput****\n");
	printf("****2.tree_preorder 3.tree_middleorder****\n");
	printf("****4.tree_postorder 5.tree_levelorder****\n");
	printf("****6.tree_node_sum  7.tree_height    ****\n");
	printf("****8.tree_find      9.tree_parent    ****\n");
	printf("****10.tree_clone    11.tree_isequal  ****\n");
	printf("****12.tree_createbystr               ****\n");
	printf("******************************************\n");
}
int main()
{
	int input = 0;
	int count = 0;
	BinTreeNode * p = NULL;
	BinTree bt;
	BinTree_Init(&bt);
	do
	{
		menu();
		printf("请输入你的选择:>");
		scanf("%d",&input);
		fflush(stdin);
		switch(input)
		{
		case 0:
			break;
		case 1:
			BinTree_Creat_By_Input(&bt);
			break;
		case 2:
			printf("VLR:>");
			BinTree_PreOrder(&bt);
			printf("\n");
			break;
		case 3:
			printf("LVR:>");
			BinTree_MiddleOrder(&bt);
			printf("\n");
			break;
		case 4:
			printf("LRV:>");
			BinTree_PostOrder(&bt);
			printf("\n");
			break;
		case 5:
			break;
		case 6:
			count = BinTree_Node_Sum(&bt);
			printf("该二叉树结点个数为:>%d\n",count);
			/*BinTree_Node_Sum(&bt);*/
			break;
		case 7:
			count = BinTree_Height(&bt);
			printf("该二叉树的深度为:>%d\n",count);
			break;
		case 8:
			/*printf("请输入你要查找的结点值:>");
			scanf("&c",&input);
			fflush(stdin);*/
			p = BinTree_Find(&bt,'D');
			printf("%p\n",p);
			/*if(p == NULL)
			{
				printf("查找的值不存在!\n");
			}
			else
			{
				printf("该值的位置为:%p\n",p);
			}*/
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
	}while(input);
	return 0;
}
