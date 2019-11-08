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
		//�Ƴ�����Ҷ�ӽ��
		if((*pbst)->leftchild == NULL && (*pbst)->rightchild == NULL)
		{
			free(p);
			*pbst = NULL;
		}
		else if((*pbst)->leftchild != NULL && (*pbst)->rightchild == NULL)
		{//�Ƴ��Ľ��ֻ�����ӽ��
			p = *pbst;
			*pbst = (*pbst)->leftchild;
			free(p);
		}
		else if((*pbst)->leftchild == NULL && (*pbst)->rightchild != NULL)
		{//�Ƴ��Ľ��ֻ���Һ��ӽ��
			p = *pbst;
			*pbst = (*pbst)->rightchild;
			free(p);
		}
		else
		{
			//�Ƴ��ļ�������������������������ѡ�������������Ļ�������������С��
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
	if(*pbst != NULL)//�൱���������
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
		printf("����ҵ�ֵ������!\n");
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
		printf("��Ҫ�ҵ�ֵΪ:>%d,��λ��Ϊ:>%p\n",pbst->data,pbst);
	}
}