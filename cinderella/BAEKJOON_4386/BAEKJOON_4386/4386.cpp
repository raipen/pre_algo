#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int starcount;
double x, y;
double ans = 0;
vector<int>connected(101, 0);
vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> edge;

int find(int x);

int main(void)
{
	cin >> starcount;

	if (starcount == 1) cout << "0" << endl;
	else
	{
		for (int i = 0; i < starcount; i++)
		{
			cin >> x >> y;
			star.push_back(make_pair(x, y));
		}

		for (int i = 0; i < starcount; i++)
		{
			for (int j = i + 1; j < starcount; j++)
			{
				double weight = sqrt(pow(star[j].first - star[i].first, 2) + pow(star[j].second - star[i].second, 2));
				edge.push_back(make_pair(weight, make_pair(i, j)));
			}
		}

		for (int i = 0; i < starcount; i++)
			connected[i] = i;

		sort(edge.begin(), edge.end());
		
		for (int i = 0; i < starcount * (starcount - 1) / 2; i++)
		{
			x = edge[i].second.first;
			y = edge[i].second.second;
			double weight = edge[i].first;

			double from = find(x);
			double to = find(y);

			if (from != to)
			{
				connected[from] = to;
				ans += weight;
			}
		}

		cout << fixed;
		cout.precision(2);
		cout << ans << endl;

		return 0;
	}
}
int find(int x)
{
	if (connected[x] == x) return x;
	return connected[x] = find(connected[x]);
}