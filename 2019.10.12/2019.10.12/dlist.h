#ifndef _DLIST_H_
#define _DLIST_H_

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
	SORT_LIST,
	FIND_VAL,
	REVERSE,
	INSERT_VAL,
	DELETE_VAL,
	MODIFY_VAL,
	LENTH,
	CLEAR,
	DESTROY
};

typedef struct DListNode
{
	DataType data;
	struct DListNode * prev;
	struct DListNode * next;
}DListNode;

typedef struct DList
{
	DListNode * first;
	DListNode * last;
	DataType size;
}DList;

void DList_Init(struct DList * plist);
void Push_back(struct DList * plist,DataType x);
void Show_List(struct DList * plist);
void Push_front(struct DList * plist,DataType x);
void Pop_back(struct DList * plist);
void Pop_front(struct DList * plist);
DListNode * Find_val(struct DList * plist,DataType x);
void Delete_val(struct DList * plist,DataType x);
void Sort_List(struct DList * plist);
DataType Lenth_List(struct DList * plist);
void Reverse_List(struct DList * plist);
void Insert_val(struct DList * plist,DataType x);
void Modify_val(struct DList * plist,DataType x);
void Clear_List(struct DList * plist);
void Destroy_List(struct DList * plist);

#endif /*_DLIST_H_*/