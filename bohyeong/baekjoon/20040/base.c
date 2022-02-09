#include <stdio.h>

//�θ� ��带 ã�� �Լ�
int getparent(int parent[], int x) {
	if (parent[x] == x) return x; //����Լ��� �����ɺκ� - � ���� �θ��尡 ���� ��
	return parent[x] = getparent(parent, parent[x]); // �θ� �ڱ��ڽ��� �ƴ� �� ��͸� ���� �θ� ������Ʈ 
}

//�� �θ� ��带 ��ġ�� �Լ�
int unionparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a < b) parent[b] = a; //�� �θ��� �� ���� ģ���� �θ�� ����!
	else parent[a] = b;
}

//���� �θ� �������� Ȯ��
int findparent(int parent[], int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a == b) return 1;
	else return 0;
}