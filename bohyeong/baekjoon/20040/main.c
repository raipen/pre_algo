#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int flag = 0; count = 0;
int cy_num = 0;
int parent[500000];
//���� Ʋ������: ����Ŭ�� �̷������ �� ����ϰ� �ٷ� �����߾���ߴµ� �׷��� ���� �ʰ� m ��° ���� �������� flag�� ���� ����Ϸ����ؼ� �׷���
//�θ� ��带 ã�� �Լ�
int getparent(int parent[], int x) {
	if (parent[x] == x) return x; //����Լ��� �����ɺκ� - � ���� �θ��尡 ���� ��
	return parent[x] = getparent(parent, parent[x]); // �θ� �ڱ��ڽ��� �ƴ� �� ��͸� ���� �θ� ������Ʈ 
}

//���� �θ� �������� Ȯ��
int findparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a == b) return 1;
	else return 0;
}

//�� �θ� ��带 ��ġ�� �Լ�
int unionparent(int parent[], int a, int b) {
	count++;
	if (findparent(parent, a, b)) {
		flag = 1;
		cy_num = count;
	}

	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a < b) parent[b] = a; //�� �θ��� �� ���� ģ���� �θ�� ����!
	else parent[a] = b;
}


int main() {
	int n, m;
	int a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) { //�θ� ��� �ʱ�ȭ
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