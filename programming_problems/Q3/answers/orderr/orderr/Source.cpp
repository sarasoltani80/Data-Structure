
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void merge(long long int arr[], long long int l, long long int m, long long int r)
{
	long long int i, j, k;
	long long int n1 = m - l + 1;
	long long int n2 = r - m;


	long long int* L = (long long int*)malloc(n1 * sizeof(long long int));
	long long int* R = (long long int*)malloc(n2 * sizeof(long long int));

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(long long int arr[], long long int l, long long int r)
{
	if (l < r) {

		long long int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void insertionSort(long long int arr[], long long int n)
{
	long long int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


int main()
{
	long long int i;
	long long int count = 300000;
	long long int upper = 10000;
	long long int lower = -10000;
	long long int* array = (long long int*)malloc(count * sizeof(long long int));

	for (i = 0; i < count; i++) {
		long long int num = (rand() %
			(upper - lower + 1)) + lower;
		array[i] = num;
	}

	clock_t t;
	t = clock();
	mergeSort(array, 0, count-1);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("insertion sort timer: %f s \n", time_taken);


	clock_t T;
	T = clock();
	insertionSort(array, count);
	T = clock() - T;
	double timetaken = ((double)T) / CLOCKS_PER_SEC;
	printf("merge sort timer: %f s \n", timetaken);

	return 0;
}
