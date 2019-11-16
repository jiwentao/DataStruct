#define _CRT_SECURE_NO_WARNINGS
#include"selectsort.h"
int main()
{
	int arr[] = {6,1,2,7,9,3,4,5,10,8};
	int n = sizeof(arr)/sizeof(arr[0]);
	PrintArray(arr,0,n-1);
	TestSort(arr,0,n-1);
	TestSortEfficiency();
}