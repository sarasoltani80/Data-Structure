
#include <stdlib.h>
#include <stdio.h>


void join(long long int arr[], long long int left[], long long int right[],
	long long int l, long long int m, long long int r)
{
	long long int i; 
	for (i = 0; i <= m - l; i++)
		arr[i] = left[i];

	for (long long int j = 0; j < r - m; j++)
		arr[i + j] = right[j];
}

void split(long long int arr[], long long int left[], long long int right[],
	long long int l, long long int m, long long int r)
{
	for (long long int i = 0; i <= m - l; i++)
		left[i] = arr[i * 2];

	for (long long int i = 0; i < r - m; i++)
		right[i] = arr[i * 2 + 1];
}

void insertion_sort(long long int b[], long long int size)
{
	long long int key;
	for (long long int i = 1; i < size; i++)
	{
		key = b[i];
		long long int j = i - 1;
		for (j; b[j] > key && j >= 0; j--)
		{
			b[j + 1] = b[j];
		}
		b[j + 1] = key;
	}
}

void generateWorstCase(long long int arr[], long long int l, long long int r)
{
	if (l < r)
	{
		long long int m = l + (r - l) / 2;

		long long int* left = (long long int*)malloc((m - l + 1) * sizeof(long long int));
		long long int* right = (long long int*)malloc((r - m) * sizeof(long long int));
		split(arr, left, right, l, m, r);
		generateWorstCase(left, l, m);
		generateWorstCase(right, m + 1, r);
		join(arr, left, right, l, m, r);
	}
}


int main()
{
	long long int n;
	scanf("%lld", &n);
	long long int* array = (long long int*)malloc(n * sizeof(long long int));

	for (long long int i = 0; i < n; i++)
	{
		scanf("%lld", &array[i]);
	}

	insertion_sort(array, n);
	generateWorstCase(array, 0, n - 1);

	for (long long int i = 0; i < n; i++)
	{
		printf("%lld ", array[i]);

	}

	return 0;
}
