#include <iostream>//stdio.h
#include <vector>//����, �迭 Ŭ�� ����
#include <algorithm>//�����
#include <cmath>//math.h
using namespace std;//c++���ϸ�������

int starcount;
double x, y;
double ans = 0;


vector<int> parent(101, 0); // ==int connected[101] = {0,};
vector<pair<double, double>> star; //typedef struct{d,d}asdf; asdf star[�����ϸ� *2 �̷����� ����];
vector<pair<double, pair<int, int>>> edge; 

int find(int x);

int main(void)
{
	cin >> starcount; //scanf_s("�����˾Ƽ�ã����", &starcount);

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

		sort(edge.begin(), edge.end());//������ ����մϴ�
		
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

		cout << fixed; //�Ҽ���fix?���� �׷�����
		cout.precision(3);//����.
		cout << ans << endl;

		return 0;
	}
}
int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}