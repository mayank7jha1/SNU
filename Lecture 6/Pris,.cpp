// Created by Mayank

#include <bits/stdc++.h>
using namespace std;
#define int long long

class Graph {
// Adj. list:
	vector<pair<int, int>>*l;//node,weight
	int V;
public:
	Graph(int n) {
		V = n;
		l = new vector<pair<int, int>>[n];
	}
	void addEdge(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}
	int prim_mst() {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		bool *visited = new bool[V] {0};
		int ans = 0;
		q.push({0, 0});//weight,node

		while (!q.empty()) {
			auto best = q.top();
			q.pop();

			int to_edge = best.second;
			int weight = best.first;
			if (visited[to_edge]) {
				continue;
			}

			ans += weight;
			visited[to_edge] = 1;
			for (auto x : l[to_edge]) {
				if (visited[x.first] == 0) {
					q.push({x.second, x.first});
				}
			}
		}
		return ans;
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//Graph g(5);
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.addEdge(x - 1, y - 1, w);
	}
	cout << g.prim_mst() << endl;

	return 0;
}