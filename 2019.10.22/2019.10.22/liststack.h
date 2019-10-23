#ifndef _LISTSTACK_H_
#define _LISTSTACK_H_

#include<stdio.h>
#include<stdlib.h>

#define DataType int

typedef struct StackNode
{
	DataType data;
	struct StackNode * next;
}StackNode;

typedef StackNode* ListStack;

void ListStack_Init(ListStack * pst);
void ListStack_push(ListStack * pst);
void ListStack_show(ListStack pst);
void ListStack_pop(ListStack * pst);
void Get_Stack_Pop_Val(ListStack pst);

#endif/*_LISTSTACK_H_*/