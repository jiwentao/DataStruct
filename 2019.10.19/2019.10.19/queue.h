#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<stdio.h>
#include<stdlib.h>

#define DataType int
#define SeqQueue_Max 10

typedef struct SeqQueue
{
	DataType * base;
	size_t capacity;
	int front;
	int tail;
}SeqQueue;

void SeqQueue_Init(struct SeqQueue * pQ);
void SeqQueue_In(struct SeqQueue * pQ);
void SeqQueue_show(struct SeqQueue * pQ);
void SeqQueue_Out(struct SeqQueue * pQ);
void Get_Front_Val(struct SeqQueue * pQ);
void SeqQueue_Destroy(struct SeqQueue * pQ);

#endif/*_QUEUE_H_*/