#ifndef _BST_H_
#define _BST_H_

#include<stdio.h>
#include<stdlib.h>

#define DataType int

typedef struct BSTNode
{
	DataType data;
	struct BSTNode * leftchild;
	struct BSTNode * rightchild;
}BSTNode;

typedef BSTNode* BSTree;

void BSTree_Init(BSTree * pbst);
void BSTree_Insert(BSTree * pbst,DataType x);
void BSTree_Show(BSTree pbst);
void BSTree_Remove(BSTree * pbst,DataType x);
void BSTree_Sort(BSTree * pbst,int arr[],int * i);
void BSTree_Find_Min(BSTree pbst);
void BSTree_Find_Max(BSTree pbst);
void BSTree_Find(BSTree pbst,DataType x);

#endif/*_BST_H_*/