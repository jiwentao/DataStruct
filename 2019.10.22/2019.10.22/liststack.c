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
	printf("��������ջ��ֵ:>");
	scanf("%d",&val);
	New->data = val;
	New->next = *pst;
	*pst = New;
}

void ListStack_show(ListStack pst)
{
	if(pst == NULL)
	{
		printf("����ջ�ѿ�!\n");
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
		printf("��ջ�ѿ�,�޷�ȡ��ջ��Ԫ��!\n");
		return;
	}
	printf("ջ��Ԫ�ص�ֵΪ:>%d\n",pst->data);
}