// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>>l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
	}
	void dfs_helper(T scr, map<T, bool>&visited, list<T>&ordering) {
		visited[scr] = true;
		for (auto nbr : l[scr]) {
			if (!visited[nbr]) {
				dfs_helper(nbr, visited, ordering);
			}
		}
		ordering.push_front(scr);
		return;
	}

	void dfs() {
		map<T, bool>visited;
		list<T>ordering;
		for (auto x : l) {
			T node = x.first;
			visited[node] = false;
		}
		for (auto p : l) {
			T node = p.first;
			if (!visited[node]) {
				dfs_helper(node, visited, ordering);
			}
		}
		for (auto x : ordering) {
			cout << x << " ";
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Graph<string>g;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string s, t;
		cin >> s >> t;
		g.addEdge(s, t);
	}
	g.dfs();



	return 0;
}