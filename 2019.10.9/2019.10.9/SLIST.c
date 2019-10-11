#define _CRT_SECURE_NO_WARNINGS
#include"slist.h"
SlistNode * _Buynode(DataType x)
{
	SlistNode * s = (SlistNode *)malloc(sizeof(SlistNode));
	assert(s != NULL);
	s->next = NULL;
	s->data = x;
	return s;
}
void SlistInit(struct Slist * plist)//����������
{
	//���ȴ���һ�����
	SlistNode * s = _Buynode(0);
	if(s == NULL)
		return;
	//Ȼ��������
	plist->fist = plist->last = s;
	plist->size = 0;
}

void Push_back(struct Slist * plist,DataType x)
{
	SlistNode * New = _Buynode(x);
	if(New == NULL)
		return;
	plist->last->next = New;
	plist->last = New;
	plist->size++;
}

void Show_List(struct Slist * plist)
{
	SlistNode * p;
	assert(plist->fist != NULL);
    p = plist->fist->next;
	while(p != NULL)
	{
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("Over\n");
}

void Push_front(struct Slist * plist,DataType x)
{
	SlistNode * New = _Buynode(x);
	if(New == NULL)
		return;
	New->next = plist->fist->next;
	plist->fist->next = New;
	//ע�⣺��������Ƿ�Ϊ���һ�����޸�βָ��
	if(plist->size == 0)
		plist->last = New;
	plist->size++;
}

void Pop_back(struct Slist * plist)
{
	SlistNode * p = plist->fist;
	//�ж��Ƿ��н��
	if(plist->size == 0)
		return;
	//�ҵ�β����ǰһ�����
	while(p->next != plist->last)
	{
		p = p->next;
	}
	p->next = NULL;
	//ɾ���ڵ���Ҫ�ͷ�
	free(plist->last);
	plist->last = p;
	plist->size--;
}

void Pop_front(struct Slist * plist)
{
	SlistNode * p ;
	if(plist->size == 0)
		return;
	p = plist->fist->next;
	plist->fist->next = p->next;
	free(p);
	plist->size--;
	//ֻ��һ���������
	if(plist->size == 0)
		plist->last = plist->fist;
}

void Insert_val(struct Slist * plist,DataType x)
{
	SlistNode * p = plist->fist;
	SlistNode * New = _Buynode(x);
	if(New == NULL)
		return;
	while(p->next != NULL && p->next->data < x)
	{
		p = p->next;
	}
	if(p->next == NULL)
	{
		p->next = New;
		plist->last = New;
	}
	else
	{
		New->next = p->next;
		p->next = New;
	}
	plist->size++;
}

SlistNode * Find_val(struct Slist * plist,DataType x)
{
	SlistNode * p = plist->fist->next;
	while(p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}
#if 1
void Delete_val(struct Slist * plist,DataType x)//����һ
{
	SlistNode * q;
	SlistNode * p = Find_val(plist,x);
	if(NULL == p)
		printf("Ҫɾ����ֵ������!\n");
	q = plist->fist;
	while(q->next != p)
	{
		q = q->next;
	}
	if(p == plist->last)
		plist->last = q;
	q->next = p->next;
	free(p);
	plist->size--;
}
#endif
#if 0
void Delete_val(struct Slist * plist,DataType x)//������
{
	SlistNode * q = NULL;
	SlistNode * p = plist->fist;
	while(p->next != NULL && p->next->data != x)
	{
		p = p->next;
	}
	if(p->next == NULL)
	    return;
	q = p->next;
	if(q == plist->last)
	{
		plist->last = p;
	}
	p->next = q->next;
	free(q);
	plist->size--;
}
#endif
void Reverse(struct Slist * plist)
{
	SlistNode * p1,*p2,*p3;
	if(plist->size <= 1)
		return;
	p1 = NULL;
	p2 = plist->fist->next;
    p3 = p2->next;

	plist->last = p2;
	//����ָ��ͬʱ����
	while(p2 != NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if(p3 != NULL)
			p3 = p3->next;
	}
	plist->fist->next = p1;
}

void Sort(struct Slist * plist)
{
	SlistNode * p1,* p2,* p3;
	if(plist->size <= 1)
		return;
	p2 = plist->fist->next;
	p3 = p2->next;
	plist->last = p2;
	plist->last->next = NULL;
	p2 = p3;
	while(p2 != NULL)
	{
		p3 = p3->next;
		p1 = plist->fist;
		while(p1->next != NULL && p1->next->data < p2->data)
		{
			p1 = p1->next;
		}
		if(p1->next == NULL)
		{
			p1->next = p2;
			plist->last = p2;
			p2->next = NULL;
		}
		else
		{
			p2->next = p1->next;
			p1->next = p2;
		}
		p2 = p3;
	}
}

DataType Slist_Lenth(struct Slist * plist)
{
	return plist->size;
}

void Modify_val(struct Slist * plist,DataType x)
{
	SlistNode * p = plist->fist;
	DataType val;
	printf("�������޸ĺ��ֵ:>");
	scanf("%d",&val);
	while(p != NULL && p->data != x)
	{
		p = p->next;
	}
	if(p == NULL)
	{
		printf("��Ҫ�޸ĵ�ֵ������!\n");
		return;
	}
	p->data = val;
}

void Clear_Slist(struct Slist * plist)
{
	SlistNode * p = plist->fist->next;
	while(p != NULL)
	{
		plist->fist->next = p->next;
		free(p);
		p = plist->fist->next;
	}
	plist->last = plist->fist;
	plist->size = 0;
}

void Destroy_Slist(struct Slist * plist)
{
	Clear_Slist(plist);
	free(plist->fist);
	plist->fist = plist->last = NULL;
}