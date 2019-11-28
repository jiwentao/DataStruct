#define _CRT_SECURE_NO_WARNINGS
#include"radixsort.h"
#include"slist.h"

Slist list[RADIX];//Ͱ��0 1 2 3 4 5 6 7 8 9

void PrintArray(int * arr,int left,int right)
{
	int i = 0;
	for(i = left; i <= right; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int GetKey(int value,int k)
{
	int key = 0;
	/* 
	   iΪ���ݵĸ�λ����ʮλ���߰�λ��
	   ѭ����Ϊ�˵õ�ȡ����Ͱ���±�ֵ
	*/
	while(k >= 0)
	{
		key = value % 10;
		value /= 10;
		k--;
	}
	return key;
}
void Distribute(int * arr,int left,int right,int k)
{
	int i = 0,key = 0;
	for(i = left; i <= right; i++)
	{
		key = GetKey(arr[i],k);//�õ�Ͱ���±꣬��k��Ϊ�˿���ѭ��
		Slist_Push_Back(&list[key],arr[i]);//�����ݷŵ���Ӧ�±��������
	}
}
void Collect(int * arr)
{
	int i = 0,k = 0;
	SlistNode * p = NULL;
	for(i = 0; i < RADIX; i++)
	{
		if(&list[i] != NULL)
		{
			p = list[i].first->next;
			while(p != NULL)
			{
				arr[k++] = p->data;
				p = p->next;
			}
		}
	}
	for(i = 0; i < RADIX; i++)
	{
		Slist_Clear(&list[i]);
	}
}
void RadixSort(int * arr,int left,int right)
{
	int i = 0;
	for(i = 0; i < RADIX; i++)
	{
		Slist_Init(&list[i]);
	}

	for(i = 0; i < K; i++)
	{
		//1 �ַ�
		Distribute(arr,left,right,i);
		//2 ����
		Collect(arr);
	}
}

void TestSort(int * arr,int left,int right)
{
	printf("��������Ϊ:>");
	RadixSort(arr,left,right);
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
	RadixSort(a,0,n-1);
	end = clock();
	printf("RadixSort:>%u\n",end-start);
}