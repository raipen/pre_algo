#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Stdlib.h>
#include <math.h>
typedef struct star
{
	float x;
	float y;
}star;
star star_list[101];
float length[101][101];
int main()
{
	int size;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		scanf("%f %f", &star_list[i].x, &star_list[i].y);
	}
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			length[i][j] = sqrt(pow((star_list[i].x - star_list[j].x), 2) + pow((star_list[i].y - star_list[j].y), 2));
		}
	}

	return 0;
}