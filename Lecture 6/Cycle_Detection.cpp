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

	bool dfs_helper(T scr, map<T, bool>&visited, T parent) {
		visited[scr] = 1;
		for (auto x : l[scr]) {
			if (!visited[x]) {
				bool cycle_found = dfs_helper(x, visited, scr);
				if (cycle_found == 1) {
					return true;
				}
			} else if (x != parent) {
				return true;
			}
		}
		return false;
	}


	bool dfs() {
		map<T, bool>visited;
		for (auto x : l) {
			visited[x.first] = false;
		}

		return dfs_helper(0, visited, -1);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Graph<int>g;

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	//g.addEdge(5, 0);
	//g.addEdge(6, 7);

	cout << g.dfs();


	return 0;
}