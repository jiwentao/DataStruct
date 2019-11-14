#ifndef _INSERTSORT_H_
#define _INSERTSORT_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void PrintArray(int * arr,int left,int right);
void TestSort(int * arr,int left,int right);
//ֱ�Ӳ�������
void Straight_Insert_Sort1(int * arr,int left,int right);
void Straight_Insert_Sort2(int * arr,int left,int right);
void Straight_Insert_Sort3(int * arr,int left,int right);
//�۰��������
void Binary_Insert_Sort(int * arr,int left,int right);
//��·��������
void TwoWay_Insert_Sort(int * arr,int left,int right);

void TestSortEfficiency();

#endif/*_INSERTSORT_H_*/