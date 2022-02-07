#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 2001
#define INF 999999999

int VertSize, EdgeSize, CandSize, StartPos, PassPos_1, PassPos_2, Weight_Pass;
int Weight_StartPos[MAX];
int Weight_Pass_1[MAX];
int Weight_Pass_2[MAX];

vector<pair<int, int>> Graph[MAX];
vector<int> CandList;

void Dijkstra(int Start, int A[MAX]);

int main(void)
{
    int TestCase;
    cin >> TestCase;

    for (int TC = 0; TC < TestCase; TC++)
    {
        for (int i = 0; i < MAX; i++)
        {
            Graph[i].clear();
            Weight_StartPos[i] = INF;
            Weight_Pass_1[i] = INF;
            Weight_Pass_2[i] = INF;
        }
        CandList.clear();
        
        cin >> VertSize >> EdgeSize >> CandSize;
        cin >> StartPos >> PassPos_1 >> PassPos_2;
        for (int i = 0; i < EdgeSize; i++)
        {
            int VertFrom, VertTo, Weight;
            cin >> VertFrom >> VertTo >> Weight;
            Graph[VertFrom].push_back(make_pair(VertTo, Weight));
            Graph[VertTo].push_back(make_pair(VertFrom, Weight));
        }

        for (int i = 0; i < CandSize; i++)
        {
            int Cand;
            cin >> Cand;
            CandList.push_back(Cand);
        }

        Dijkstra(StartPos, Weight_StartPos);

        Dijkstra(PassPos_1, Weight_Pass_1);
        Weight_Pass = Weight_Pass_1[PassPos_2];
        Dijkstra(PassPos_2, Weight_Pass_2);

        sort(CandList.begin(), CandList.end());

        for (int i = 0; i < CandSize; i++)
        {
            int Dest = CandList[i];
            if (Weight_StartPos[Dest] == Weight_StartPos[PassPos_1] + Weight_Pass + Weight_Pass_2[Dest]) cout << Dest << " ";
            else if (Weight_StartPos[Dest] == Weight_StartPos[PassPos_2] + Weight_Pass + Weight_Pass_1[Dest]) cout << Dest << " ";
        }
        cout << endl;
    }

    return 0;
}

void Dijkstra(int Pos, int Arr[MAX])
{
    priority_queue<pair<int, int>> PrQ;

    PrQ.push(make_pair(0, Pos));
    Arr[Pos] = 0;

    while (!PrQ.empty())
    {
        int Weight = -PrQ.top().first;
        int Pos = PrQ.top().second;

        PrQ.pop();

        for (int i = 0; i < Graph[Pos].size(); i++)
        {
            int NextPos = Graph[Pos][i].first;
            int NextWeight = Graph[Pos][i].second;

            if (Arr[NextPos] > Weight + NextWeight)
            {
                Arr[NextPos] = Weight + NextWeight;
                PrQ.push(make_pair(-Arr[NextPos], NextPos));
            }
        }
    }
}