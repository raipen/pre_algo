#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int white = 0;
int blue = 0;
void initFence(int*** arr2, int size);
int equal_area(int**, int, int, int);
void dfs(int**, int, int ,int);

int main(void) {
	int size;
	int** arr;
	
	scanf("%d", &size);

	initFence(&arr, size);
	dfs(arr, 0, 0, size);
	printf("%d\n%d", white, blue);

	return 0;
}

int equal_area(int** arr, int x, int y, int size) {
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++){
			if (arr[i][j] != arr[x][y]){
				return false;
			}
		}
	}
	return true;
}

void dfs(int **arr, int x, int y, int size) {
	if (equal_area(arr, x, y, size) == true){
		if (arr[x][y] == 1) blue++;
		else white++;
	}
	else {
		dfs(arr, x, y, size / 2);
		dfs(arr, x, y + size / 2, size / 2); 
		dfs(arr, x + size / 2, y, size / 2);
		dfs(arr, x + size / 2, y + size / 2, size / 2);
	}
}

void initFence(int*** arr2, int size) {
	int i;
	int j;

	*arr2 = (int**)malloc(sizeof(int*) * size);

	for (i = 0; i < size; i++) {
		(*arr2)[i] = (int*)malloc(sizeof(int) * size);
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			scanf("%d", &((*arr2)[i][j]));
		}
	}
}