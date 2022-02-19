#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 11

int Size, Answer = 100000000;
int MAP[MAX][MAX];
bool Visited[MAX];
int StartNode;

void DFS(int nodePos, int weight, int cnt)
{
    if (cnt == Size - 1)
    {
        if (MAP[nodePos][StartNode])
        {
            Answer = min(Answer, weight + MAP[nodePos][StartNode]); //더 작은값 저장
            return;
        }
    }

    for (int i = 1; i <= Size; i++)
    {
        if (MAP[nodePos][i] && !Visited[i])
        {
            Visited[i] = true;  //방문했음
            DFS(i, weight + MAP[nodePos][i], cnt + 1);
            Visited[i] = false; //방문기록 초기화(다음 loop를 위해)
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //<input>
    cin >> Size;

    for (int i = 1; i <= Size; i++)
    {
        for (int j = 1; j <= Size; j++)
            cin >> MAP[i][j];
    }
    //</input>

    //<loop - rec>
    for (int i = 1; i <= Size; i++)
    {
        StartNode = i;
        Visited[i] = true;
        DFS(i, 0, 0);
        Visited[i] = false;
    }
    //</loop - rec>

    //<output>
    cout << Answer << endl;
    //</output>
}