#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

#define DataType char

typedef struct BinTreeNode
{
	DataType data;
	struct BinTreeNode * leftchild;
	struct BinTreeNode * rightchild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode * root;
}BinTree;

void BinTree_Init(struct BinTree * pbt);
void _BinTree_Creat_By_Input(BinTreeNode ** pbt);
void BinTree_Creat_By_Input(struct BinTree * pbt);
void BinTree_PreOrder(struct BinTree * pbt);
void _BinTree_PreOrder(struct BinTreeNode * pbt);
void BinTree_MiddleOrder(struct BinTree * pbt);
void _BinTree_MiddleOrder(struct BinTreeNode * pbt);
void BinTree_PostOrder(struct BinTree * pbt);
void _BinTree_PostOrder(struct BinTreeNode * pbt);
size_t BinTree_Node_Sum(struct BinTree * pbt);
size_t _BinTree_Node_Sum(struct BinTreeNode * pbt);
//void BinTree_Node_Sum(struct BinTree * pbt);
//void _BinTree_Node_Sum(struct BinTreeNode * pbt,int * sum);
size_t BinTree_Height(struct BinTree * pbt);
size_t _BinTree_Height(struct BinTreeNode * pbt);
BinTreeNode * BinTree_Find(struct BinTree * pbt,DataType key);
BinTreeNode * _BinTree_Find(struct BinTreeNode * pbt,DataType key);
BinTreeNode * BinTree_Parent(struct BinTree * pbt,DataType key);
BinTreeNode * _BinTree_Parent(struct BinTreeNode * pbt,DataType key);
void BinTree_Clone(struct BinTree * pbt,struct BinTree * pbt1);
BinTreeNode * _BinTree_Clone(struct BinTreeNode * pbt);
int BinTree_IsEqual(struct BinTree * pbt,struct BinTree * pbt1);
int _BinTree_IsEqual(struct BinTreeNode * pbt,struct BinTreeNode * pbt1);
void BinTree_Create_By_Str(struct BinTree * pbt,DataType * str,int * i);
BinTreeNode * _BinTree_Create_By_Str(DataType * str,int * i);
void BinTree_LevelOrder(struct BinTree * pbt);
void _BinTree_LevelOrder(struct BinTreeNode * pbt);
//根据前序和中序创建树
void BinTree_Create_By_VLR_LVR(struct BinTree * pbt,char * vlr,char * lvr,int n);
BinTreeNode * _BinTree_Create_By_VLR_LVR(char * vlr,char * lvr,int n);
//根据中序和后序创建树
void BinTree_Create_By_LVR_LRV(BinTree * pbt,char * lvr,char * lrv,int n);
BinTreeNode * _BinTree_Create_By_LVR_LRV(char * lvr,char * lrv,int n);

#endif/*_BINTREE_H_*/