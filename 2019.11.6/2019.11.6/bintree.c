#define _CRT_SECURE_NO_WARNINGS
#include"bintree.h"

void BinTree_Init(struct BinTree * pbt)
{
	pbt->root = NULL;
}

void BinTree_Create_By_Input(struct BinTree * pbt)
{
	_BinTree_Create_By_Input(&pbt->root);
}
void _BinTree_Create_By_Input(struct BinTreeNode ** pbt)
{
	DataType val = '0';
	scanf("%c",&val);
	if(val == '#')
	{
		*pbt = NULL;
	}
	else
	{
		*pbt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*pbt != NULL);
		(*pbt)->data = val;
		_BinTree_Create_By_Input(&(*pbt)->leftchild);
		_BinTree_Create_By_Input(&(*pbt)->rightchild);
	}
}
#include"stack.h"
void BinTree_PreOrder(struct BinTree * pbt)
{
	_BinTree_PreOrder(pbt->root);
}
//根节点先入栈，栈不空，根节点出栈，右结点入栈，左节点入栈
void _BinTree_PreOrder(struct BinTreeNode * pbt)
{
	BinTreeNode * p = NULL;
	if(pbt != NULL)
	{
		ListStack ls;
		ListStack_Init(&ls);
		ListStack_Push(&ls,pbt);//根节点先入栈
		while(ls != NULL)
		{
			p = ListStack_Get_Top_Val(&ls);
			ListStack_Pop(&ls);
			printf("%c ",p->data);
			if(p->rightchild != NULL)//右结点入栈
				ListStack_Push(&ls,p->rightchild);
			if(p->leftchild != NULL)//左节点入栈
				ListStack_Push(&ls,p->leftchild);
		}
	}
}

void BinTree_MiddleOrder(struct BinTree * pbt)
{
	_BinTree_MiddleOrder(pbt->root);
}
//先找到最左边的结点，遍历结点入栈，找到后出栈，判断出栈结点是否有右结点
void _BinTree_MiddleOrder(struct BinTreeNode * pbt)
{
	if(pbt != NULL)
	{
		BinTreeNode * p = NULL;
		ListStack ls;
		ListStack_Init(&ls);
		do
		{
			while(pbt != NULL)
			{
				ListStack_Push(&ls,pbt);
				pbt = pbt->leftchild;
			}

			p = ListStack_Get_Top_Val(&ls);
			ListStack_Pop(&ls);
			printf("%c ",p->data);

			if(p->rightchild != NULL)
				pbt = p->rightchild;
		}while(ls != NULL || pbt != NULL);
	}
}

void BinTree_PostOrder(struct BinTree * pbt)
{
	_BinTree_PostOrder(pbt->root);
}
void _BinTree_PostOrder(struct BinTreeNode * pbt)
{
	if(pbt != NULL)
	{
		BinTreeNode * p = NULL,* pre = NULL;
		ListStack ls;
		ListStack_Init(&ls);
		do
		{
			while(pbt != NULL)
			{
				ListStack_Push(&ls,pbt);
				pbt = pbt->leftchild;
			}

			p = ListStack_Get_Top_Val(&ls);
			if(p->rightchild == NULL || p->rightchild == pre)
			{
				ListStack_Pop(&ls);
				printf("%c ",p->data);
				pre = p;
			}
			else
			{
				pbt = p->rightchild;
			}
		}while(ls != NULL);
	}
}