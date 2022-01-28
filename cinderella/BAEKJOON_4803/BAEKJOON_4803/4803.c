#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_SIZE 501		//0번째 index 귀찮아서 안씀

int VertSize, EdgeSize;			//입력받는 Vertex, Edge 크기
int RootCount, CaseCount = 0;	//트리의 Root 갯수 확인, Case 변수
int Vert_From, Vert_To;			//입력받는 Vertex들
int RootNode[MAX_VERTEX_SIZE];	//Union-Find Algorithm의 Parent 배열

int RootFind(int x);			//Root 노드 탐색 함수
void RootUnion(int x, int y);	//Root 노드의 병합	

int main(void)
{
	while (1)
	{
		//Vertsize, Edgesize 입력
		scanf_s("%d %d", &VertSize, &EdgeSize);
		if (!VertSize && !EdgeSize) break;						//입력이 0 0일 때 break

		//initialization
		CaseCount++;
		RootCount = 0;
		for (int i = 0; i < MAX_VERTEX_SIZE; i++)
			RootNode[i] = i;									//RootNode 배열 각 칸을 index값으로 초기화
																//RootNode 배열의 0번째 칸은 사용되지 않으며, 0으로 초기화되어 있음

		for (int i = 0; i < EdgeSize; i++)
		{
			scanf_s("%d %d", &Vert_From, &Vert_To);

			//Vert_From과 Vert_To 각각의 Root 탐색
			Vert_From = RootFind(Vert_From);
			Vert_To = RootFind(Vert_To);

			if (Vert_From == Vert_To) RootNode[Vert_From] = 0;	//Root가 같다 == 이제부터는 Circuit이 존재한다 -> 0으로 값 변경해 버리기
			else RootUnion(Vert_From, Vert_To);					//RootUnion 함수를 통해 Root 노드의 병합
		}

		for (int i = 1; i <= VertSize; i++)
			if (RootNode[i] == i) RootCount++;					//RootNode 배열 각 칸의 값이 변하지 않은 경우 Tree의 Root임 -> Count++

		//print
		printf("Case %d: ", CaseCount);
		
		if (!RootCount) printf("No trees.\n");
		else if (RootCount == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", RootCount);
	}
	return 0;
}

//Union-Find Algorithm
int RootFind(int x)				//재귀함수, RootNode[x]의 값이 변하지 않은 자기자신이 될때까지 재귀 반복해 Root 찾아가기
{
	return (RootNode[x] == x) ? x : (RootNode[x] = RootFind(RootNode[x]));
}
void RootUnion(int x, int y)	//x = 0이 아닌 값(Circuit 아님), y = 0(Circiut 상태)일 때 RootNode[x]의 값 역시 0으로 바꿔준다(Circuit 상태)
{								//y = 0이 아닌 값, x = 0일 때를 포함한 다른 상황에서는 모두 RootNode[y]의 값을 x로 바꿔준다
	if (!y) RootNode[x] = y;
	else RootNode[y] = x;
}