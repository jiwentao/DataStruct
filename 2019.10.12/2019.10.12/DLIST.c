#define _CRT_SECURE_NO_WARNINGS
#include"dlist.h"
DListNode * _Buy_Node(DataType x)
{
	DListNode * p = (DListNode *)malloc(sizeof(DListNode));
	if(NULL == p)
		return;
	p->prev = p->next = NULL;
	p->data = x;
	return p;
}
void DList_Init(struct DList * plist)
{
	DListNode * New = _Buy_Node(0);
	if(New == NULL)
		return;
	plist->first = plist->last = New;
	plist->size = 0;
}

void Push_back(struct DList * plist,DataType x)
{
	DListNode * New = _Buy_Node(x);
	if(New == NULL)
		return;
	plist->last->next = New;
	New->prev = plist->last;
	plist->last = New;
	plist->size++;
}

void Show_List(struct DList * plist)
{
	DListNode * p = plist->first->next;
	while(p != NULL)
	{
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("Over\n");
}

void Push_front(struct DList * plist,DataType x)
{
	DListNode * New = _Buy_Node(x);
	if(New == NULL)
		return;
	
	/*if(plist->size == 0)
	{
		plist->first->next = New;
		New->prev = plist->first;
		plist->last = New;
	}
	else
	{
		New->next = plist->first->next;
		plist->first->next->prev = New;
		plist->first->next = New;
		New->prev = plist->first;
	}*/
    //对上述代码的优化
	New->next = plist->first->next;
	if(plist->first->next != NULL)
		plist->first->next->prev = New;
	plist->first->next = New;
	New->prev = plist->first;

	if(plist->size == 0)
		plist->last = New;

	plist->size++;
}

void Pop_back(struct DList * plist)
{
	DListNode * p = plist->first;
	if(plist->size == 0)
		return;
	while(p->next != plist->last)
	{
		p = p->next;
	}
	p->next = NULL;
	free(plist->last);
	plist->last = p;
	plist->size--;
}

void Pop_front(struct DList * plist)
{
	DListNode * p = plist->first->next;
	if(plist->size == 0)
		return;
	plist->first->next = p->next;
	if(p->next != NULL)
		p->next->prev = plist->first;
	free(p);
	if(plist->size == 1)
		plist->last = plist->first;
	plist->size--;
}

DListNode * Find_val(struct DList * plist,DataType x)
{
	DListNode * p = plist->first->next;
	while(p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}

void Delete_val(struct DList * plist,DataType x)
{
	DListNode * p = Find_val(plist,x);
	if(p == NULL)
	{
		printf("你要删除的值不存在!\n");
		return;
	}
	p->prev->next = p->next;
	if(p->next != NULL)
		p->next->prev = p->prev;
	else
		plist->last = p->prev;
	free(p);
	plist->size--;
}

void Sort_List(struct DList * plist)
{
	DListNode *p1,*p2,*p3;
	if(plist->size <= 1)
		return;
	p2 = plist->first->next;
	p3 = p2->next;
	plist->last = p2;
	plist->last->next = NULL;
	p2 = p3;
	while(p2 != NULL)
	{
		p3 = p3->next;
		p1 = plist->first;
		while(p1->next != NULL && p1->next->data < p2->data)
		{
			p1 = p1->next;
		}
		if(p1->next == NULL)
		{
			p1->next = p2;
			p2->prev = p1;
			plist->last = p2;
			p2->next = NULL;
		}
		else
		{
			p2->next = p1->next;
			p1->next->prev = p2;
			p1->next = p2;
			p2->prev = p1;
		}
		p2 = p3;
	}
}

DataType Lenth_List(struct DList * plist)
{
	return plist->size;
}

void Reverse_List(struct DList * plist)
{
	DListNode *p1,*p2,*p3;
	if(plist->size <= 1)
		return;
	p1 = NULL;
	p2 = plist->first->next;
	p3 = p2->next;
	plist->last = p2;
	while(p2 != NULL)
	{
		p2->next = p1;
		if(p1 != NULL)
			p1->prev = p2;
		p1 = p2;
		p2 = p3;
		if(p3 != NULL)
			p3 = p3->next;
	}
	plist->first->next = p1;
	p1->prev = plist->first;
}

void Insert_val(struct DList * plist,DataType x)
{
	DListNode * p = plist->first;
	DListNode * q = _Buy_Node(x);
	if(q == NULL)
		return;
	while(p->next != NULL && p->next->data < x)
	{
		p = p->next;
	}
	if(p->next == NULL)
	{
		//p->next = q;
		//q->prev = p;
		plist->last = q;
	}
	else
	{
		q->next = p->next;
		p->next->prev = q;
		//p->next = q;
	    //q->prev = p;
	}
	//优化后
	p->next = q;
	q->prev = p;
	plist->size++;
}

void Modify_val(struct DList * plist,DataType x)
{
	DataType val = 0;
	DListNode * p = Find_val(plist,x);
	printf("请输入修改后的值:>");
	scanf("%d",&val);
	if(p == NULL)
		printf("你要修改的值不存在!\n");
	p->data = val;
}

void Clear_List(struct DList * plist)
{
	DListNode * p = plist->first->next;
	while(p != NULL)
	{
		plist->first->next = p->next;
		if(p->next != NULL)
		   p->next->prev = plist->first;
		free(p);
		p = plist->first->next;
		plist->size--;
	}
	plist->last = plist->first;
}

void Destroy_List(struct DList * plist)
{
	Clear_List(plist);
	free(plist->first);
	plist->first = plist->last = NULL;
}