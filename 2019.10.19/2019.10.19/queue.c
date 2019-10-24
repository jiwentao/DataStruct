#define _CRT_SECURE_NO_WARNINGS
#include"queue.h"

void SeqQueue_Init(SeqQueue * pQ)
{
	pQ->capacity = SeqQueue_Max;
	pQ->base = (DataType *)malloc(sizeof(DataType)*pQ->capacity);
	if(pQ->base == NULL)
		return;
	pQ->front = pQ->tail = 0;
}

void SeqQueue_In(struct SeqQueue * pQ)
{
	int val = 0;
	if(pQ->tail >= pQ->capacity)
	{
		printf("�ö�������,�������!\n");
		return;
	}
	printf("��������ӵ�ֵ:>");
	scanf("%d",&val);
	pQ->base[pQ->tail++] = val;
}

void SeqQueue_show(struct SeqQueue * pQ)
{
	int i = 0;
	if(pQ->tail == pQ->front)
	{
		printf("�ö���Ϊ��!\n");
		return;
	}
	for(i = pQ->front; i < pQ->tail; i++)
	{
		printf("%d ",pQ->base[i]);
	}
	printf("\n");
}

void SeqQueue_Out(struct SeqQueue * pQ)
{
	//int i = 0;
	if(pQ->front == pQ->tail)
	{
		printf("�ö���Ϊ��,���ܳ���!\n");
		return;
	}
	/*for(i = pQ->front; i < pQ->tail; i++)
	{
		pQ->base[i] = pQ->base[i+1];
	}
	pQ->tail--;*/
	pQ->front++;
}

void Get_Front_Val(struct SeqQueue * pQ)
{
	if(pQ->front == pQ->tail)
	{
		printf("�ö���Ϊ��,����ȡ��ͷֵ!\n");
		return;
	}
	printf("��ͷԪ�ص�ֵΪ:>%d\n",pQ->base[pQ->front]);
}

void SeqQueue_Destroy(struct SeqQueue * pQ)
{
	free(pQ->base);
	pQ->base = NULL;
	pQ->capacity = pQ->front = pQ->tail = 0;
}