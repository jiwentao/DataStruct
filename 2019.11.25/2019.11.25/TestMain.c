#define _CRT_SECURE_NO_WARNINGS
#include"mergesort.h"
int main()
{
	int arr[] = {10,6,7,1,8,3,9,4,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	PrintArray(arr,0,n-1);
	TestSort(arr,0,n-1);
	TestSortEfficiency();
	return 0;
}