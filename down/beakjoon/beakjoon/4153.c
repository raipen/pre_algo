#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x,y,z;
	while (1)
	{
		scanf("%d %d %d", &x, &y, &z);
		if (!x && !y && !z)
			break;
		if (z*z == x * x + y * y|| y * y == x * x + z * z|| x * x == z * z + y * y)
		{
			printf("right\n");
		}
		else
			printf("wrong\n");
	}
	return 0;
}