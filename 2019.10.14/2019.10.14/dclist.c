#define _CRT_SECURE_NO_WARNINGS
#include"dclist.h"

DCListNode * _Buy_Node(DataType x)
{
	DCListNode * p = (DCListNode *)malloc(sizeof(DCListNode));
	p->prev = p->next = NULL;
	p->data = x;
	return p;
}

void DCList_Init(struct DCList * plist)
{
	DCListNode * New = _Buy_Node(0);
	if(New == NULL)
		return;
	plist->first= plist->last = New;
	plist->first->prev = plist->first;
	plist->first->next = plist->first;
	plist->size = 0;
}

void Push_back(struct DCList * plist,DataType x)
{
	DCListNode * New = _Buy_Node(x);
	if(New == NULL)
		return;
	plist->last->next = New;
	New->prev = plist->last;
	New->next = plist->first;
	plist->first->prev = New;
	plist->last = New;
	plist->size++;
}

void Show_list(struct DCList * plist)
{
	DCListNode * p = plist->first->next;
	while(p != plist->first)
	{
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("over\n");
}

void Push_front(struct DCList * plist,DataType x)
{
	DCListNode * New = _Buy_Node(x);
	if(New == NULL)
		return;
	New->next = plist->first->next;
	plist->first->next->prev = New;
	plist->first->next = New;
	New->prev = plist->first;
	plist->size++;
}

void Pop_back(struct DCList * plist)
{
	DCListNode * p = plist->last;
	if(plist->size == 0)
		return;
	plist->last = plist->last->prev;
	plist->last->next = plist->first;
	plist->first->prev = plist->last;
	free(p);
	p = NULL;
	plist->size--;
}

void Pop_front(struct DCList * plist)
{
	DCListNode * p = plist->first->next;
	if(plist->size == 0)
		return;
	plist->first->next = p->next;
	p->next->prev = plist->first;
	free(p);
	p = NULL;
	plist->size--;
}

DCListNode * Find_val(struct DCList * plist,DataType x)
{
	DCListNode * p = plist->first->next;
	while(p != plist->first && p->data != x)
	{
		p = p->next;
	}
	if(p == plist->first)
		return NULL;
	return p;
}

void Insert_val(struct DCList * plist,DataType x)
{
	DCListNode * New = _Buy_Node(x);
	DCListNode * p = plist->first->next;
	if(New == NULL)
		return;
	while(p != plist->first && p->data < New->data)
	{
		p = p->next;
	}

	if(New->data == p->data)
	{
		free(New);
		return;
	}
	//底下代码的简化
	    New->prev = p->prev;
		New->next = p;
		p->prev->next = New;
	    p->prev = New;
		if(p == plist->first)
			plist->last = New;
#if 0
	if(p == plist->first)
	{
		plist->last->next = New;
		New->prev = plist->last;
		plist->last = New;
		plist->last->next = plist->first;
		plist->first->prev = plist->last;
	}
	else
	{
		New->prev = p->prev;
		New->next = p;
		p->prev->next = New;
	    p->prev = New;
	}
#endif
	plist->size++;
}

void Delete_val(struct DCList * plist,DataType x)
{
	DCListNode * p = Find_val(plist,x);
	if(p == NULL)
	{
		printf("你要删除的值不存在!\n");
		return;
	}
	
	p->next->prev = p->prev;
	p->prev->next = p->next;
	if(p == plist->last)
	{
		plist->last = p->prev;
	}
	free(p);
	plist->size--;
}

void Modify_val(struct DCList * plist,DataType x)
{
	DataType Val = 0;
	DCListNode * p = Find_val(plist,x);
	if(p == NULL)
	{
		printf("你要修改的值不存在!\n");
		return;
	}
	printf("请输入修改后的值:>");
	scanf("%d",&Val);
	p->data = Val;
}

DataType Lenth_list(struct DCList * plist)
{
	return plist->size;
}

