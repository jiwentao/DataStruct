#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct SlistNode
{
	int data;
	struct SlistNode * next;
}SlistNode;

typedef struct Slist
{
	SlistNode * first;
	SlistNode * last;
	size_t size;
}Slist;

void Slist_Init(struct Slist * plist);
void Slist_Push_Back(struct Slist * plist,int x);
void Slist_Clear(struct Slist * plist);

#endif/*_SLIST_H_*/