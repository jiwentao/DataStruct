#ifndef _SLIST_H_
#define _SLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define DataType int

enum Option
{
	EXIT,
	PUSH_BACK,
	PUSH_FRONT,
	POP_BACK,
	POP_FRONT,
	INSERT_VAL,
	DELETE_VAL,
	FIND_VAL,
	REVERSE,
	SORT,
	LENTH,
	MODIFY_VAL,
	SHOW_SLIST,
	CLEAR,
	DESTROY
};

typedef struct SlistNode
{
	DataType data;
	struct SlistNode * next;
}SlistNode;

typedef struct Slist
{
	SlistNode * fist;
	SlistNode * last;
	size_t size;
}Slist;

void SlistInit(struct Slist * plist);
void Push_back(struct Slist * plist,DataType x);
void Show_List(struct Slist * plist);
void Push_front(struct Slist * plist,DataType x);
void Pop_back(struct Slist * plist);
void Pop_front(struct Slist * plist);
void Insert_val(struct Slist * plist,DataType x);
SlistNode * Find_val(struct Slist * plist,DataType x);
void Delete_val(struct Slist * plist,DataType x);
#endif/*_SLIST_H_*/