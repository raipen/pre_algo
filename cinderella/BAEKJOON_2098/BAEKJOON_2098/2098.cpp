#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
#define MAX 16
#define INF 987654321

int N, Answer_Bit;
int MAP[MAX][MAX];
int Weight_Bit[MAX][1 << MAX];

int DFS(int Cur, int Visited)
{
    if (Visited == (1 << N) - 1)
    {
        if (MAP[Cur][0]) return MAP[Cur][0];
        else return INF;
    }

    if (Weight_Bit[Cur][Visited] != -1) return Weight_Bit[Cur][Visited];

    Weight_Bit[Cur][Visited] = INF;

    for (int i = 0; i < N; i++)
    {
        if (!MAP[Cur][i]) continue;
        if ((Visited & (1 << i)) == (1 << i)) continue;

        Weight_Bit[Cur][Visited] = min(Weight_Bit[Cur][Visited], MAP[Cur][i] + DFS(i, Visited | 1 << i));
    }
    return Weight_Bit[Cur][Visited];
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];
    } 

    memset(Weight_Bit, -1, sizeof(Weight_Bit));

    cout << DFS(0, 1) << endl;

    return 0;
}