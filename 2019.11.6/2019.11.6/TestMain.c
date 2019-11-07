#define _CRT_SECURE_NO_WARNINGS
#include"bintree.h"
int main()
{
	BinTree bt;
	BinTree_Init(&bt);
	BinTree_Create_By_Input(&bt);

	printf("VLR:>");
	BinTree_PreOrder(&bt);
	printf("\n");

	printf("LVR:>");
	BinTree_MiddleOrder(&bt);
	printf("\n");

	printf("LRV:>");
	BinTree_PostOrder(&bt);
	printf("\n");

	return 0;
}