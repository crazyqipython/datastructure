/*
 * main.cpp
 *
 *  Created on: 2017Äê8ÔÂ13ÈÕ
 *
 */
#include <stdio.h>
#include "sort.h"

int main(){
//	int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};

//	selectsort(a, 9);

//    quiksort(arr, 0, 4);
//	printArray(a, 9);
//	printf("%d", 21/2);

	//test heapsort
//	{
//		int arr[] = {12, 11, 13, 5, 6, 7};
//		int n = sizeof(arr)/sizeof(arr[0]);
//
//		heapsort(arr, n);
//
//		printArray(arr, n);
//	}

	//mergesort
//	{
//	int arr[] = {12, 11, 13, 5, 6, 7};
//	int arr_size = sizeof(arr)/sizeof(arr[0]);
//
//	printf("Given array is \n");
//	printArray(arr, arr_size);
//
//	mergesort(arr, 0, arr_size - 1);
//
//	printf("\nSorted array is \n");
//	printArray(arr, arr_size);
//	}

//	test countsort
//	{
//	int A[8] = {2, 5, 3, 0, 2, 3, 0, 3}, B[8], i;
//	countsort(A, B, 8, 5);
//	for (i=0; i<= 7; i++)
//	{
//		printf("%d ", B[i]);
//	}
//	printf("\n");
//	}

	//test radix sort
	{
		int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
		int n = sizeof(arr)/sizeof(arr[0]);
		radixsort(arr, n);
		printArray(arr, n);
	}
	return 0;
}


