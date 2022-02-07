#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int m[1000000];
int arr[1000000];
int arr2[1000000];
int count = 0;


void quicksort(int arr[], int left, int right) {
    int L = left, R = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (L <= R) {
        while (arr[L] < pivot)
            L++;
        while (arr[R] > pivot)
            R--;


        if (L <= R) {
            if (L != R) {
                temp = arr[L];
                arr[L] = arr[R];
                arr[R] = temp;
            }
            L++; R--;


        }
    }

    if (left < R)
        quicksort(arr, left, R);
    if (L < right)
        quicksort(arr, L, right);
}

int main() {
    int n, num, j;
    int flag;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        m[i] = arr[i] = num;
    }

    quicksort(arr, 0, n - 1);

    arr2[count++] = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr2[count - 1] == arr[i]) continue;
            arr2[count++] = arr[i];
    }

    /*printf("arr1: ");
    for (int i = 0; i < n; i++) {
       printf("%d |", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < count; i++) {
       printf("%d |", arr2[i]);
    }*/

    for (int i = 0; i < n; i++) {
        int left = 0;
        int right = count;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (m[i] > arr2[mid]) {
                left = mid + 1;
            }
            else if (m[i] < arr2[mid]) {
                right = mid - 1;
            }
            else {
                break;
            }
        }
        printf("%d ", mid);
    }

    return 0;

}