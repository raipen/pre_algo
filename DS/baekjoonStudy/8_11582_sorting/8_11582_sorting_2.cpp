#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int chicken[1048577];
int n, k;
int cnt = 0;

void QuickSort(int left, int right);

int main()
{
    int i;
    scanf("%d", &n);
    cnt = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &chicken[i]);
    }

    scanf("%d", &k);

    for (i = 1; i <= k; i++)
    {
        QuickSort(n / k * (i - 1), n / k * i - 1);
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", chicken[i]);
    }

    return 0;
}

void QuickSort(int left, int right) {
    int L = left, R = right;
    int temp;
    int pivot = chicken[(left + right) / 2];

    while (L <= R) {
        while (chicken[L] < pivot) L++;
        while (chicken[R] > pivot) R--;

        if (L <= R) {
            temp = chicken[L];
            chicken[L] = chicken[R];
            chicken[R] = temp;
            L++;
            R--;
        }
    }
    if (left < R)
        QuickSort(left, R);
    if (L < right)
        QuickSort(L, right);
}