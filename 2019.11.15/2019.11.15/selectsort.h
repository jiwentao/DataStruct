#ifndef _SELECTSORT_H_
#define _SELECTSORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintArray(int * arr,int left,int right);
void TestSort(int * arr,int left,int right);
//ֱ��ѡ������
void Straight_Select_Sort(int * arr,int left,int right);
//������
void Heap_Select_Sort(int * arr,int left,int right);

void TestSortEfficiency();

#endif/*_SELECTSORT_H_*/