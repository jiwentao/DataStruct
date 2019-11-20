#define _CRT_SECURE_NO_WARNINGS
#include"exchange.h"
void PrintArray(int * arr,int left,int right)
{
	int i = 0;
	for(i = left; i <= right; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void BubbleSort_1(int * arr,int left,int right)
{
	int i = 0, j = 0,tem = 0;
	for(i = left; i < right; i++)//right = n-1
	{
		for(j = left; j < right-i; j++)
		{
			
			if(arr[j] > arr[j+1])
			{
				tem = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tem;
			}
		}
	}
}

void BubbleSort_2(int * arr,int left,int right)
{
	int i = 0, j = 0,tem = 0;
	int is_swap = 0;
	for(i = left; i < right; i++)
	{
		for(j = left; j < right - i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				tem  = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tem;
				is_swap = 1;
			}
		}
		//若从某一趟开始已经完成排序，就可以减少趟数
		if(is_swap == 0)
			break;
		else
			is_swap = 0;
	}
}

void Swap(int * x, int * y)
{
	int tem = 0;
	tem = *x;
	*x = *y;
	*y = tem;
}
//hoare版：每交换一次，比较方向也需要交换
int _Partition_1(int * arr,int left,int right)
{
	int key = arr[left];
	while(left < right)
	{
		while(left < right && key <= arr[right])
			right--;
		Swap(&arr[left],&arr[right]);
		while(left < right && arr[left] < key)
			left++;
		Swap(&arr[left],&arr[right]);
	}
	return left;
}

void QuickSort_1(int * arr,int left,int right)
{
	if(left < right)
	{
		int pos = _Partition_1(arr,left,right);
		QuickSort_1(arr,left,pos-1);
		QuickSort_1(arr,pos+1,right);
	}
}

/*
挖坑法：取消两个元素的交换，将小的放在左边，大的放在右边，
        空出来的就是key值,减少了交换次数
*/
int _Partition_2(int * arr,int left,int right)
{
	int key = arr[left];
	while(left < right)
	{
		while(left < right && arr[right] >= key)
			right--;
		arr[left] = arr[right];
		while(left < right && arr[left] < key)
			left++;
		arr[right] = arr[left];
	}
	arr[left] = key;
	return left;
}
void QuickSort_2(int * arr,int left,int right)
{
	if(left < right)
	{
		int pos = _Partition_2(arr,left,right);
		QuickSort_2(arr,left,pos-1);
		QuickSort_2(arr,pos+1,right);
	}
}

/*
  快速排序的优化(前后指针版本):
    1、三数取中法选key 
	2、递归到小的子区间时，可以考虑使用插入排序
*/
int GetMidIndex(int * arr,int left,int right)
{
	int mid = (left+right)/2;
	if(arr[left] > arr[mid] && arr[left] < arr[right])
		return left;
    if(arr[left] < arr[mid] && arr[mid] < arr[right])
		return mid;
	return right;
}
int _Partition_3(int * arr,int left,int right)
{
	int key = 0,pos = 0,i = 0;
	int index = GetMidIndex(arr,left,right);
	if(index != left)
		Swap(&arr[index],&arr[left]);
	key = arr[left];
	pos = left;
	/*选择左边值不动，把后面的数小的放前面，把大的换的后面*/
	for(i = left+1; i <= right; i++)
	{
		if(arr[i] < key)
		{
			pos++;
			if(pos != i)
			{
				Swap(&arr[pos],&arr[i]);
			}
		}
	}
	Swap(&arr[left],&arr[pos]);//最后把这个分界值放到中间
	return pos;
}
void QuickSort_3(int * arr,int left,int right)
{
	if(left < right)
	{
		int pos = _Partition_3(arr,left,right);
		QuickSort_3(arr,left,pos-1);
		QuickSort_3(arr,pos+1,right);
	}
}

void TestSort(int * arr,int left,int right)
{
	printf("冒泡排序方法一:>");
	BubbleSort_1(arr,left,right);
	PrintArray(arr,left,right);

	printf("冒泡排序方法二:>");
	BubbleSort_2(arr,left,right);
	PrintArray(arr,left,right);

	printf("快速排序方法一:>");
	QuickSort_1(arr,left,right);
	PrintArray(arr,left,right);

	printf("快速排序方法二:>");
	QuickSort_2(arr,left,right);
	PrintArray(arr,left,right);

	printf("快速排序方法三:>");
	QuickSort_3(arr,left,right);
	PrintArray(arr,left,right);
}

void TestSortEfficiency()
{
	int n = 20000;
	int i = 0;
	time_t start = 0,end = 0;
	int * a = (int*)malloc(sizeof(int)*n);
	int * a1 = (int*)malloc(sizeof(int)*n);
	int * a2 = (int*)malloc(sizeof(int)*n);
	int * a3 = (int*)malloc(sizeof(int)*n);
	int * a4 = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for(i = 0; i < n; i++)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
	}

	start = clock();
	BubbleSort_1(a,0,n-1);
	end = clock();
	printf("BubbleSort_1:>%u\n",end-start);

	start = clock();
	BubbleSort_2(a1,0,n-1);
	end = clock();
	printf("BubbleSort_2:>%u\n",end-start);

	start = clock();
	QuickSort_1(a2,0,n-1);
	end = clock();
	printf("QuickSort_1:>%u\n",end-start);

	start = clock();
	QuickSort_2(a3,0,n-1);
	end = clock();
	printf("QuickSort_2:>%u\n",end-start);

	start = clock();
	QuickSort_3(a4,0,n-1);
	end = clock();
	printf("QuickSort_3:>%u\n",end-start);
}