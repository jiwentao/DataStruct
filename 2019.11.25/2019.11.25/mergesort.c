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
  归并排序：
      1.将待排序的线性表不断地切分成若干个子表，直到每个子表
	    只包含一个元素，这时，可以认为只包含一个元素的子表是
		有序表。
	  2.将子表两两合并，每合并一次，就会产生一个新的且更长的
	    有序表，重复这一步骤，直到最后只剩下一个子表，这个子
		表就是排好序的线性表。
*/
void _MergeSort(int * arr,int left,int right,int * tmp)
{
	int begin1,begin2,end1,end2,i;
	//分解
	int mid = (left+right)/2;
	if(left >= right)
		return;
	_MergeSort(arr,left,mid,tmp);
	_MergeSort(arr,mid+1,right,tmp);

	//归并
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
	//比较之后有剩余的情况，把剩余部分存储到临时空间中
	while(begin1 <= end1)
	{
		tmp[i++] = arr[begin1++];
	}
	while(begin2 <= end2)
	{
		tmp[i++] = arr[begin2++];
	}
	//将临时空间中排好序的线性表拷贝到数组中
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
	printf("归并排序为:>");
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