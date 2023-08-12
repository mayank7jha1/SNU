// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int>gr[N];

// visited====0,1,2

bool dfs_helper(int node, int parent, int *visited, int color) {
	visited[node] = color;
	for (auto nbr : gr[node]) {
		if (visited[nbr] == 0) {
			int small_ans = dfs_helper(nbr, node, visited, 3 - color);   //1==3-1=2
			if (small_ans == 0) {
				return false;
			}
		} else if (nbr != parent and visited[nbr] == color) {
			return false;
		}
	}
	return true;
}

bool dfs(int n) {
	int visited[n] = {0};
	int color = 1;

	bool ans = dfs_helper(0, -1, visited, color);
	for (int i = 0; i < n; i++) {
		cout << i << " - Color " << visited[i] << endl;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	if (dfs(n)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}