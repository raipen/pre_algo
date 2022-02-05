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
	long long low = 1, high = max; //high�� ���� ū ������ ��´��س��� �ƹ��������� arr[n-1] �̶����..
	long long mid, key, temp; //�� Ƚ��

	while (low <= high) {
		mid = (low + high) / 2; // 2�� 32�� -1�� �����͸� �޾Ƶ��̱� ���ؼ��� int������ long long�� ����� ���� 
		//printf("mid: %d\n", mid);
		key = count_arr(arr, n, mid);
		if (key < N) { // ���� Ƚ���� ����ĥ��
			high = mid - 1; //������ ���� ����
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
		scanf("%lld", &arr[i]); // long long ���� scanf �ϱ����ؼ��� %lld�������� �������
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	key = binsearch(arr, K, N, max);
	printf("%d\n", key);
	

}