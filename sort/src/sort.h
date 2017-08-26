/*
 * sort.h
 *
 *  Created on: 2017Äê8ÔÂ13ÈÕ
 *
 */

#ifndef SORT_H_
#define SORT_H_

void insertsort(int array[], int n);
void binaryinsertsort(int array[], int n);
void shellsort(int array[], int n);
void bubbleSort(int arr[], int n);
void quiksort(int array[], int s, int t);
void selectsort(int array[], int n);
void heapify(int arr[], int n, int i);
void heapsort(int array[], int n);
void mergesort(int array[], int l, int r);
void merge(int array[], int l, int m, int r);
void countsort(int *A, int *B, int array_size, int k);
void radixsort(int arr[], int n);
void printArray(int arr[], int n);



#endif /* SORT_H_ */
