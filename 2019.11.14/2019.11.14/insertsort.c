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
   ֱ�Ӳ������򣺰Ѵ�����ļ�¼����ؼ���ֵ��С������뵽һ���Ѿ��ź�������������У�
                 ֱ�����еļ�¼������Ϊֹ���õ�һ���µ���������
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
	for(i = left+1; i <= right; i++)//Ҫ�����Ԫ�أ����ĵ��ģ�
	{
		j = i;
		while(j > left && arr[j-1] > arr[j])//����Ĺ���
		{
			Swap(&arr[j-1],&arr[j]);
			j--;//������ıȽ����ǰ�ƣ������Ƚϣ�
		}
	}
}

void Straight_Insert_Sort2(int * arr,int left,int right)//����˳�򣬼����˽�������
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

//����������ݲ��ʺ�
void Straight_Insert_Sort3(int * arr,int left,int right)//����һ���ڱ�λ,��:�����һ��λ�ÿճ���
{
	int i = 0, j = 0;
	for(i = left+1; i <= right; i++)
	{
		j = i;
		arr[0] = arr[j];
		while(arr[0] < arr[j-1])//�����ж��Ƿ񵽴��±߽�left
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = arr[0];
	}
}
/* 
  �۰���������ڽ�һ��Ԫ�ز������ź��������Ĺ����У�Ѱ�Ҳ���㣬
                ���������������Ԫ����Ϊa[low]��ĩԪ����Ϊa[high],
				���ֱȽ�ʱ��������Ԫ����a[mid]��Ƚϣ�����mid=(low+high)/2,
				�����a[mid]С����ѡ��a[low]��a[mid-1](high=mid-1)Ϊ�µĲ�������
				����ѡ��a[mid+1](low=mid+1)��a[high]Ϊ�µĲ�������
				ֱ��low<=high��������������λ�ã�����low��֮������Ԫ�غ���һλ��
				������Ԫ�ز���a[low]
*/
void Binary_Insert_Sort(int * arr,int left,int right)//�����˱Ƚϴ���
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
		for(j = i;j > low; j--)//ֻ��Ŀ��Ԫ��С�ڱȽ�Ԫ��ʱ��Ҫ��λ
		{
			arr[j] = arr[j-1];
		}
		arr[low] = tem;
	}
}

/*
  ��·��������:����һ���ʹ�������arrͬ���͵�����brr�����Ƚ�arr[1]��ֵ��brr[1],
  ����brr[1]���������ź���������д����м�λ�õļ�¼��Ȼ���arr�еڶ�����¼��ʼ
  ���β��뵽brr[1]֮ǰ����֮������������С��Ƚ������¼�Ĺؼ��ֺ�brr[1]��Ƚϣ�
  ��arr[i].key<=brr[1].key,��arr[i]���뵽brr[1]֮ǰ��������С���֮����arr[i]
  ���뵽brr[1]֮���������С���ʵ���㷨ʱ���ɽ�brr����һ��ѭ������(������βѭ��)��
  ��������ָ��first��final�ֱ�ָʾ��������еõ������������еĵ�һ����¼�����һ��
  ��¼��brr�е�λ�á�(����ָ�벢��һ�������ָ��)
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
			first = (first-1+n)%n;//ʹ�������±�ѭ��
			tem[first] = arr[i];
		}
		else if(arr[i] > tem[final])
		{
			tem[++final] = arr[i];
		}
		else//��Ҫ�ƶ�����
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

	for(i = first;k < n;)//�������ռ��е�ֵ������ԭ������
	{
		arr[k++] = tem[i];
		i = (i+1)%n;
	}

	free(tem);
	tem = NULL;
}

/*
   ϣ������(��С��������):��ȡһ��С��n������d1��Ϊ��һ�����������ļ���ȫ����¼���顣
                          ���о���Ϊd1�ı����ļ�¼����ͬһ�����С����ڸ����ڽ���ֱ��
						  ��������Ȼ��ȡ�ڶ�������d2<d1�ظ������ķ��������ֱ����
						  ȡ������dt=1(dt<dt-1...<d2<d1),�����м�¼����ͬһ���н���ֱ��
						  ��������Ϊֹ��                         
*/
void _Shell_Insert_Sort1(int * arr,int left,int right,int gap)
{
	int i = 0;
	for(i = left; i <= right-gap; i++)
	{
		if(arr[i+gap] < arr[i])
		{
			int end = i;
			int tem = arr[end+gap];
			while(tem < arr[end])
			{
				arr[end+gap] = arr[end];
				end -= gap;
			}
			arr[end+gap] = tem;
		}
	}
}
int dlta[] = {5,3,2,1};
void Shell_Insert_Sort1(int * arr,int left,int right)
{
	int n = sizeof(dlta)/sizeof(dlta[0]);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		_Shell_Insert_Sort1(arr,left,right,dlta[i]);
	}
}

void Shell_Insert_Sort2(int * arr,int left,int right)
{
	int gap = right - left + 1;
	int i = 0,end = 0,tem = 0;
	while(gap > 1)
	{
		gap = gap/3 +1;
		for(i = left; i <= right-gap; i++)
		{
			if(arr[i+gap] < arr[i])
			{
				end = i;
				tem = arr[end+gap];
				while(end >= left && tem < arr[end])
				{
					arr[end+gap] = arr[end];
					end -= gap; 
				}
				arr[end+gap] = tem;
			}
		}
	}
}

void TestSort(int * arr,int left,int right)
{
	printf("ֱ�Ӳ������򷽷�һ:>");
	Straight_Insert_Sort1(arr,left,right);
	PrintArray(arr,left,right);
	
	printf("ֱ�Ӳ������򷽷���:>");
	Straight_Insert_Sort2(arr,left,right);
	PrintArray(arr,left,right);

	/*printf("ֱ�Ӳ������򷽷���:>");
	Straight_Insert_Sort3(arr,left,right);
	PrintArray(arr,left,right);*/

	printf("�۰�������򷽷�:>");
	Binary_Insert_Sort(arr,left,right);
	PrintArray(arr,left,right);

	printf("��·�������򷽷�:>");
	TwoWay_Insert_Sort(arr,left,right);
	PrintArray(arr,left,right);

	printf("ϣ���������򷽷�һ:>");
	Shell_Insert_Sort1(arr,left,right);
	PrintArray(arr,left,right);

	printf("ϣ���������򷽷���:>");
	Shell_Insert_Sort2(arr,left,right);
	PrintArray(arr,left,right);
}

void TestSortEfficiency()
{
	int n = 40000,i = 0;
	time_t start = 0,end = 0;
	int *a = (int*)malloc(sizeof(int)*n);
	int *a1 = (int*)malloc(sizeof(int)*n);
	int *a2 = (int*)malloc(sizeof(int)*n);
	int *a3 = (int*)malloc(sizeof(int)*n);
	int *a4 = (int*)malloc(sizeof(int)*n);
	int *a5 = (int*)malloc(sizeof(int)*n);
	int *a6 = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for(i = 0; i < n; i++)
	{
		a[i] = rand();
		a1[i] = a[i];
		a2[i] = a[i];
		a3[i] = a[i];
		a4[i] = a[i];
		a5[i] = a[i];
		a6[i] = a[i];
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

	start = clock();
	Shell_Insert_Sort1(a5,0,n-1);
	end = clock();
	printf("Shell_Insert_Sort1:>%u\n",end-start);

	start = clock();
	Shell_Insert_Sort2(a6,0,n-1);
	end = clock();
	printf("Shell_Insert_Sort2:>%u\n",end-start);
}