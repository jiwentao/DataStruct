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
	SlistNode * p = plist->fist->next;
	while(p != NULL)
	{
		printf("%d-->",p->data);
		p = p->next;
	}
	printf("Over\n");
}