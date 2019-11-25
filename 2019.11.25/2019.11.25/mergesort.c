#define _CRT_SECURE_NO_WARNINGS
#include"mergesort.h"
void PrintArray(int * arr,int left,int right)
{
	int i = 0;
	for(i = left;i <= right; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
/*
  �鲢����
      1.������������Ա��ϵ��зֳ����ɸ��ӱ�ֱ��ÿ���ӱ�
	    ֻ����һ��Ԫ�أ���ʱ��������Ϊֻ����һ��Ԫ�ص��ӱ���
		�����
	  2.���ӱ������ϲ���ÿ�ϲ�һ�Σ��ͻ����һ���µ��Ҹ�����
	    ������ظ���һ���裬ֱ�����ֻʣ��һ���ӱ������
		������ź�������Ա�
*/
void _MergeSort(int * arr,int left,int right,int * tmp)
{
	int begin1,begin2,end1,end2,i;
	//�ֽ�
	int mid = (left+right)/2;
	if(left >= right)
		return;
	_MergeSort(arr,left,mid,tmp);
	_MergeSort(arr,mid+1,right,tmp);

	//�鲢
	begin1 = left,end1 = mid;
	begin2 = mid+1;end2 = right;
	i = left;
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(arr[begin1] < arr[begin2])
			tmp[i++] = arr[begin1++];
		else
			tmp[i++] = arr[begin2++];
	}
	//�Ƚ�֮����ʣ����������ʣ�ಿ�ִ洢����ʱ�ռ���
	while(begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	//����ʱ�ռ����ź�������Ա�����������
	memcpy(arr+left,tmp+left,sizeof(int)*(right-left+1));
}
void MergeSort(int * arr,int left,int right)
{
	int n = right - left + 1;
	int * tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(arr,left,right,tmp);
	free(tmp);
	tmp = NULL;
}

void TestSort(int *arr,int left,int right)
{
	printf("�鲢����Ϊ:>");
	MergeSort(arr,left,right);
	PrintArray(arr,left,right);
}

void TestSortEfficiency()
{
	int i = 0;
	time_t start = 0,end = 0;
	int n = 20000;
	int * a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for(i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	start = clock();
	MergeSort(a,0,n-1);
	end = clock();
	printf("MergeSort:>%u\n",end-start);
}