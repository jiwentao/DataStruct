#define _CRT_SECURE_NO_WARNINGS
#include"liststack.h"

void ListStack_Init(ListStack * pst)
{
	*pst = NULL;
}

void ListStack_push(ListStack * pst)
{
	int val = 0;
	StackNode * New = (StackNode*)malloc(sizeof(StackNode));
	if(New == NULL)
		return;
	printf("请输入入栈的值:>");
	scanf("%d",&val);
	New->data = val;
	New->next = *pst;
	*pst = New;
}

void ListStack_show(ListStack pst)
{
	if(pst == NULL)
	{
		printf("该链栈已空!\n");
		return;
	}
	while(pst != NULL)
	{
		printf("%d ",pst->data);
		pst = pst->next;
	}
	printf("\n");
}

void ListStack_pop(ListStack * pst)
{
	ListStack p = *pst;
	*pst = p->next;
	free(p);
	p = NULL;
}

void Get_Stack_Pop_Val(ListStack pst)
{
	if(pst == NULL)
	{
		printf("该栈已空,无法取其栈顶元素!\n");
		return;
	}
	printf("栈顶元素的值为:>%d\n",pst->data);
}