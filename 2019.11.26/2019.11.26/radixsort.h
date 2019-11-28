#ifndef _RADIXSORT_H_
#define _RADIXSORT_H_

#include<stdio.h>
#include<time.h>

#define RADIX 10 //��ʼ��ʱͰ�ĸ���
#define K 3 //�������������λ��

void PrintArray(int * arr,int left,int right);
void TestSort(int * arr,int left,int right);
void RadixSort(int * arr,int left,int right);
void TestSortEfficiency();

#endif/*_RADIXSORT_H_*/