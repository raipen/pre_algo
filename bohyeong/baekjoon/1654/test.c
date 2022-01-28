#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long arr[10001] = { 0, };

long long count_arr(long long arr[], int n, long long mid) {
	long long count = 0;
	for (int i = 0; i < n; i++) {
		count += (arr[i] / mid);
	}
	return count;
}

long long binsearch(long long arr[], int n, int N, long long max) {
	long long low = 1, high = max; //high를 제일 큰 값으로 잡는다해놓고 아무생각없이 arr[n-1] 이라고함..
	long long mid, key, temp; //총 횟수

	while (low <= high) {
		mid = (low + high) / 2; // 2의 32승 -1의 데이터를 받아들이기 위해서는 int형보다 long long을 써야할 듯함 
		//printf("mid: %d\n", mid);
		key = count_arr(arr, n, mid);
		if (key < N) { // 나눈 횟수에 못미칠때
			high = mid - 1; //나누기 값을 줄임
		}
		else if (key >= N) {
			low = mid + 1;
			temp = mid;
		}
	}

	return temp;
}

int main() {
	int K, N;
	long long max =0;
	long long key;
	char c;
	scanf("%d %d", &K, &N);

	for (int i = 0; i < K; i++) {
		scanf("%lld", &arr[i]); // long long 형을 scanf 하기위해서는 %lld형식으로 해줘야함
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	key = binsearch(arr, K, N, max);
	printf("%d\n", key);
	

}