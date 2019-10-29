#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

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

#endif/*_BINTREE_H_*/