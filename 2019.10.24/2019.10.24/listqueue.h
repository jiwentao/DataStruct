#ifndef _LISTQUEUE_H_
#define _LISTQUEUE_H_

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

#define DataType int

typedef struct ListQueueNode
{
	DataType data;
	struct ListQueueNode * next;
}ListQueueNode;

typedef struct ListQueue
{
	ListQueueNode * front;
	ListQueueNode * tail;
}ListQueue;

void ListQueue_Init(ListQueue * pq);
void ListQueue_In(ListQueue * pq);
void ListQueue_Show(ListQueue * pq);
void ListQueue_Out(ListQueue * pq);
void Get_Front_Val(ListQueue * pq);
void ListQueue_Destroy(ListQueue * pq);

#endif/*_LISTQUEUE_H_*/