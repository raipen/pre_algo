#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_SIZE 501		//0��° index �����Ƽ� �Ⱦ�

int VertSize, EdgeSize;			//�Է¹޴� Vertex, Edge ũ��
int RootCount, CaseCount = 0;	//Ʈ���� Root ���� Ȯ��, Case ����
int Vert_From, Vert_To;			//�Է¹޴� Vertex��
int RootNode[MAX_VERTEX_SIZE];	//Union-Find Algorithm�� Parent �迭

int RootFind(int x);			//Root ��� Ž�� �Լ�
void RootUnion(int x, int y);	//Root ����� ����	

int main(void)
{
	while (1)
	{
		//Vertsize, Edgesize �Է�
		scanf_s("%d %d", &VertSize, &EdgeSize);
		if (!VertSize && !EdgeSize) break;						//�Է��� 0 0�� �� break

		//initialization
		CaseCount++;
		RootCount = 0;
		for (int i = 0; i < MAX_VERTEX_SIZE; i++)
			RootNode[i] = i;									//RootNode �迭 �� ĭ�� index������ �ʱ�ȭ
																//RootNode �迭�� 0��° ĭ�� ������ ������, 0���� �ʱ�ȭ�Ǿ� ����

		for (int i = 0; i < EdgeSize; i++)
		{
			scanf_s("%d %d", &Vert_From, &Vert_To);

			//Vert_From�� Vert_To ������ Root Ž��
			Vert_From = RootFind(Vert_From);
			Vert_To = RootFind(Vert_To);

			if (Vert_From == Vert_To) RootNode[Vert_From] = 0;	//Root�� ���� == �������ʹ� Circuit�� �����Ѵ� -> 0���� �� ������ ������
			else RootUnion(Vert_From, Vert_To);					//RootUnion �Լ��� ���� Root ����� ����
		}

		for (int i = 1; i <= VertSize; i++)
			if (RootNode[i] == i) RootCount++;					//RootNode �迭 �� ĭ�� ���� ������ ���� ��� Tree�� Root�� -> Count++

		//print
		printf("Case %d: ", CaseCount);
		
		if (!RootCount) printf("No trees.\n");
		else if (RootCount == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", RootCount);
	}
	return 0;
}

//Union-Find Algorithm
int RootFind(int x)				//����Լ�, RootNode[x]�� ���� ������ ���� �ڱ��ڽ��� �ɶ����� ��� �ݺ��� Root ã�ư���
{
	return (RootNode[x] == x) ? x : (RootNode[x] = RootFind(RootNode[x]));
}
void RootUnion(int x, int y)	//x = 0�� �ƴ� ��(Circuit �ƴ�), y = 0(Circiut ����)�� �� RootNode[x]�� �� ���� 0���� �ٲ��ش�(Circuit ����)
{								//y = 0�� �ƴ� ��, x = 0�� ���� ������ �ٸ� ��Ȳ������ ��� RootNode[y]�� ���� x�� �ٲ��ش�
	if (!y) RootNode[x] = y;
	else RootNode[y] = x;
}