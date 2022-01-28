#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_SIZE 501

int VertSize, EdgeSize, RootCount, CaseCount = 0;
int Vert_From, Vert_To;
int RootNode[MAX_VERTEX_SIZE];

int find(int x);
void unionparent(int x, int y);

int main(void)
{
	while (1)
	{
		scanf_s("%d %d", &VertSize, &EdgeSize);
		if (!VertSize && !EdgeSize) break;

		//init
		CaseCount++;
		RootCount = 0;
		for (int i = 0; i < MAX_VERTEX_SIZE; i++)
			RootNode[i] = i;


		for (int i = 0; i < EdgeSize; i++)
		{
			scanf_s("%d %d", &Vert_From, &Vert_To);

			Vert_From = find(Vert_From);
			Vert_To = find(Vert_To);

			if (Vert_From == Vert_To) RootNode[Vert_From] = 0;
			else unionparent(Vert_From, Vert_To);
		}

		for (int i = 1; i <= VertSize; i++)
			if (RootNode[i] == i) RootCount++;

		printf("Case %d: ", CaseCount);
		
		if (!RootCount) printf("No trees.\n");
		else if (RootCount == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", RootCount);
	}
	return 0;
}

int find(int x)
{
	return (RootNode[x] == x) ? x : (RootNode[x] = find(RootNode[x]));
}
void unionparent(int x, int y)
{
	if (!x) RootNode[y] = x;
	else if (!y) RootNode[x] = y;
	else RootNode[y] = x;
}