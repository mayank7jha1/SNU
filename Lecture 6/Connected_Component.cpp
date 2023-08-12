// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>>l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);//birectional and unweighted;
	}

	void dfs_helper(T scr, map<T, bool>&visited) {
		cout << scr << " ";
		visited[scr] = true;
		for (auto x : l[scr]) {
			if (!visited[x]) {
				dfs_helper(x, visited);
			}
		}
	}


	void dfs() {
		map<T, bool>visited;
		for (auto x : l) {
			visited[x.first] = false;
		}

		int cnt = 0;
		for (auto x : l) {
			if (!visited[x.first]) {
				cout << "Component " << cnt << "-->";
				dfs_helper(x.first, visited);
				cnt++;
			}
		}
		cout << endl << cnt;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Graph<int>g;

	g.addEdge(0, 4);
	g.addEdge(0, 3);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(8, 6);
	g.addEdge(6, 7);

	g.dfs();


	return 0;
}