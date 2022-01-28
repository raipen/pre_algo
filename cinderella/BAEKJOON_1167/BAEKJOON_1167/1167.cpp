#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

//std::
using namespace std;

//func
void DFS(int, int);

//var
int VertexSize, VertexFrom, VertexTo, EdgeWeight;
int StartingNode, WeightCount;
bool visited[100001];

//pair vector
vector<pair<int, int> > Tree[100001];

//main
int main()
{
	cin >> VertexSize;

	for (int i = 1; i <= VertexSize; i++)
	{
		cin >> VertexFrom;
		while (1)
		{
			cin >> VertexTo;
			if (VertexTo == -1) break;

			cin >> EdgeWeight;

			Tree[VertexFrom].push_back(pair<int, int>(VertexTo, EdgeWeight));
		}
	}

	DFS(1, 0);

	WeightCount = 0;

	for (int i = 1; i <= VertexSize; i++)
		visited[i] = false;

	DFS(StartingNode, 0);

	cout << WeightCount << '\n';
}

//func
void DFS(int curNode, int weight)
{
	visited[curNode] = true;

	if (weight > WeightCount)
	{
		WeightCount = weight;
		StartingNode = curNode;
	}

	for (int i = 0; i < Tree[curNode].size(); i++)
	{
		int NextNode = Tree[curNode][i].first;
		int NextWeight = Tree[curNode][i].second + weight;

		if (!visited[NextNode])
		{
			visited[NextNode] = true;
			DFS(NextNode, NextWeight);
			visited[NextNode] = false;
		}
	}
}