#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int chicken[2000000];
int tmp[2000000];
int n, k;
int cnt = 0;

void QuickSort(int* arr, int left, int right);

int main()
{
    int i, j;

    scanf("%d", &n);
    cnt = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &chicken[i]);
    }

    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        QuickSort(&chicken[i * n / k], 0, n / k - 1);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", chicken[i]);
    }

    return 0;
}

void QuickSort(int* arr, int left, int right) {
    int L = left, R = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (L <= R) {
        while (arr[L] < pivot) L++;
        while (arr[R] > pivot) R--;

        if (L <= R) {
            temp = arr[L];
            arr[L] = arr[R];
            arr[R] = temp;
            L++;
            R--;
        }
    }
    if (left < R)
        QuickSort(arr, left, R);
    if (L < right)
        QuickSort(arr, L, right);
}