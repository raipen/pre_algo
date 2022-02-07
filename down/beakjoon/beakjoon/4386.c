#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct star
{
	double x;
	double y;
}star;
typedef struct star_relate
{
	int star_1;
	int star_2;
	double length;
}star_relate;
int parent_star[102];
star star_list[102];
star_relate relation_map[10404];
int compare(const void* a, const void* b);
void kruscar();
void union_star(int star_1,int star_2);
int find_parent(int sibiling);
double sum;
int size;
int main()
{
	int cnt = 0;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		scanf("%lf %lf", &star_list[i].x, &star_list[i].y);
	}
	for (int i = 1; i <= size; i++)
	{
		parent_star[i] = i;
	}
	for (int i = 1; i <= size; i++)
	{
		for (int j = i+1; j <= size; j++)
		{
			relation_map[++cnt].star_1 = i;
			relation_map[cnt].star_2 = j;
			relation_map[cnt].length = sqrt(pow_dawns((star_list[i].x - star_list[j].x), 2) + pow_dawns((star_list[i].y - star_list[j].y), 2));
		}
	}
	qsort(relation_map, ((size+1)*(size))/2, sizeof(star_relate), compare);
	kruscar();
	printf("%lf", sum);
	return 0;
}
int compare(const void* a, const void* b)
{
	star_relate num1 = *(star_relate*)a;
	star_relate num2= *(star_relate*)b;

	if (num1.length > num2.length)
		return 1;

	if (num1.length < num2.length)
		return -1;

	return 0;
}
void kruscar()
{
	int a, b;
	for (int i = 1,cnt=0; i <= 10000000; i++)
	{
		if (cnt == size - 1)
			break;
		a = find_parent(relation_map[i].star_1);
		b = find_parent(relation_map[i].star_2);
		if (a!=b)
		{
			sum += relation_map[i].length;
			cnt++;
			parent_star[a] = b;
		}
		
	}
}
void union_star(int star_1, int star_2)
{
	int parent_1,parent_2;
	parent_1 = find_parent(star_1);
	parent_2 = find_parent(star_2);
	if (parent_1 < parent_2)
	{
		parent_star[star_2] = parent_1;
	}
	else
	{
		parent_star[star_1] = parent_2;
	}
}
int find_parent(int sibiling)
{
	if (parent_star[sibiling] == sibiling)
	{
		return sibiling;
	}
	return parent_star[sibiling] = find_parent(parent_star[sibiling]);

}