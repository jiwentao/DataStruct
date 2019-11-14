#define _CRT_SECURE_NO_WARNINGS
#include"insertsort.h"
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
   直接插入排序：把待排序的记录按其关键码值大小逐个插入到一个已经排好序的有序序列中，
                 直到所有的记录插入完为止，得到一个新的有序序列
*/
void Swap(int * x,int * y)
{
	int tem = 0;
	tem = *x;
	*x = *y;
	*y = tem;
}
void Straight_Insert_Sort1(int * arr,int left,int right)
{
	int i = 0,j = 0;
	for(i = left+1; i <= right; i++)//要插入的元素（从哪到哪）
	{
		j = i;
		while(j > left && arr[j-1] > arr[j])//插入的过程
		{
			Swap(&arr[j-1],&arr[j]);
			j--;//跟最近的比较完后前移，继续比较；
		}
	}
}

void Straight_Insert_Sort2(int * arr,int left,int right)//调整顺序，减少了交换次数
{
	int i = 0,j = 0,tem = 0;
	for(i = left+1; i <= right; i++)
	{
		j = i;
		tem = arr[j];
		while(j > left && tem > arr[j-1])
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = tem;
	}
}

//本组测试数据不适合
void Straight_Insert_Sort3(int * arr,int left,int right)//增加一个哨兵位,即:数组第一个位置空出来
{
	int i = 0, j = 0;
	for(i = left+1; i <= right; i++)
	{
		j = i;
		arr[0] = arr[j];
		while(arr[0] < arr[j-1])//不用判断是否到达下边界left
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = arr[0];
	}
}
/* 
  折半插入排序：在将一个元素插入已排好序的数组的过程中，寻找插入点，
                将待插入区域的首元素设为a[low]，末元素设为a[high],
				则轮比较时将待插入元素与a[mid]相比较，其中mid=(low+high)/2,
				如果比a[mid]小，则选择a[low]到a[mid-1](high=mid-1)为新的插入区域，
				否则选择a[mid+1](low=mid+1)到a[high]为新的插入区域，
				直到low<=high不成立，即将此位置（包括low）之后所有元素后移一位，
				并将新元素插入a[low]
*/
void Binary_Insert_Sort(int * arr,int left,int right)//减少了比较次数
{
	int mid = 0,low = 0,high = 0;
	int i = 0,j = 0;
	int tem = 0;
	for(i = left+1; i <= right; i++)
	{
		tem = arr[i];
		low = left;
		high = i-1;		
		while(low <= high)
		{
			mid = (low+high)/2;
			if(arr[i] < arr[mid])
			{
				high = mid-1;
			}
			else
			{
				low = mid+1;
			}
		}
		for(j = i;j > low; j--)//只有目标元素小于比较元素时，要移位
		{
			arr[j] = arr[j-1];
		}
		arr[low] = tem;
	}
}

/*
  二路插入排序:另设一个和待排数组arr同类型的数组brr，首先将arr[1]赋值给brr[1],
  并将brr[1]看成是在排好序的序列中处于中间位置的记录，然后从arr中第二个记录开始
  依次插入到brr[1]之前或者之后的有序序列中。先将待插记录的关键字和brr[1]相比较，
  若arr[i].key<=brr[1].key,则将arr[i]插入到brr[1]之前的有序表中。反之，则将arr[i]
  插入到brr[1]之后的有序表中。在实现算法时，可将brr看成一个循环变量(数组首尾循环)，
  并设两个指针first和final分别指示排序过程中得到的有序序列中的第一个记录和最后一个
  记录在brr中的位置。(两个指针并非一般意义的指针)
*/
void TwoWay_Insert_Sort(int * arr,int left,int right)
{
	int n = right-left+1;
	int *tem = (int*)malloc(sizeof(int)*n);
	int first = 0,final = 0,i = 0,end = 0;
	int k = 0;
	tem[0] = arr[left];
	for(i = left+1; i <= right; i++)
	{
		if(arr[i] < tem[first])
		{
			first = (first-1+n)%n;//使得数组下标循环
			tem[first] = arr[i];
		}
		else if(arr[i] > tem[final])
		{
			tem[++final] = arr[i];
		}
		else//需要移动数据
		{
			end = final;
			while(arr[i] < tem[end])
			{
				tem[(end+1)%n] = tem[end];
				end = (end-1+n)%n;
			}
			tem[(end+1)%n] = arr[i];
			final++;
		}
	}

	for(i = first;k < n;)//将辅助空间中的值拷贝到原数组中
	{
		arr[k++] = tem[i];
		i = (i+1)%n;
	}

	free(tem);
	tem = NULL;
}

void TestSort(int * arr,int left,int right)
{
	printf("直接插入排序方法一:>");
	Straight_Insert_Sort1(arr,left,right);
	PrintArray(arr,left,right);
	
	printf("直接插入排序方法二:>");
	Straight_Insert_Sort2(arr,left,right);
	PrintArray(arr,left,right);

	/*printf("直接插入排序方法三:>");
	Straight_Insert_Sort3(arr,left,right);
	PrintArray(arr,left,right);*/

	printf("折半插入排序方法:>");
	Binary_Insert_Sort(arr,left,right);
	PrintArray(arr,left,right);

	printf("二路插入排序方法:>");
	TwoWay_Insert_Sort(arr,left,right);
	PrintArray(arr,left,right);
}

void TestSortEfficiency()
{
	int n = 20000,i = 0;
	time_t start = 0,end = 0;
	int *a = (int*)malloc(sizeof(int)*n);
	int *a1 = (int*)malloc(sizeof(int)*n);
	int *a2 = (int*)malloc(sizeof(int)*n);
	int *a3 = (int*)malloc(sizeof(int)*n);
	int *a4 = (int*)malloc(sizeof(int)*n);
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
	Straight_Insert_Sort1(a,0,n-1);
	end = clock();
	printf("Straight_Insert_Sort1:>%u\n",end-start);

	start = clock();
	Straight_Insert_Sort2(a1,0,n-1);
	end = clock();
	printf("Straight_Insert_Sort2:>%u\n",end-start);

	start = clock();
	Straight_Insert_Sort3(a2,0,n-1);
	end = clock();
	printf("Straight_Insert_Sort3:>%u\n",end-start);

	start = clock();
	Binary_Insert_Sort(a3,0,n-1);
	end = clock();
	printf("Binary_Insert_Sort:>%u\n",end-start);
	
	start = clock();
	TwoWay_Insert_Sort(a4,0,n-1);
	end = clock();
	printf("TwoWay_Insert_Sort:>%u\n",end-start);
}