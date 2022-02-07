//----- [2630] 분할정복/색종이 만들기 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX_N 128

int arr[MAX_N][MAX_N];
int count[2] = { 0 };

void cut(int x, int y, int size);
int ch(int x, int y, int size);

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++)
			scanf("%d", &arr[i][j]);

	cut(0, 0, n);

	printf("%d\n%d", count[0], count[1]);

	return 0;
}

void cut(int x, int y, int size) {
	if (size == 1 || ch(x, y, size)) {
		count[arr[x][y]]++;
		return;
	}

	cut(x, y, size / 2);
	cut(x + size / 2, y, size / 2);
	cut(x, y + size / 2, size / 2);
	cut(x + size / 2, y + size / 2, size / 2);
}

int ch(int x, int y, int size) {
	for (int i = x; i < x + size; i++)
		for (int j = y; j < y + size; j++)
			if (arr[i][j] != arr[x][y])
				return 0;
	return 1;
}