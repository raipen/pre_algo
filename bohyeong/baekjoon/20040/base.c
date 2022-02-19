#include <stdio.h>

//부모 노드를 찾는 함수
int getparent(int parent[], int x) {
	if (parent[x] == x) return x; //재귀함수의 종료명령부분 - 어떤 노드와 부모노드가 같을 때
	return parent[x] = getparent(parent, parent[x]); // 부모가 자기자신이 아닐 때 재귀를 통해 부모를 업데이트 
}

//두 부모 노드를 합치는 함수
int unionparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a < b) parent[b] = a; //두 부모노드 중 작은 친구를 부모로 설정!
	else parent[a] = b;
}

//같은 부모를 가지는지 확인
int findparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a == b) return 1;
	else return 0;
}