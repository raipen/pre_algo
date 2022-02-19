//----- [2156] 포도주 시식 -----//

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_N 10000

typedef struct {
	int cont;
	int discont;
	int max;
} MAXTB;

int main() {
	int n, input;
	MAXTB arr[MAX_N];

	scanf("%d", &n);
	scanf("%d", &input);
	arr[0].cont = arr[0].discont = arr[0].max = input;

	for (int i = 1; i < n; i++) {
		scanf("%d", &input);
		arr[i].cont = arr[i - 1].discont + input;
		if (i - 2 < 0)
			arr[i].discont = input;
		else
			arr[i].discont = arr[i - 2].max + input;

		if (arr[i - 1].max > arr[i].cont && arr[i - 1].max > arr[i].discont)
			arr[i].max = arr[i - 1].max;
		else if (arr[i].cont > arr[i].discont)
			arr[i].max = arr[i].cont;
		else
			arr[i].max = arr[i].discont;

	}

	printf("%d\n", arr[n - 1].max);

	return 0;
}