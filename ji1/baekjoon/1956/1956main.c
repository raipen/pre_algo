#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int V, E,r,c;
	scanf("%d %d", &V, &E);
	int graph[400][400] = { 0 };
	while (E-- && scanf("%d %d", &r, &c) && scanf("%d", &graph[r][c]));
	
	return 0;
}