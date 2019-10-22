#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"

void SeqStack_Init(struct SeqStack * pst,int sz)
{
	assert(pst != NULL);
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType*)malloc(sizeof(DataType)*pst->capacity);
	pst->top = 0;
}

void SeqStack_push(struct SeqStack * pst,DataType x)
{
	assert(pst != NULL);
	if(pst->top >= pst->capacity)
	{
		printf("该栈已满,不能进行入栈操作!\n");
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStack_show(struct SeqStack * pst)
{
	int i = 0;
	if(pst->top == 0)
	{
		printf("该栈是空栈!\n");
		return;
	}
	for(i = 0;i < pst->top; i++)
	{
		printf("%d ",pst->base[i]);
	}
	printf("\n");
}

void SeqStack_pop(struct SeqStack * pst)
{
	assert(pst != NULL);
	if(pst->top == 0)
	{
		printf("该栈已空,不能出栈!\n");
		return;
	}
	pst->top--;
}

void Get_Pop_Val(struct SeqStack * pst)
{
	assert(pst != NULL);
	if(pst->top == 0)
	{
		printf("该栈为空,不能取栈顶元素!\n");
		return;
	}
	printf("栈顶元素为:%d\n",pst->base[pst->top-1]);
}
/* 创造一个顺序栈
SeqStack * SeqStackCreate(int sz)
{
	SeqStack * pst = (SeqStack *)malloc(sizeof(SeqStack));
	if(pst == NULL)
		return;
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (DataType *)malloc(sizeof(DataType)*pst->capacity);
	assert(pst->base);
	pst->top = 0;
	return pst;
}

void SeqStack_Destroy(struct SeqStack * pst)
{
	free(pst->base);
	pst->base = NULL;
	free(pst);
	pst = NULL;	
}*/