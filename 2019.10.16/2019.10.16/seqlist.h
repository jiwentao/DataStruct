#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DataType int
#define Max 10

enum option
{
	EXIT,
	PUSH_BACK,
	PUSH_FRONT,
	POP_BACK,
	POP_FRONT,
	SHOW_LIST,
	CAPACITY,
	INSERT_POS,
	INSERT_VAL,
	DELETE_POS,
	DELETE_VAL,
	FIND_POS,
	FIND_VAL,
	MODIFY_POS,
	MODIFY_VAL,
	SORT,
	REVERSE,
	LENTH,
	CLEAR
};

/*Ë³Ðò±íµÄ¾²Ì¬´æ´¢
typedef struct SeqList
{
	DataType arr[Max];
	size_t size;
}SeqList;
*/
//ÊýÐò±íµÄ¶¯Ì¬´æ´¢
typedef struct SeqList
{
	DataType * arr;
	size_t size;
	size_t capacity;
}SeqList;

void SeqList_Init(struct SeqList * psl);
void Push_back(struct SeqList * psl,DataType x);
void Show_list(struct SeqList * psl);
void Push_front(struct SeqList * psl,DataType x);
void Pop_back(struct SeqList * psl);
void Pop_front(struct SeqList * psl);
size_t Capacity(struct SeqList * psl);
void Insert_pos(struct SeqList * psl,int pos);
void Insert_val(struct SeqList * psl,DataType x);
int Find_pos(struct SeqList * psl,int pos);
int Find_val(struct SeqList * psl,DataType x);
#endif/*_SEQLIST_H_*/