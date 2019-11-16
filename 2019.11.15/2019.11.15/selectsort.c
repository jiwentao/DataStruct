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
  ֱ��ѡ������:��һ�δ�R[0]~R[n-1]��ѡȡ��Сֵ����R[0]������
               �ڶ��δ�R[1]~R[n-1]��ѡȡ��Сֵ����R[1]������
			   ��i�δ�R[i-1]~R[n-1]��ѡȡ��Сֵ����R[i-1]������
			   ��n-1�δ�R[n-2]~R[n-1]��ѡȡ��Сֵ����R[n-2]������
			   �ܹ�ͨ��n-1�Σ��õ�һ�����������С������������С�
*/
int Get_Min_Index(int * arr,int left,int right)//ѡȡ��Сֵ
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
		index = Get_Min_Index(arr,i,right);//ֻ�ǽ���
		if(index != i)
		{
			tmp = arr[i];
			arr[i] = arr[index];
			arr[index] = tmp;
		}
	}
}

/*
   ������:1.�������У�����һ����ʼ�ѣ�����ѻ�С���ѣ�
          2.�����ѵĵ�һ�������һ��Ԫ��
	      3.�ų����һ��Ԫ�أ������е�һ��Ԫ�ص������ڶ�����������ɶ�
	      4.�ٴν����ѵĵ�һ���͵����ڶ���Ԫ��
		  5.�ظ���3����ֱ���������
  ����ѵĹ��죺
            ��һ�δ�������Ѵ��м�ڵ㿪ʼ(�ڵ���ʼֵΪ1)��
			���ε���һ���ڵ㣬������һ�Σ��Ժ󴴽������
			���ӵ�һ���ڵ㿪ʼ������ֻ�迼�����ӻ����Һ��ӣ�
	             �����и��׶��������ĺ��ӡ�
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
	printf("ֱ��ѡ������:>");
	Straight_Select_Sort(arr,left,right);
	PrintArray(arr,left,right);

	printf("������:>");
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