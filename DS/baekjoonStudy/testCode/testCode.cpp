#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

int parents[101];

vector<pair<double, double> > nodes;
vector<pair<pair<double, double>, double> > edges;


bool cmp(pair<pair<double, double>, double> a, pair<pair<double, double>, double> b) {
    return a.second < b.second;
}

int get_parent(int x) {
    if (parents[x] == x) return x;
    return parents[x] = get_parent(parents[x]);
}

void union_parents(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a > b) parents[a] = b;
    else parents[b] = a;
}

void solution() {

    double dist = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            // 거리 계산  
            dist = sqrt(pow(nodes[i].first - nodes[j].first, 2) + pow(nodes[i].second - nodes[j].second, 2));
            // 두 별과 거리 넣기  
            edges.push_back({ {i, j}, dist });
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < n; i++) parents[i] = i;

    double sum = 0;
    for (int i = 0; i < edges.size(); i++) {
        if (get_parent(edges[i].first.first) != get_parent(edges[i].first.second)) {
            sum += edges[i].second;
            union_parents(edges[i].first.first, edges[i].first.second);
        }
    }

    printf("%0.2f", sum);
}

int main(void) {

    cin >> n;

    double y, x;
    for (int i = 0; i < n; i++) {
        cin >> y >> x;
        nodes.push_back({ y, x });
    }

    solution();
}


