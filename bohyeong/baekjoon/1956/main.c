#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max 400

int INF = 2000000;
int arr[max][max];
int min = 2000000;
int flag = 0;

void floy(int size) {
	
	//int d[max][max];

	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%10d", arr[i][j]);
		}
		printf("\n");
	}*/

	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			d[i][j] = arr[i][j];
		}
	}*/

	for (int k = 0; k < size; k++) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i][k] + arr[k][j] < arr[i][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}


	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%10d", d[i][j]);
		}
		printf("\n");
	}*/


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i != j) {
				if (arr[i][j] != INF && arr[j][i] != INF) {
					if (min > (arr[i][j] + arr[j][i])) {
						min = arr[i][j] + arr[j][i];
						flag = 1;
					}
				}
			}
		}
	}

	if (!flag) {
		min = -1;
	}
}

int main() {
	int index, load;
	scanf("%d %d", &index, &load);
	int n = load;
	int i, j, w;

	for (int i = 0; i < index; i++) {
		for (int j = 0; j < index; j++) {
			if (i == j) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = INF;
			}
		}
	}

	while (n--) {
		scanf("%d %d %d", &i, &j, &w);
		arr[i-1][j-1] = w;
	}

	floy(index);
	printf("%d\n", min);
	return 0;
}