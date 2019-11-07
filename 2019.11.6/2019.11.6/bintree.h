#ifndef _BINTREE_H_
#define _BINTREE_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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
void BinTree_Create_By_Input(struct BinTree * pbt);
void _BinTree_Create_By_Input(struct BinTreeNode ** pbt);

void BinTree_PreOrder(struct BinTree * pbt);
void _BinTree_PreOrder(struct BinTreeNode * pbt);
void BinTree_MiddleOrder(struct BinTree * pbt);
void _BinTree_MiddleOrder(struct BinTreeNode * pbt);
void BinTree_PostOrder(struct BinTree * pbt);
void _BinTree_PostOrder(struct BinTreeNode * pbt);

#endif/*_BINTREE_H_*/