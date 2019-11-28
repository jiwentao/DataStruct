#define _CRT_SECURE_NO_WARNINGS
#include"slist.h"

SlistNode * _BuyNode(int x)
{
	SlistNode * p = (SlistNode*)malloc(sizeof(SlistNode));
	assert(p);
	p->data = x;
	p->next = NULL;
	return p;
}
void Slist_Init(struct Slist * plist)
{
	SlistNode * s = _BuyNode(0);
	if(s == NULL)
		return;
	plist->first = plist->last = s;
	plist->size = 0;
}

void Slist_Push_Back(struct Slist * plist,int x)
{
	SlistNode * New = _BuyNode(x);
	if(New == NULL)
		return;
	plist->last->next = New;
	plist->last = New;
	plist->size++;
}

void Slist_Clear(struct Slist * plist)
{
	SlistNode * p = plist->first->next;
	while(p != NULL)
	{
		plist->first->next = p->next;
		free(p);
		p = plist->first->next;
	}
	 plist->last = plist->first;
	 plist->size = 0;
}