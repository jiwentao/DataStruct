#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include"bintree.h"
#define ListStackDataType BinTreeNode*

typedef struct ListStackNode
{
	ListStackDataType data;
	struct ListStackNode * next;
}ListStackNode;

typedef ListStackNode* ListStack;

void ListStack_Init(ListStack * pls);
void ListStack_Push(ListStack * pls,ListStackDataType x);
ListStackDataType ListStack_Get_Top_Val(ListStack * pls);
void ListStack_Pop(ListStack * pls);

#endif/*_STACK_H_*/