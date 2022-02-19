#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct dot
{
	double x;
	double y;
}dot;

int find_dir(dot a, dot b, dot c);

int main()
{
	dot a, b, c;

	scanf("%lf %lf", &a.x, &a.y);
	scanf("%lf %lf", &b.x, &b.y);
	scanf("%lf %lf", &c.x, &c.y);

	printf("%d", find_dir(a, b, c));


	return 0;
}
int find_dir(dot a, dot b, dot c)
{
	if ((a.x - b.x) != 0)
	{
		if (a.x < b.x)
		{
			if ((c.y - a.y) == ((a.y - b.y) / (a.x - b.x)) * (c.x - a.x))
			{
				return 0;
			}
			else if ((c.y - a.y) > ((a.y - b.y) / (a.x - b.x)) * (c.x - a.x))
			{
				return 1;
			}
			else
				return -1;
		}
		else
		{
			if ((c.y - a.y) == ((a.y - b.y) / (a.x - b.x)) * (c.x - a.x))
			{
				return 0;
			}
			else if ((c.y - a.y) > ((a.y - b.y) / (a.x - b.x)) * (c.x - a.x))
			{
				return -1;
			}
			else
				return 1;
		}
	}
	else
	{
		if (a.y > b.y)
		{
			if (c.x > a.x)
				return 1;
			else if (c.x == a.x)
				return 0;
			else
				return -1;
		}
		else
		{
			if (c.x > a.x)
				return -1;
			else if (c.x == a.x)
				return 0;
			else
				return 1;
		}
	}
}