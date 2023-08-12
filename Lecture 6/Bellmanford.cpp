// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

int n, m;
template<typename T>
class Graph {
	unordered_map<T, list<pair<T, int>>> l;
public:
	void addEdge(T u, T v, int dist) {
		l[u].push_back({v, dist});
		l[v].push_back({u, dist});
	}
	void BellmanFord(T scr) {
		unordered_map<T, int>dist;
		for (int i = 0; i < n; i++) {
			dist[i] = INT_MAX;
		}
		dist[scr] = 0;
		int vertices = n;

		for (int i = 0; i < vertices - 1; i++) {
			for (auto node : l) {
				T u = node.first;
				for (auto children : l[u]) {
					T v = children.first;
					int edge_dist = children.second;
					if (dist[u] != INT_MAX and (dist[v] > dist[u] + edge_dist)) {
						dist[v] = dist[u] + edge_dist;
					}
				}
			}
		}
		// TO detect negative edge cycle:
		for (auto node : l) {
			T u = node.first;
			for (auto children : l[u]) {
				T v = children.first;
				int edge_dist = children.second;
				if (dist[u] != INT_MAX and (dist[v] > dist[u] + edge_dist)) {
					cout << "Negative Egde Cycle" << endl;
					return;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			cout << "Distance of " << i << " from " << scr << " : " << dist[i] << endl;
		}
	}
};




int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	Graph <int>g;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		//cout << x << " " << y << " " << w << endl;
		g.addEdge(x - 1, y - 1 , w);
	}
	g.BellmanFord(0);
	//cout << "Maynk";

	return 0;
}