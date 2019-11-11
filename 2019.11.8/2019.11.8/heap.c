#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"
void Heap_Init(Heap * php,DataType sz)
{
	php->capacity = sz;
	php->size = 0;
	php->heap = (DataType*)malloc(sizeof(DataType)*php->capacity);
}

//�ѵĲ��룬ֻ���ȴ�����β�����룬Ȼ��������ϵ����㷨��ֱ�������
void Heap_Insert(Heap * php,DataType x)
{
	if(php->size >= php->capacity)
		return;
	php->heap[php->size] = x;
	_AdjustUp(php,php->size);
	php->size++;
}
void _AdjustUp(Heap * php,int start)
{
	int j = start;
	int i = (j-1)/2;//���������±���㿪ʼ������(j-1)/2;���Ǵ�1��ʼ����Ϊj/2.
	int tem = 0;
    while(j > 0)
	{
		if(php->heap[j] < php->heap[i])
		{
			tem = php->heap[i];
			php->heap[i] = php->heap[j];
			php->heap[j] = tem;
			j = i;
			i = (j-1)/2;
		}
		else
			break;
	}
}

void Heap_Show(Heap php)
{
	int i = 0;
	for(i = 0; i < php.size; i++)
	{
		printf("%d ",php.heap[i]);
	}
	printf("\n");
}//����������Ľ��:15 18 19 25 28 34 65 49 27 37

//���Ƴ�:ɾ���Ѷ���Ԫ��,���Ѷ������һ��Ԫ�ؽ���,Ȼ��ɾ�����һ��Ԫ��,�ٽ������µ���
void Heap_Remove(Heap * php)
{
	if(php->size == 0)
		return;
	php->heap[0] = php->heap[php->size-1];
	php->size--;
	_AdjustDown(php,0);
}

void _AdjustDown(Heap * php,int start)
{
	int i = start;
	int j = 2*i+1;
	int tem = 0;
	while(j < php->size)
	{   
		//Ϊ���ҵ���С��ֵ,�����ҽ��С����ڵ�����
		if(j+1 < php->size && php->heap[j] > php->heap[j+1])
			j++;
		if(php->heap[i]>php->heap[j])
		{
			tem = php->heap[i];
			php->heap[i] = php->heap[j];
			php->heap[j] = tem;
			i = j;
			j = 2*i+1;
		}
		else
			break;
	}
}

void Heap_Destroy(Heap * php)
{
	php->capacity = php->size = 0;
	free(php->heap);
	php->heap = NULL;
}

void Heap_Get_Top_Val(Heap php)
{
	printf("�Ѷ�Ԫ��Ϊ:>%d\n",php.heap[0]);
}