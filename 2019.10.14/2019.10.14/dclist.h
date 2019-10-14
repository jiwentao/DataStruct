#ifndef _DCLIST_H_
#define _DCLIST_H_

#include<stdio.h>
#include<stdlib.h>

#define DataType int

enum option
{
	EXIT,
	PUSH_BACK,
	PUSH_FRONT,
	POP_BACK,
	POP_FRONT,
	SHOW_LIST,
	FIND_VAL,
	INSEART_VAL,
	DELETE_VAL,
	MODIFY_VAL,
	LENTH,
	SORT,
	REVERSE,
	CLEAR,
	DESTROY
};

typedef struct DCListNode
{
	DataType data;
	struct DCListNode * prev;
	struct DCListNode * next;
}DCListNode;

typedef struct DCList
{
	DCListNode * first;
	DCListNode * last;
	DataType size;
}DCList;

void DCList_Init(struct DCList * plist);
void Push_back(struct DCList * plist,DataType x);
void Show_list(struct DCList * plist);
void Push_front(struct DCList * plist,DataType x);
void Pop_back(struct DCList * plist);
void Pop_front(struct DCList * plist);
DCListNode * Find_val(struct DCList * plist,DataType x);
DataType Lenth_list(struct DCList * plist);
void Insert_val(struct DCList * plist,DataType x);
void Delete_val(struct DCList * plist,DataType x);
void Modify_val(struct DCList * plist,DataType x);

#endif/*_DCLIST_H_*/