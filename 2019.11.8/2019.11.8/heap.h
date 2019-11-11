#ifndef _HEAP_H_
#define _HEAP_H_

#include<stdio.h>
#include<stdlib.h>

#define DataType int

typedef struct Heap
{
	DataType * heap;
	size_t capacity;
	size_t size;
}Heap;

void Heap_Init(Heap * php,DataType sz);
void Heap_Insert(Heap * php,DataType x);
void _AdjustUp(Heap * php,int start);
void Heap_Show(Heap php);
void Heap_Remove(Heap * php);
void _AdjustDown(Heap * php,int start);
void Heap_Destroy(Heap * php);
void Heap_Get_Top_Val(Heap php);

#endif/*_HEAP_H_*/