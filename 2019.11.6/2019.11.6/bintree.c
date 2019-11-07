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
//���ڵ�����ջ��ջ���գ����ڵ��ջ���ҽ����ջ����ڵ���ջ
void _BinTree_PreOrder(struct BinTreeNode * pbt)
{
	BinTreeNode * p = NULL;
	if(pbt != NULL)
	{
		ListStack ls;
		ListStack_Init(&ls);
		ListStack_Push(&ls,pbt);//���ڵ�����ջ
		while(ls != NULL)
		{
			p = ListStack_Get_Top_Val(&ls);
			ListStack_Pop(&ls);
			printf("%c ",p->data);
			if(p->rightchild != NULL)//�ҽ����ջ
				ListStack_Push(&ls,p->rightchild);
			if(p->leftchild != NULL)//��ڵ���ջ
				ListStack_Push(&ls,p->leftchild);
		}
	}
}

void BinTree_MiddleOrder(struct BinTree * pbt)
{
	_BinTree_MiddleOrder(pbt->root);
}
//���ҵ�����ߵĽ�㣬���������ջ���ҵ����ջ���жϳ�ջ����Ƿ����ҽ��
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