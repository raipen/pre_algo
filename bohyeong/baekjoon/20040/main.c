#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int flag = 0; count = 0;
int cy_num = 0;
int parent[500000];
//백준 틀린이유: 사이클이 이루어졌을 때 출력하고 바로 종료했어야했는데 그렇게 하지 않고 m 번째 까지 돌린다음 flag를 통해 출력하려고해서 그런듯
//부모 노드를 찾는 함수
int getparent(int parent[], int x) {
	if (parent[x] == x) return x; //재귀함수의 종료명령부분 - 어떤 노드와 부모노드가 같을 때
	return parent[x] = getparent(parent, parent[x]); // 부모가 자기자신이 아닐 때 재귀를 통해 부모를 업데이트 
}

//같은 부모를 가지는지 확인
int findparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a == b) return 1;
	else return 0;
}

//두 부모 노드를 합치는 함수
int unionparent(int parent[], int a, int b) {
	count++;
	if (findparent(parent, a, b)) {
		flag = 1;
		cy_num = count;
	}

	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a < b) parent[b] = a; //두 부모노드 중 작은 친구를 부모로 설정!
	else parent[a] = b;
}


int main() {
	int n, m;
	int a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) { //부모 노드 초기화
		parent[i] = i;
	}

	while (m--) {
		scanf("%d %d", &a, &b);
		unionparent(parent, a, b);
		if (flag) {
			printf("%d\n", cy_num);
			return 0;
		}
	}
	printf("%d\n", 0);

	return 0;
}