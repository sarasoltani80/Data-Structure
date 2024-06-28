#include <stdio.h>
#include <stdlib.h>

void recursiveInsertionSort(long long int arr[], long long int n) {
    if (n <= 1)
        return;
    recursiveInsertionSort(arr, n - 1);

    long long int temp = arr[n - 1];
    long long int j = n - 2;
    while (j >= 0 && arr[j] > temp) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;
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

    recursiveInsertionSort(array, n);

    for (long long int i = 0; i < n; i++)
    {
        printf("%lld ", array[i]);

    }


}