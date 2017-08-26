/*
 * sort.cpp
 *
 *  Created on: 2017��8��13��
 *
 */
#include <stdio.h>
#include "sort.h"

void insertsort(int array[], int n){
	int i, j, tmp;
	for(i = 1; i < n; i++){
		tmp = array[i];
		j = i - 1;
		//��������i-1���Ҳ���λ��
		while(j >= 0 && array[j] > tmp){
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = tmp;
	}
}

void binaryinsertsort(int array[], int n){
	int i, j, low, high, mid, tmp;
	for(i = 1; i < n; i++){
		if(array[i] < array[i - 1]){
			tmp = array[i];
			low = 0;
			high = i - 1;
			//���ֲ��Ҳ���λ��
			while(low <= high){
				mid = (low + high)/2;
				if(tmp < array[mid]){
					high = mid - 1;
				}else{
					low = mid + 1;
				}
			}
			for(j = i -1; j >= high + 1; j--){
				array[j + 1] = array[j];
			}
			array[high + 1] = tmp;
		}
	}
}

void shellsort(int array[], int n){
	int i, j, gap, tmp;
	gap = n/2;
	while(gap > 0){
		for(i = gap; i < n; i++){
			tmp = array[i];
			j = i - gap;
			while(j >= 0 && tmp < array[j]){
				array[j + gap] = array[j];
				j = j - gap;
			}
			array[j + gap] = tmp;
		}
		gap = gap/2;
	}
}

void bubbleSort(int array[], int n){
	int i, j, tmp;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n-i-1; j++){
			if(array[j] > array[j+1]){
				tmp = array[j];
				array[j] = array[j+1];
				array[j+1] = tmp;
			}
		}
	}
}

void quiksort(int array[], int s, int t){
	int i = s, j = t;
	int tmp = array[s];
	while(i != j){
		while(i < j && tmp <= array[j])
		        /*��Ѱ�ҽ������������ǣ�1���ҵ�һ��С�ڻ��ߴ���key���������ڻ�С��ȡ����������
		        ���ǽ���2��û�з�������1�ģ�����i��j�Ĵ�Сû�з�ת*/
		        {
		            j--;/*��ǰѰ��*/
		        }

		array[i] = array[j];
		        /*�ҵ�һ������������Ͱ�������ǰ��ı����ߵ�i��ֵ�������һ��ѭ����key��
		        a[left]����ô���Ǹ�key��*/

		        while(i < j && tmp >= array[i])
		        /*����i�ڵ�������ǰѰ�ң�ͬ�ϣ�����ע����key�Ĵ�С��ϵֹͣѭ���������෴��
		        ��Ϊ����˼���ǰ����������ӣ������������ߵ�����С��key�Ĺ�ϵ�෴*/
		        {
		            i++;
		        }

		        array[j] = array[i];
	}
	array[i] = tmp;
	quiksort(array, s, i-1);
	quiksort(array, i+1, t);
}

void selectsort(int array[], int n){
	int i,j,k;
	int tmp;
	for(i=0; i<n; i++){
		k = i;
		for(j = i+1; j<n; j++){
			if(array[j]<array[k])
				k=j;
		}
		if(k != i){
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
		}
	}
}

void heapify(int arr[], int n, int i){
	int tmp;
	int largest = i;
	int l = 2*i + 1; //���㿪ʼ����
	int r = 2*i + 2;

	if(l < n && arr[l] > arr[largest])
		largest = l;
	if(r < n && arr[r] > arr[largest])
		largest = r;
	if(largest != i){
		tmp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = tmp;
		heapify(arr, n, largest);
	}
}

void heapsort(int array[], int n){
	int tmp;
	for(int i = n / 2 -1; i>=0; i--){
		heapify(array, n, i);
	}
	for(int i = n-1; i>=0; i--){
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		heapify(array, i, 0);
	}
}

void merge(int array[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r-m;

	int L[n1], R[n2];
	for(i=0; i<n1; i++){
		L[i] = array[l+i];
	}
	for(j=0; j<n2; j++){
		R[j] = array[m+1+j];
	}

	i = 0;
	j = 0;
	k = l;
	while(i<n1 && j<n2){
		if(L[i] <= R[i]){
			array[k] = L[i];
			i++;
		}
		else{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		array[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		array[k] = R[j];
		j++;
		k++;
	}
}

void mergesort(int arr[], int l, int r){
	if(l<r){
		int m = l + (r-l)/2;
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void countsort(int *A, int *B, int array_size, int k){
	int c[k+1], i, value, pos;
	for(i=0; i<=k; i++){
		c[i] = 0;
	}
	for(i=0; i<array_size; i++){
		c[A[i]]++;  					//������Ҫ�����ֵ�ĸ���
	}
	for(i=1; i<=k; i++){
		c[i] = c[i] +c[i-1];
	}
	for(i=array_size-1; i>=0; i--){
		value = A[i];
		pos = c[value];
		B[pos-1] = value;
		c[value]--;
	}
}

int getmax(int arr[], int n){
	int max=arr[0];
	for(int i=1; i<n; i++){
		if(arr[i]>max)
			max = arr[i];
	}
	return max;
}

void countsort1(int arr[], int n, int exp){
	int output[n];
	int i, count[10]={0};

	for(int i=0; i<n; i++){
		count[(arr[i]/exp)%10]++;
	}

	for(i=1; i<10; i++){
		count[i] +=count[i-1];
	}

	for(i=n-1; i>=0; i--){
		output[count[(arr[i]/exp)%10] - 1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	for(i=0; i<n; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int n){
	int m = getmax(arr, n);

	for(int exp=1; m/exp>0; exp*=10){
		countsort1(arr,n, exp);
	}
}

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
