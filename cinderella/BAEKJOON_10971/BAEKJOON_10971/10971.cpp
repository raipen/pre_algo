#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX 11

int Size, Answer = 100000000;//INF
int MAP[MAX][MAX];
bool Visited[MAX];
int StartNode;

void DFS(int nodePos, int weight, int cnt)
{
    if (cnt == Size - 1)    //�̵� size - 1�� ������
    {
        if (MAP[nodePos][StartNode])    //���� ��ġ���� ù ���� ���ƿ� �� ������
        {
            Answer = min(Answer, weight + MAP[nodePos][StartNode]); //�� ������ ����
            return;
        }
    }

    for (int i = 1; i <= Size; i++)
    {
        if (MAP[nodePos][i] && !Visited[i])
        {
            Visited[i] = true;  //�湮����
            DFS(i, weight + MAP[nodePos][i], cnt + 1);
            Visited[i] = false; //�湮��� �ʱ�ȭ(���� loop�� ����)
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
    //for (int i = 1; i <= Size; i++)
    //{
        StartNode = 1;
        Visited[1] = true;
        DFS(1, 0, 0);
        Visited[1] = false;
    //}
    //</loop - rec>

    //<output>
    cout << Answer << endl;
    //</output>
}