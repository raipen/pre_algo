#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	int i;
	int j;
	FILE* f1;

	f1 = fopen("text1.txt", "w");

	for (i = 0; i < 100; i++) {
		for (j = 0; j < 100; j++) {
			fprintf(f1, "%d", 1);
		}
		fprintf(f1, "\n");
	}
}