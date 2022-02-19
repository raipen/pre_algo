#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int sp;
	int ep;
	double distance;
}array; //출발 노드, 도착 노드 ,간선 거리를 담는 구조체

typedef struct {
	double x;
	double y;
}point; // 노드의 x,y 좌표를 담는 구조체

array s[4950];
point p[102];
int parent[102];

int compare(const void* a, const void* b)    // 오름차순 비교 함수 
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

int get_parent(int parent[], int x) { //아 씨발 진짜 어이없어 
	if (parent[x] == x) {             //백준 틀린이유: return; 이지랄 해서 틀림 씨발것 
		return x; //음 반환값 똑바로 보자 그리고 , c++넘어가자 
	}
	return parent[x] = get_parent(parent, parent[x]);
}

int find_parent(int parent[], int a, int b) { //같은 부모를 가지는 지 확인하는 함수
	a = get_parent(parent, a);
	b = get_parent(parent, b);
	if (a == b) return 1;
	else return 0;
}

int unionparent(int parent[], int a, int b) {
	a = get_parent(parent, a);
	b = get_parent(parent, b);						
	if (a < b) parent[b] = a; //두 부모노드 중 작은 친구를 부모로 설정!
	else parent[a] = b;
}

int main() {
	int num; int wei;
	int arr_count = 0;
	int count = 0;
	double sum = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {//좌표 넣기
		scanf("%lf %lf", &p[i].x, &p[i].y); 
		parent[i] = i;
	}

	for (int i = 0; i < num; i++) { // 간선 거리 구하고 array에 정보 넣기
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