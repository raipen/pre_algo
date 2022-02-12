#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	double x;
	double y;
}coor;

typedef struct {
	int start;
	int end;
	double dis;
}path;

typedef int union_find;

void printPath(path* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d:%d %d %lf\n", i, arr[i].start, arr[i].end, arr[i].dis);
	}
}

int compare(const void* a, const void* b) {
	return ((path*)a)->dis > ((path*)b)->dis ? 1 : -1;
}

path* sortedDistance(coor* star, int size) {
	int size2 = size * (size - 1) / 2;
	path* temp = (path*)malloc(size2 * sizeof(path));
	for (int i = 0, index = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			path a = { i , j, sqrt(pow(fabs(star[i].x - star[j].x),2) + pow(fabs(star[i].y - star[j].y),2)) };
			temp[index++] = a;
		}
	}
	qsort(temp, size2, sizeof(path), compare);
	return temp;
}

int getParents(union_find* p, int e) {
	return p[e] == e ? e : getParents(p, p[e]);
}

int isGraph(path d, union_find* p) {
	return getParents(p, d.start) == getParents(p, d.end);
}

void unionStar(path d, union_find* p) {
	p[getParents(p, d.start)] = getParents(p, d.end);
}

union_find* initUnion(int size) {
	union_find* temp = (union_find*)malloc(size * sizeof(union_find));
	for (int i = 0; i < size; i++) {
		temp[i] = i;
	}
	return temp;
}

double minimumDistance(path* distance, int size) {
	union_find* parents = initUnion(size); //size��ŭ�� ���Ͽ� ����
	int size2 = size * (size - 1) / 2;	//������ ����
	double result = 0.0;	//�̾��� �� ���� ��
	for (int i = 0; i < size2; i++) {//��� ���� �˻�
		if (!isGraph(distance[i], parents)) {//�� ������ �����Ͽ����� �׷����� ���� �ʴ� �ٸ�
			result += distance[i].dis;//�� ������ ���̸� ����� ���ϰ�
			unionStar(distance[i], parents);//�� ������ �̾��ش�.
		}
	}
	return result;
}

int main() {
	int c;
	scanf("%d", &c);
	coor* star = (coor*)malloc(c * sizeof(coor));
	for (int i = 0; i < c; i++)
		scanf("%lf %lf", &star[i].x, &star[i].y);
	//�� ���� ������ �Ÿ��� ª�� ������ ����	
	//�Ÿ��� ������ �迭�� �������� �ּ� ���� Ʈ���� �Ÿ��� ����
	printf("%.2lf", minimumDistance(sortedDistance(star, c), c));

	return 0;
}