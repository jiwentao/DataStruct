#ifndef _RADIXSORT_H_
#define _RADIXSORT_H_

#include<stdio.h>
#include<time.h>

#define RADIX 10 //初始化时桶的个数
#define K 3 //给定数据最大三位数

void PrintArray(int * arr,int left,int right);
void TestSort(int * arr,int left,int right);
void RadixSort(int * arr,int left,int right);
void TestSortEfficiency();

#endif/*_RADIXSORT_H_*/