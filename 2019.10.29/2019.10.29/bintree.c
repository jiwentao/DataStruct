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

#include"queue.h"
/* 先将二叉树根节点入队，然后出队，访问该节点，如果有左子树，则将左子树根节点入队；
如果有右子树，则将右子树根节点入队。然后出队，对出队节点访问，如此循环 */
void BinTree_LevelOrder(struct BinTree * pbt)
{
	_BinTree_LevelOrder(pbt->root);
}
void _BinTree_LevelOrder(struct BinTreeNode * pbt)
{
	if(pbt != NULL)
	{
		ListQueue lq;
		ListQueue_Init(&lq);
		ListQueue_En(&lq,pbt);
		while(!((&lq)->start == NULL))
		{
			BinTreeNode * p = ListQueue_Front_Val(&lq);
			ListQueue_Del(&lq);
			printf("%c ",p->data);
			if(p->leftchild != NULL)
				ListQueue_En(&lq,p->leftchild);
			if(p->rightchild != NULL)
				ListQueue_En(&lq,p->rightchild);
		}
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

BinTreeNode * BinTree_Parent(struct BinTree * pbt,DataType key)
{
	return _BinTree_Parent(pbt->root,key);
}
BinTreeNode * _BinTree_Parent(struct BinTreeNode * pbt,DataType key)
{
	BinTreeNode * pr = NULL;
	BinTreeNode * p = _BinTree_Find(pbt,key);
	if(pbt == NULL || p == NULL || pbt == p)
		return NULL;
	if(pbt->leftchild == p || pbt->rightchild == p)
		return pbt;
	pr = _BinTree_Parent(pbt->leftchild,key);
	if(pr != NULL)
		return pr;
	return _BinTree_Parent(pbt->rightchild,key);
}

void BinTree_Clone(struct BinTree * pbt,struct BinTree * pbt1)
{
	pbt1->root = _BinTree_Clone(pbt->root);
}
BinTreeNode * _BinTree_Clone(struct BinTreeNode * pbt)
{
	BinTreeNode * p = NULL;
	if(pbt == NULL)
		return NULL;
	else
	{
		p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		p->data = pbt->data;
		p->leftchild = _BinTree_Clone(pbt->leftchild);
		p->rightchild = _BinTree_Clone(pbt->rightchild);
		return p;
	}
}

int BinTree_IsEqual(struct BinTree * pbt,struct BinTree * pbt1)
{
	return _BinTree_IsEqual(pbt->root,pbt1->root);
}
int _BinTree_IsEqual(struct BinTreeNode * pbt,struct BinTreeNode * pbt1)
{
	if(pbt == NULL && pbt1 == NULL)
		return 1;
	if(pbt == NULL || pbt1 == NULL)
		return 0;
	return (pbt->data == pbt1->data)
		&& _BinTree_IsEqual(pbt->leftchild,pbt1->leftchild)
		&& _BinTree_IsEqual(pbt->rightchild,pbt1->rightchild);
}

void BinTree_Create_By_Str(struct BinTree * pbt,DataType * str,int * i)
{
	pbt->root = _BinTree_Create_By_Str(str,i);
}
BinTreeNode * _BinTree_Create_By_Str(DataType * str,int * i)
{
	BinTreeNode * p = NULL;
	if(str[*i] == '#' || str[*i] == '\0')
		return NULL;
	else
	{
		p = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		p->data = str[*i];
		(*i)++;
		p->leftchild = _BinTree_Create_By_Str(str,i);
		(*i)++;
		p->rightchild = _BinTree_Create_By_Str(str,i);
	}
    return p;
}

void BinTree_Create_By_VLR_LVR(struct BinTree * pbt,char * vlr,char * lvr,int n)
{
	pbt->root = _BinTree_Create_By_VLR_LVR(vlr,lvr,n);
}
BinTreeNode * _BinTree_Create_By_VLR_LVR(char * vlr,char * lvr,int n)
{
	int i = 0;
	BinTreeNode * pbt =  NULL;
	if(n == 0)
		return NULL;
	while(lvr[i] != vlr[0])
		i++;
	pbt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	pbt->data = lvr[i];
	pbt->leftchild = _BinTree_Create_By_VLR_LVR(vlr+1,lvr,i);
	pbt->rightchild = _BinTree_Create_By_VLR_LVR(vlr+i+1,lvr+i+1,n-i-1);
	return pbt;
}

void BinTree_Create_By_LVR_LRV(BinTree * pbt,char * lvr,char * lrv,int n)
{
	pbt->root = _BinTree_Create_By_LVR_LRV(lvr,lrv,n);
}
BinTreeNode * _BinTree_Create_By_LVR_LRV(char * lvr,char * lrv,int n)
{
	int i = 0;
	BinTreeNode * pbt = NULL;
	if(n == 0)
		return NULL;
	while(lvr[i] != lrv[n-1])
		i++;
	pbt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
	pbt->data = lvr[i];
	pbt->rightchild = _BinTree_Create_By_LVR_LRV(lvr+i+1,lrv+i,n-i-1);
	pbt->leftchild = _BinTree_Create_By_LVR_LRV(lvr,lrv,i);
	return pbt;
}