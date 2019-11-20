#ifndef _EXCHANGE_H_
#define _EXCHANGE_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintArray(int * arr,int left,int right);
void TestSort(int * arr,int left,int right);

void BubbleSort_1(int * arr,int left,int right);
void BubbleSort_2(int * arr,int left,int right);
void QuickSort_1(int * arr,int left,int right);
void QuickSort_2(int * arr,int left,int right);
void QuickSort_3(int * arr,int left,int right);
void TestSortEfficiency();

#endif/*_EXCHANGE_H_*/