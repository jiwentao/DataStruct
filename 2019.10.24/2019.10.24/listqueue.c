#define _CRT_SECURE_NO_WARNINGS
#include"listqueue.h"

void ListQueue_Init(ListQueue * pq)
{
	assert(pq != NULL);
	pq->front = pq->tail = NULL;
}

void ListQueue_In(ListQueue * pq)
{
	int val;
	ListQueueNode * New = (ListQueueNode*)malloc(sizeof(ListQueueNode));
	if(New == NULL)
		return;
	printf("请输入入队的值:>");
	scanf("%d",&val);
	New->data = val;
	New->next = NULL;
	if(pq->front == NULL)
	{
		pq->front = pq->tail = New;
	}
	else
	{
		pq->tail->next = New;
		pq->tail = New;
	}
}

void ListQueue_Show(ListQueue * pq)
{
	ListQueueNode * p = pq->front;
	assert(pq != NULL);
	if(pq->front == NULL)
	{
		printf("该队列为空!\n");
		return;
	}
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

void ListQueue_Out(ListQueue * pq)
{
	ListQueueNode * p = NULL;
	assert(pq != NULL);
	if(pq->front == NULL)
	{
		printf("该队列为空,不能出队!\n");
		return;
	}
	p = pq->front;
	pq->front = pq->front->next;
	free(p);
	p = NULL;	
}

void Get_Front_Val(ListQueue * pq)
{
	assert(pq != NULL);
	if(pq->front == NULL)
	{
		printf("该队列为空,不能取队头值!\n");
		return;
	}
	printf("该队头的值为:>%d\n",pq->front->data);
}

void ListQueue_Destroy(ListQueue * pq)
{
	ListQueueNode * p = pq->front;
	while(p != NULL)
	{
		pq->front = pq->front->next;
		free(p);
		p = pq->front;
	}
	pq->front = pq->tail = NULL;
}