#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int size,nation_num,plane_num,plane_1,plane_2;
	scanf("%d", &size);
	for (int i = 1; i <= size; i++)
	{
		scanf("%d %d", &nation_num, &plane_num);
		for (int j = 1; j <= plane_num; j++)
		{
			scanf("%d %d", &plane_1, &plane_2);
		}
		printf("%d\n", nation_num - 1);
	}
	return 0;
}