#define _CRT_SECURE_NO_WARNINGS
#include"insertsort.h"
int main()
{
	int arr[] = {49,38,65,97,76,13,27,49};
	int n = sizeof(arr)/sizeof(arr[0]);
	PrintArray(arr,0,n-1);
	TestSort(arr,0,n-1);
	TestSortEfficiency();
	return 0;
}