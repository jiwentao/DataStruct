#define _CRT_SECURE_NO_WARNINGS
#include"bintree.h"
void BinTree_Init(struct BinTree * pbt)
{
	assert(pbt != NULL);
	pbt->root = NULL;
}

void _BinTree_Creat_By_Input(BinTreeNode ** pbt)
{
	DataType input = 0;
	scanf("%c",&input);
	if(input == '#')
	{
		*pbt = NULL;
	}
	else
	{
		*pbt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		if(*pbt == NULL)
			return;
		(*pbt)->data = input;
		_BinTree_Creat_By_Input(&((*pbt)->leftchild));
		_BinTree_Creat_By_Input(&((*pbt)->rightchild));
	}	
}
void BinTree_Creat_By_Input(struct BinTree * pbt)
{
	_BinTree_Creat_By_Input(&(pbt->root));
}

void BinTree_PreOrder(struct BinTree * pbt)
{
	_BinTree_PreOrder(pbt->root);
}
void _BinTree_PreOrder(struct BinTreeNode * pbt)
{
	if(pbt != NULL)
	{
		printf("%c ",pbt->data);
		_BinTree_PreOrder(pbt->leftchild);
		_BinTree_PreOrder(pbt->rightchild);
	}	
}

void BinTree_MiddleOrder(struct BinTree * pbt)
{
	_BinTree_MiddleOrder(pbt->root);
}
void _BinTree_MiddleOrder(struct BinTreeNode * pbt)
{
	if(pbt != NULL)
	{
		_BinTree_MiddleOrder(pbt->leftchild);
		printf("%c ",pbt->data);
		_BinTree_MiddleOrder(pbt->rightchild);
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
		_BinTree_PostOrder(pbt->leftchild);
		_BinTree_PostOrder(pbt->rightchild);
		printf("%c ",pbt->data);
	}
}

//求节点个数方法一
size_t BinTree_Node_Sum(struct BinTree * pbt)
{
	return _BinTree_Node_Sum(pbt->root);
}
size_t _BinTree_Node_Sum(struct BinTreeNode * pbt)
{
	if(pbt == NULL)
	{
		return 0;
	}
	return _BinTree_Node_Sum(pbt->leftchild)+_BinTree_Node_Sum(pbt->rightchild)+1;
}
#if 0
//求节点个数方法二
void BinTree_Node_Sum(struct BinTree * pbt)
{   
	 int count = 0;
	_BinTree_Node_Sum(pbt->root,&count);
	printf("该二叉树结点个数为:>%d\n",count);
}
void _BinTree_Node_Sum(struct BinTreeNode * pbt,int * sum)
{
	
	if(pbt != NULL)
	{
		(*sum)++;
		_BinTree_Node_Sum(pbt->leftchild,sum);
		_BinTree_Node_Sum(pbt->rightchild,sum);
	}	
}
#endif

size_t BinTree_Height(struct BinTree * pbt)
{
	return _BinTree_Height(pbt->root);
}
size_t _BinTree_Height(struct BinTreeNode * pbt)
{
	if(pbt == NULL)
		return 0;
	return _BinTree_Height(pbt->leftchild)>_BinTree_Height(pbt->rightchild)?_BinTree_Height(pbt->leftchild)+1:_BinTree_Height(pbt->rightchild)+1;
}

BinTreeNode * BinTree_Find(struct BinTree * pbt,DataType key)
{
	return _BinTree_Find(pbt->root,key);
}
BinTreeNode * _BinTree_Find(struct BinTreeNode * pbt,DataType key)
{
	BinTreeNode * p = NULL;
	if(pbt == NULL)
		return NULL;
	if(pbt->data == key)
		return pbt;
	p = _BinTree_Find(pbt->leftchild,key);
	if(p != NULL)
		return p;
	return _BinTree_Find(pbt->rightchild,key);
}