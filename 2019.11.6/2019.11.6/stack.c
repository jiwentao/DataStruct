#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"
void ListStack_Init(ListStack * pls)
{
	*pls = NULL;
}

void ListStack_Push(ListStack * pls,ListStackDataType x)//Í·²å
{
	ListStackNode * p = (ListStackNode*)malloc(sizeof(ListStackNode));
	if(p == NULL)
		return;
	p->data = x;
	p->next = *pls;
	*pls = p;
}

ListStackDataType ListStack_Get_Top_Val(ListStack * pls)
{
	assert(*pls != NULL);
	return (*pls)->data;
}

void ListStack_Pop(ListStack * pls)//Í·É¾
{
	ListStackNode * p = *pls;
	*pls = p->next;
	free(p);
	p = NULL;
}