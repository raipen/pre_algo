#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define POS first
#define CONSUM second
#define INF 1000000000

const bool LEFT = true;
const bool RIGHT = false;

pair<int, int> street[1001] = { {0,0}, };
int dp[1001][1001][2] = { 0, };
int lightsize, startpos;
int lightconsumption, lightpos;

int solve(int lpos, int rpos, bool lr)
{
	if (dp[lpos][rpos][lr]) return dp[lpos][rpos][lr];

	if (lpos == 1 && rpos == lightsize) return dp[lpos][rpos][lr] = 0;

	int ans = 1000000000;
	int on = street[lightsize].second - (street[rpos].second - street[lpos - 1].second);
	int pos = lr ? rpos : lpos;

	cout << "pos : " << street[lpos].first << "  " << street[rpos].first << "   on : " << on << "  weight : " << ans << endl;

	if (lpos - 1)
	{
		ans = min(ans, solve(lpos - 1, rpos, LEFT) + (street[pos].first - street[lpos - 1].first) * on);
		//if (!dp[lpos][rpos][lr] || dp[lpos][rpos][lr] > tmp) dp[lpos][rpos][lr] = tmp;
	}
	if (rpos < lightsize)
	{
		ans = min(ans, solve(lpos, rpos + 1, RIGHT) + (street[rpos + 1].first - street[pos].first) * on);
		//if (!dp[lpos][rpos][lr] || dp[lpos][rpos][lr] > tmp) dp[lpos][rpos][lr] = tmp;
	}

	return dp[lpos][rpos][lr] = ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> lightsize >> startpos;

	for (int i = 1; i <= lightsize; i++)
	{
		cin >> street[i].first >> street[i].second;
		street[i].second += street[i - 1].second;//²ÜÆÁ, prefix sum
	}

	cout << solve(startpos, startpos, LEFT) << endl;
}