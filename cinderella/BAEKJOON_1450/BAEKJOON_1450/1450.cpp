#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'

int N, C;

vector <long long> weightN;
vector <long long> Lpart;
vector <long long> Rpart;

void dfs(int start, int end, vector <long long>& part, long long sum) 
{
	if (start > end) 
	{
		part.push_back(sum);
		return;
	}
	else 
	{
		dfs(start + 1, end, part, sum);
		dfs(start + 1, end, part, sum + weightN[start]);
	}
}
int main() 
{
	cin >> N >> C;
	weightN.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> weightN[i];

	dfs(1, N / 2, Lpart, 0);
	dfs(N / 2 + 1, N, Rpart, 0);

	sort(Rpart.begin(), Rpart.end());

	int cnt = 0;

	for (int i = 0; i < Lpart.size(); i++) 
		cnt += upper_bound(Rpart.begin(), Rpart.end(), C - Lpart[i]) - Rpart.begin();

	cout << cnt << endl;
}