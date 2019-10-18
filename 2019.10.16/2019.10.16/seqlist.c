#define _CRT_SECURE_NO_WARNINGS
#include"seqlist.h"

int SeqListIsFull(SeqList * psl)
{
	return psl->size >= psl->capacity;
}

void SeqList_Inc(SeqList * psl)
{
	assert(psl != NULL);
	psl->arr = (DataType*)realloc(psl->arr,sizeof(DataType)*(psl->capacity+Max));
	if(psl->arr == NULL)
		return ;
	psl->capacity += Max;
}
void SeqList_Init(struct SeqList * psl)
{
	psl->capacity = Max;
	psl->arr = (DataType *)malloc(sizeof(DataType)*psl->capacity);
	psl->size = 0;	
}

void Push_back(struct SeqList * psl,DataType x)
{
	if(SeqListIsFull(psl))
		SeqList_Inc(psl);
	psl->arr[psl->size++] = x;
}

void Push_front(struct SeqList * psl,DataType x)
{
	int i = 0;
	assert(psl != NULL);
	if(SeqListIsFull(psl))
		SeqList_Inc(psl);
	for(i = psl->size; i > 0; i--)
	{
		psl->arr[i] = psl->arr[i-1];
	}
	psl->arr[i] = x;
	psl->size++;
}

void Pop_back(struct SeqList * psl)
{
	assert(psl != NULL);
	if(psl->size == 0)
	{
		printf("顺序表已空,不能删除!\n");
		return;
	}
	psl->size--;
}

void Pop_front(struct SeqList * psl)
{
	int i = 0;
	assert(psl != NULL);
	if(psl->size == 0)
	{
		printf("该顺序表已空,不能删除!\n");
		return;
	}
	for(i = 0; i < psl->size; i++)
	{
		psl->arr[i] = psl->arr[i+1];
	}
	psl->size--;
}

void Show_list(struct SeqList * psl)
{
	int i = 0;
	if(psl->size == 0)
	{
		printf("数序表目前为空!\n");
		return;
	}
	for(i = 0;i < psl->size; i++)
	{
		printf("%d ",psl->arr[i]);
	}
	printf("\n");
}

size_t Capacity(struct SeqList * psl)
{
	assert(psl);
	return psl->capacity;
}

int Find_pos(struct SeqList * psl,int pos)
{
	int i = 0;
	assert(psl != NULL);
	for(i = 0; i < psl->size; i++)
	{
		if(i == pos)
			return i;
	}
	return -1;
}

void Insert_pos(struct SeqList * psl,int pos)
{
	int val = 0,i;
	assert(psl);
	if(SeqListIsFull(psl))
	     SeqList_Inc(psl);
	printf("请输入你要插入的值:>");
	scanf("%d",&val);
	if(pos < 0 || pos > psl->size)
	{
		printf("你插入的位置非法!\n");
		return;
	}
	for(i = psl->size; i > pos; i--)
	{
		psl->arr[i] = psl->arr[i-1];
	}
	psl->arr[pos] = val;
	psl->size++;
}

void Insert_val(struct SeqList * psl,DataType x)
{
	int i = 0;
	assert(psl);
	if(SeqListIsFull(psl))
		SeqList_Inc(psl);
	for(i = psl->size-1;i > 0 && x < psl->arr[i]; i--)
	{
		psl->arr[i+1] = psl->arr[i];
	}
	psl->arr[i+1] = x;
	psl->size++;
}

int Find_val(struct SeqList * psl,DataType x)
{
	int i = 0;
	assert(psl != NULL);
	for(i = 0; i < psl->size; i++)
	{
		if(psl->arr[i] == x)
			return i;
	}
	return -1;
}