#define _CRT_SECURE_NO_WARNINGS
#include"slist.h"
SlistNode * _Buynode(DataType x)
{
	SlistNode * s = (SlistNode *)malloc(sizeof(SlistNode));
	assert(s != NULL);
	s->next = NULL;
	s->data = x;
	return s;
}
void SlistInit(struct Slist * plist)//创建单链表
{
	//首先创建一个结点
	SlistNode * s = _Buynode(0);
	if(s == NULL)
		return;
	//然后构造链表
	plist->fist = plist->last = s;
	plist->size = 0;
}

void Push_back(struct Slist * plist,DataType x)
{
	SlistNode * New = _Buynode(x);
	if(New == NULL)
		return;
	plist->last->next = New;
	plist->last = New;
	plist->size++;
}

void Show_List(struct Slist * plist)
{
	SlistNode * p = plist->fist->next;
	while(p != NULL)
	{
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("Over\n");
}

void Push_front(struct Slist * plist,DataType x)
{
	SlistNode * New = _Buynode(x);
	if(New == NULL)
		return;
	New->next = plist->fist->next;
	plist->fist->next = New;
	//注意：看插入的是否为最后一个，修改尾指针
	if(plist->size == 0)
		plist->last = New;
	plist->size++;
}

void Pop_back(struct Slist * plist)
{
	SlistNode * p = plist->fist;
	//判断是否有结点
	if(plist->size == 0)
		return;
	//找到尾结点的前一个结点
	while(p->next != plist->last)
	{
		p = p->next;
	}
	p->next = NULL;
	//删除节点需要释放
	free(plist->last);
	plist->last = p;
	plist->size--;
}

void Pop_front(struct Slist * plist)
{
	SlistNode * p ;
	if(plist->size == 0)
		return;
	p = plist->fist->next;
	plist->fist->next = p->next;
	free(p);
	plist->size--;
	//只有一个结点的情况
	if(plist->size == 0)
		plist->last = plist->fist;
}

void Insert_val(struct Slist * plist,DataType x)
{
	SlistNode * p = plist->fist;
	SlistNode * New = _Buynode(x);
	if(New == NULL)
		return;
	while(p->next != NULL && p->next->data < x)
	{
		p = p->next;
	}
	if(p->next == NULL)
	{
		p->next = New;
		plist->last = New;
	}
	else
	{
		New->next = p->next;
		p->next = New;
	}
	plist->size++;
}

SlistNode * Find_val(struct Slist * plist,DataType x)
{
	SlistNode * p = plist->fist->next;
	while(p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}
#if 0
void Delete_val(struct Slist * plist,DataType x)
{
	SlistNode * q;
	SlistNode * p = Find_val(plist,x);
	if(p = NULL)
		printf("要删除的值不存在!\n");
	q = plist->fist;
	while(q->next != p)
	{
		q = q->next;
	}
	if(p == plist->last)
		plist->last = q;
	q->next = p->next;
	free(p);
	plist->size--;
}
#endif