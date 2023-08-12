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

	void topological_sort(int n) {
		map<T, int>indegree;
		for (auto x : l) {
			indegree[x.first] = 0;
		}
		for (auto x : l) {
			for (auto p : x.second) {
				indegree[p]++;
			}
		}
		queue<T>q;
		for (auto x : indegree) {
			if (x.second == 0) {
				q.push(x.first);
			}
		}

		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	Graph<int>g;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, t;
		cin >> s >> t;
		g.addEdge(s, t);
	}
	g.topological_sort(2);


	return 0;
}