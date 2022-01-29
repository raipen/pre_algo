#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cw = 0; int cb = 0;

void merge(int** arr, int x, int y, int size) {
	int fir = arr[x][y];
	int flag = 0;
	int mid;
	//printf("x: %d, y: %d, size: %d\n", x, y, size);
	
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (fir != arr[i][j]) {
				flag = 1;
			}
		}
	}

	if (flag) {
		mid = size / 2;
		merge(arr, x, y, size/2); //왼쪽위
		merge(arr, x, y+mid, size/2); // 오른쪽 위
		merge(arr, x+mid, y, size / 2); // 왼쪽아래
		merge(arr, x+mid, y+mid, size / 2); // 오른쪽 아래
	}

	else if (!flag) {
		if (fir) {
			cb++;
		}
		else {
			cw++;
		}
		return;
	}	
}

int main() {
	int size;
	scanf("%d", &size);
	
	int** arr = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++) {
		arr[i] = (int*)malloc(sizeof(int) * size);
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	merge(arr, 0, 0, size);

	printf("%d\n%d\n", cw, cb);

}