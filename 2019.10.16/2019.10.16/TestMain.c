#define _CRT_SECURE_NO_WARNINGS
#include"seqlist.h"
void menu()
{
	printf("************************************\n");
	printf("*****1.push_back   2.push_front*****\n");
	printf("*****3.pop_back    4.pop_front *****\n");
	printf("*****5.show_list   6.capacity  *****\n");
	printf("*****7.insert_pos  8.insert_val*****\n");
	printf("*****9.delete_pos 10.delete_val*****\n");
	printf("*****11.find_pos  12.find_val  *****\n");
	printf("*****13.modify_pos14.modify_val*****\n");
	printf("*****15.sort      16.reverse   *****\n");
	printf("*****17.lenth     18.clear     *****\n");
	printf("************   0.exit   ************\n");
	printf("************************************\n");
}
int main()
{
	DataType input = 0,item = 0,pos = 0;
	SeqList mylist;
	SeqList_Init(&mylist);
	do
	{
		menu();
		printf("���������ѡ��:>");
		scanf("%d",&input);
		switch(input)
		{
		case EXIT:
			break;
		case PUSH_BACK:
			printf("��������Ҫ�����ֵ:>");
			while(scanf("%d",&item) == 1 && item != -1)
			{
				Push_back(&mylist,item);
			}
			break;
		case PUSH_FRONT:
			printf("��������Ҫ�����ֵ:>");
			while(scanf("%d",&item) == 1 && item != -1)
			{
				Push_front(&mylist,item);
			}
			break;
		case POP_BACK:
			Pop_back(&mylist);
			break;
		case POP_FRONT:
			Pop_front(&mylist);
			break;
		case SHOW_LIST:
			Show_list(&mylist);
			break;
		case CAPACITY:
			item = Capacity(&mylist);
			printf("��˳��������Ϊ:%d\n",item);
			break;
		case INSERT_POS:
			printf("��������Ҫ�����λ��:>");
			scanf("%d",&pos);
			Insert_pos(&mylist,pos);
			break;
		case INSERT_VAL:
			printf("��������Ҫ�����ֵ:>");
			scanf("%d",&item);
			Insert_val(&mylist,item);
			break;
		case DELETE_POS:
			Delete_pos(&mylist);
			break;
		case DELETE_VAL:
			printf("��������Ҫɾ����ֵ:>");
			scanf("%d",&item);
			Delete_val(&mylist,item);
			break;
		case FIND_POS:
			printf("��������Ҫ���ҵ�λ��:>");
			scanf("%d",&pos);
			item = Find_pos(&mylist,pos);
			if(item == -1)
			{
				printf("����ҵ�λ�÷Ƿ�!\n");
			}
			else
				printf("����ҵ�λ��Ϊ:>%d\n",item);
			break;
		case FIND_VAL:
			printf("��������Ҫ���ҵ�ֵ:>");
			scanf("%d",&item);
			pos = Find_val(&mylist,item);
			if(pos == -1)
			{
				printf("��Ҫ���ҵ�ֵ������!\n");
			}
			else
				printf("%d��˳����е�λ��Ϊ%d\n",item,pos);
			break;
		case MODIFY_POS:
			printf("�������޸�ǰ��λ��:>");
			scanf("%d",&item);
			Modify_pos(&mylist,item);
			break;
		case MODIFY_VAL:
			printf("�������޸�ǰ��ֵ:>");
			scanf("%d",&item);
			Modify_val(&mylist,item);
			break;
		case SORT:
			Sort_list(&mylist);
			break;
		case REVERSE:
			Reverse_list(&mylist);
			break;
		case LENTH:
			Lenth(&mylist);
			break;
		case CLEAR:
			Clear_list(&mylist);
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
			break;
		}
		system("pause");
		system("cls");
	}while(input);
}