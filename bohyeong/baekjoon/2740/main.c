#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr1[102][102]; int arr2[102][102];


int main() {

	int a, b, c;
	int sum;
	scanf("%d %d", &a, &b);

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &arr1[i][j]);
		}
	}
	scanf("%d %d", &b, &c);
	
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &arr2[i][j]);
		}
	}
	
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < c; j++) {
			sum = 0;
			for (int k = 0; k < b; k++) {
				sum += (arr1[i][k] * arr2[k][j]); 
			}
			printf("%d ", sum);
		}
		printf("\n");
	}


	return 0;
}