#define _CRT_SECURE_NO_WARNINGS
#include"radixsort.h"
int main()
{
	int arr[] = {278,109,63,930,589,184,505,269,8,83};
	int n = sizeof(arr)/sizeof(arr[0]);
	PrintArray(arr,0,n-1);
	TestSort(arr,0,n-1);
	TestSortEfficiency();
	return 0;
}