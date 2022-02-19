#include <iostream>//stdio.h
#include <vector>//벡터, 배열 클라스 관련
#include <algorithm>//개사기
#include <cmath>//math.h
using namespace std;//c++제일먼저배울것

int starcount;
double x, y;
double ans = 0;


vector<int> parent(101, 0); // ==int connected[101] = {0,};
vector<pair<double, double>> star; //typedef struct{d,d}asdf; asdf star[부족하면 *2 이론으로 조절];
vector<pair<double, pair<int, int>>> edge; 

int find(int x);

int main(void)
{
	cin >> starcount; //scanf_s("지가알아서찾아줌", &starcount);

	if (starcount == 1) cout << "0" << endl; //printf("0\n") //endl == '\n'
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

		//init
		for (int i = 0; i < starcount; i++)
			parent[i] = i;

		sort(edge.begin(), edge.end());//여러분 사랑합니다
		
		for (int i = 0, count = 0; i < starcount * (starcount - 1) / 2 && count < starcount; i++)
		{
			x = edge[i].second.first;
			y = edge[i].second.second;
			double weight = edge[i].first;

			double from = find(x);
			double to = find(y);

			if (from != to)
			{
				parent[from] = to;
				ans += weight;
				count++;
			}
		}

		cout << fixed; //소수점fix?대충 그런느낌
		cout.precision(3);//고정.
		cout << ans << endl;

		return 0;
	}
}
int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}