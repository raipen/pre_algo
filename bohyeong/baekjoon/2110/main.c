#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min = 0;

int* arr;

void quicksort( int left, int right) {
	int L = left, R = right;
	int temp;
	int pivot = arr[(left + right) / 2];

	while (L <= R) {
		while (arr[L] < pivot) L++;
		while (arr[R] > pivot) R--;

		if (L <= R) {
			if (L != R) {
				temp = arr[L];
				arr[L] = arr[R];
				arr[R] = temp;
			}
			L++; R--;

		}
	
	}

	if (left < R) {
		quicksort( left, R);
	}
	if (L < right) {
		quicksort( L, right);
	}

	

}

int checking( int r, int size) {
	int count = 1;
	int pivot = 0;
	
	for (int i = 0; i < size+1; i++) {
		if (arr[i] - arr[pivot] >= r) {
				
			pivot = i;
			count++;
		}
		
	}
	
	return count;
}

int find_way(int L , int R, int goal) {
	int left = 1 , right = arr[R];
	int mid, count;
	int result = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		count = checking(mid, R);
		if (count< goal) {
			right = mid -1;
		}
		else if(count >= goal){
			result = mid;
			left = mid + 1;
		}
	}
	return result;
}

int main() {
	int N, C;
	int max;
	scanf("%d %d", &N, &C);
	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf(" %d", &arr[i]);
	}

	quicksort(0, N-1);

	/*for (int i = 0; i < N; i++) {
		printf("%2d", arr[i]);
	}*/

	max = find_way(0, N - 1, C);
	printf("%d\n", max);
}