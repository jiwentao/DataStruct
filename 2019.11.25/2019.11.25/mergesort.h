#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void PrintArray(int * arr,int left,int right);
void TestSort(int *arr,int left,int right);
void MergeSort(int * arr,int left,int right);
void TestSortEfficiency();

#endif/*_MERGESORT_H_*/