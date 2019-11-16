#define _CRT_SECURE_NO_WARNINGS
#include"selectsort.h"
void PrintArray(int * arr,int left,int right)
{
	int i = 0;
	for(i = left; i <= right; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

/*
  直接选择排序:第一次从R[0]~R[n-1]中选取最小值，与R[0]交换，
               第二次从R[1]~R[n-1]中选取最小值，与R[1]交换，
			   第i次从R[i-1]~R[n-1]中选取最小值，与R[i-1]交换，
			   第n-1次从R[n-2]~R[n-1]中选取最小值，与R[n-2]交换，
			   总共通过n-1次，得到一个按排序码从小到大的有序序列。
*/
int Get_Min_Index(int * arr,int left,int right)//选取最小值
{
	int min = arr[left];
	int index = left;
	int i = 0;
	for(i = left+1; i <= right; i++)
	{
		if(min > arr[i])
		{
			min = arr[i];
			index = i;
		}
	}
	return index;
}
void Straight_Select_Sort(int * arr,int left,int right)
{
	int i = 0,index = 0,tmp = 0;
	for(i = left; i < right; i++)
	{	
		index = Get_Min_Index(arr,i,right);//只是交换
		if(index != i)
		{
			tmp = arr[i];
			arr[i] = arr[index];
			arr[index] = tmp;
		}
	}
}

/*
   堆排序:1.根据序列，构建一个初始堆（大根堆或小根堆）
          2.交换堆的第一个和最后一个元素
	      3.排除最后一个元素，将序列第一个元素到倒数第二个重新整理成堆
	      4.再次交换堆的第一个和倒数第二个元素
		  5.重复第3步，直到完成排序
  大根堆的构造：
            第一次创建大根堆从中间节点开始(节点起始值为1)，
			依次到第一个节点，除过第一次，以后创建大根堆
			都从第一个节点开始（这样只需考虑左孩子或者右孩子）
	             【所有父亲都大于它的孩子】
*/
void Swap(int * x,int * y)
{
	int tem = 0;
	tem = *x;
	*x = *y;
	*y = tem;
}
void Adjust_Down(int * arr,int left,int right,int start)
{
	int n = right - left +1;
	int i = start;
	int j = 2 * i + 1;
	while(j < n)
	{
		if(j+1<n && arr[j]<arr[j+1])
			j++;
		if(arr[i] < arr[j])
		{
			Swap(&arr[i],&arr[j]);
			i = j;
			j = 2 * i + 1;
		}
		else
			break;
	}
}
void Heap_Select_Sort(int * arr,int left,int right)
{
	int n = right - left + 1;
	int cur = n/2 - 1;
	int end = 0;
	while(cur != -1)
	{
		Adjust_Down(arr,left,right,cur);
		cur--;
	}
    end = right;
	while(end > left)
	{
		Swap(&arr[end],&arr[left]);
		end--;
		Adjust_Down(arr,left,end,0);
	}
}

void TestSort(int * arr,int left,int right)
{
	printf("直接选择排序:>");
	Straight_Select_Sort(arr,left,right);
	PrintArray(arr,left,right);

	printf("堆排序:>");
	Heap_Select_Sort(arr,left,right);
	PrintArray(arr,left,right);
}

void TestSortEfficiency()
{
	int n = 10000;
	int i = 0;
	time_t start = 0,end = 0;
	int * a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for(i = 0; i < n; i++)
	{
		a[i] = rand();
	}

	start = clock();
	Straight_Select_Sort(a,0,n-1);
	end = clock();
	printf("Straight_Select_Sort:>%d\n",end-start);

	start = clock();
	Heap_Select_Sort(a,0,n-1);
	end = clock();
	printf("Heap_Select_Sort:>%d\n",end-start);
}