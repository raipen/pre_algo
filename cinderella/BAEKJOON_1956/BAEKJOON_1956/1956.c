#include <stdio.h>
#include <stdlib.h>

#define MAX_VERT_SIZE 401
#define INF 999999999

int VertSize, EdgeSize;
int VertFrom, VertTo, EdgeWeight;
int Graph[MAX_VERT_SIZE][MAX_VERT_SIZE];
int MinCircuit = INF;	

int main(void)
{
	for (int i = 0; i < MAX_VERT_SIZE; i++)
	{
		for (int j = 0; j < MAX_VERT_SIZE; j++)
			Graph[i][j] = INF;
	}

	scanf_s("%d %d", &VertSize, &EdgeSize);

	for (int i = 0; i < EdgeSize; i++)
	{
		scanf_s("%d %d %d", &VertFrom, &VertTo, &EdgeWeight);
		Graph[VertFrom][VertTo] = EdgeWeight;
	}

	for (int i = 1; i <= VertSize; i++)
	{
		for (int j = 1; j <= VertSize; j++)
		{
			for (int k = 1; k <= VertSize; k++)
			{
				if (Graph[j][i] != INF && Graph[i][k] != INF) Graph[j][k] = ((Graph[j][k] < (Graph[j][i] + Graph[i][k])) ? Graph[j][k] : (Graph[j][i] + Graph[i][k]));
			}
		}
	}
	for (int i = 1; i <= VertSize; i++)
	{
		for (int j = 0; j < VertSize; j++)
			if (MinCircuit > Graph[i][j] && (i == j)) MinCircuit = Graph[i][j];
	}
	if (MinCircuit == INF) MinCircuit = -1;

	printf("%d", MinCircuit);

	return 0;
}
