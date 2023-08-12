#include <bits/stdc++.h>
using namespace std;


template<typename T>
class Graph {
	map<T, list<T>>l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
	}
	bool dfs_helper(T scr, map<T, bool>&visited, map<T, bool>&instack) {
		visited[scr] = true;
		instack[scr] = true;
		for (auto nbr : l[scr]) {
			if ((!visited[nbr] and dfs_helper(nbr, visited, instack)) or instack[nbr]) {
				return true;
			}
		}
		instack[scr] = false;
		return false;
	}

	bool dfs() {
		map<T, bool>visited, instack;
		// for (auto x : l) {
		// 	if (!visited[x.first]) {
		bool cycle_found = dfs_helper(1, visited, instack);
		if (cycle_found == 1) {
			return true;
		}
		//}
		//}
		return false;
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
	cout << g.dfs() << endl;



	return 0;
}