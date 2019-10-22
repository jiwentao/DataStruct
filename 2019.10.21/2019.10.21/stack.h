#ifndef _STACK_H_
#define _STACK_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define DataType int
#define STACK_DEFAULT_SIZE 10

typedef struct SeqStack
{
	DataType * base;
	int top;
	int capacity;
}SeqStack;

void SeqStack_Init(struct SeqStack * pst,int sz);
void SeqStack_push(struct SeqStack * pst,DataType x);
void SeqStack_show(struct SeqStack * pst);
void SeqStack_pop(struct SeqStack * pst);
void Get_Pop_Val(struct SeqStack * pst);
SeqStack * SeqStackCreate(int sz);
void SeqStack_Destroy(struct SeqStack * pst);

#endif/*_STACK_H_*/