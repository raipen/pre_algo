#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int sp;
	int ep;
	double distance;
}array; //��� ���, ���� ��� ,���� �Ÿ��� ��� ����ü

typedef struct {
	double x;
	double y;
}point; // ����� x,y ��ǥ�� ��� ����ü

array s[4950];
point p[102];
int parent[102];

int compare(const void* a, const void* b)    // �������� �� �Լ� 
{
	array* num1 = (array*)a;    
	array* num2 = (array*)b;    
	if (num1->distance > num2->distance)
	{
		return 1;
	}
	else if (num1->distance < num2->distance) {
		return -1;
	}
	else {
		return 0;
	}
	
}

int get_parent(int parent[], int x) { //�� ���� ��¥ ���̾��� 
	if (parent[x] == x) {             //���� Ʋ������: return; ������ �ؼ� Ʋ�� ���߰� 
		return x; //�� ��ȯ�� �ȹٷ� ���� �׸��� , c++�Ѿ�� 
	}
	return parent[x] = get_parent(parent, parent[x]);
}

int find_parent(int parent[], int a, int b) { //���� �θ� ������ �� Ȯ���ϴ� �Լ�
	a = get_parent(parent, a);
	b = get_parent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int unionparent(int parent[], int a, int b) {
	a = get_parent(parent, a);
	b = get_parent(parent, b);						
	if (a < b) parent[b] = a; //�� �θ��� �� ���� ģ���� �θ�� ����!
	else parent[a] = b;
}

int main() {
	int num; int wei;
	int arr_count = 0;
	int count = 0;
	double sum = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {//��ǥ �ֱ�
		scanf("%lf %lf", &p[i].x, &p[i].y); 
		parent[i] = i;
	}

	for (int i = 0; i < num; i++) { // ���� �Ÿ� ���ϰ� array�� ���� �ֱ�
		for (int j = i+1; j < num; j++) {
			double a = fabs(p[j].x - p[i].x);
			double b = fabs(p[j].y - p[i].y);
			double c = sqrt((a * a) + (b * b));
			s[arr_count].sp = i; s[arr_count].ep = j;	
			s[arr_count++].distance = c;
		}
	}
	

	//quicksort(s, 0, arr_count-1);
	qsort(s , arr_count, sizeof(s[0]), compare);

	for (int i = 0; i < arr_count; i++) {
		if (!find_parent(parent, s[i].sp, s[i].ep)) {
			unionparent(parent, s[i].sp, s[i].ep);
			count++;
			 sum += s[i].distance;

			if (count == num - 1) {
				break;
			}
		}
	}

	printf("%.2lf\n", sum);
	for (int i = 0; i < arr_count; i++) {
		printf("%d %d %lf\n", s[i].sp, s[i].ep, s[i].distance);
	}

	return 0;
}