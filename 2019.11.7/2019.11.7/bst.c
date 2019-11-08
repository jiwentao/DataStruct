#define _CRT_SECURE_NO_WARNINGS
#include"bst.h"
void BSTree_Init(BSTree * pbst)
{
	*pbst = NULL;
}

void BSTree_Insert(BSTree * pbst,DataType x)
{	
	if(*pbst == NULL)
	{
		*pbst = (BSTNode*)malloc(sizeof(BSTNode));
		(*pbst)->data = x;
		(*pbst)->leftchild = (*pbst)->rightchild = NULL;
	}
	else if((*pbst)->data > x)
	{
		BSTree_Insert(&(*pbst)->leftchild,x);
	}
	else if((*pbst)->data < x)
	{
		BSTree_Insert(&(*pbst)->rightchild,x);
	}
	else
		return;
}

void BSTree_Show(BSTree  pbst)
{
	if(pbst != NULL)
	{
		BSTree_Show(pbst->leftchild);
		printf("%d ",pbst->data);
		BSTree_Show(pbst->rightchild);
	}
}

void BSTree_Remove(BSTree * pbst,DataType x)
{
	if(*pbst == NULL)
		return;
	else if((*pbst)->data > x)
		BSTree_Remove(&(*pbst)->leftchild,x);
	else if((*pbst)->data < x)
		BSTree_Remove(&(*pbst)->rightchild,x);
	else
	{
		BSTNode * p = *pbst;
		//移除的是叶子结点
		if((*pbst)->leftchild == NULL && (*pbst)->rightchild == NULL)
		{
			free(p);
			*pbst = NULL;
		}
		else if((*pbst)->leftchild != NULL && (*pbst)->rightchild == NULL)
		{//移除的结点只有左孩子结点
			p = *pbst;
			*pbst = (*pbst)->leftchild;
			free(p);
		}
		else if((*pbst)->leftchild == NULL && (*pbst)->rightchild != NULL)
		{//移除的结点只有右孩子结点
			p = *pbst;
			*pbst = (*pbst)->rightchild;
			free(p);
		}
		else
		{
			//移除的既有左子树又有右子树，可以选择左子树中最大的或者右子树中最小的
			p = (*pbst)->leftchild;
			while(p->rightchild != NULL)
				p = p->rightchild;
			(*pbst)->data = p->data;
			BSTree_Remove(&(*pbst)->leftchild,p->data);
		}
	}
}

void BSTree_Sort(BSTree * pbst,int arr[],int * i)
{
	int j = 0;
	if(*pbst != NULL)//相当于中序遍历
	{
		BSTree_Sort(&(*pbst)->leftchild,arr,i);
		arr[*i] = (*pbst)->data;
		(*i)++;
		BSTree_Sort(&(*pbst)->rightchild,arr,i);
	}
}

void BSTree_Find_Min(BSTree pbst)
{
	if(pbst != NULL)
	{
		while(pbst->leftchild != NULL)
		{
			pbst = pbst->leftchild;
		}
		printf("Min = %d\n",pbst->data);
	}
}

void BSTree_Find_Max(BSTree pbst)
{
	if(pbst != NULL)
	{
		while(pbst->rightchild != NULL)
		{
			pbst = pbst->rightchild;
		}
		printf("Max = %d\n",pbst->data);
	}
}

void BSTree_Find(BSTree pbst,DataType x)
{
	if(pbst == NULL)
	{
		printf("你查找的值不存在!\n");
		return;
	}
	else if(pbst->data > x)
	{
		BSTree_Find(pbst->leftchild,x);
	}
	else if(pbst->data < x)
	{
		BSTree_Find(pbst->rightchild,x);
	}
	else
	{
		printf("你要找的值为:>%d,其位置为:>%p\n",pbst->data,pbst);
	}
}