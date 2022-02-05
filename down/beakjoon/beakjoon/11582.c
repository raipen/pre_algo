#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000000//200000에서는 시간초과?
int list[MAX_SIZE];
int sorted[MAX_SIZE];
int size;
void merge_sort(int left, int right);
void merge(int left, int mid, int right);
int cnt=0;
int person_num;
int sum;
int cnt;
int main()
{
	scanf("%d", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &list[i]);
	}
    scanf("%d", &person_num);
    merge_sort(0, size - 1);
	return 0;
}
void merge(int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
   
}
void merge_sort( int left, int right)
{
    int mid;
    if (cnt >= person_num)
    {
        return;
    }
   if (left < right) {
        mid = (left + right) / 2;
        merge_sort( left, mid); 
        merge_sort( mid + 1, right);
        merge( left, mid, right);
        if (right - left == (size / person_num)-1)
        {
            for (int i = left; i <= right; i++)
                printf("%d ", list[i]);
            cnt++;
        }
   }
}
