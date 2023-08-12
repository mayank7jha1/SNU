// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int>gr[N];
vector<int>rev_gr[N];


void dfs(bool *visited, vector<int>&stack, int node) {
	visited[node] = true;
	for (auto nbr : gr[node]) {
		if (!visited[nbr]) {
			dfs(visited, stack, nbr);
		}
	}
	stack.push_back(node);
}

void dfs2(bool *visited, int node) {
	visited[node] = true;
	cout << node << " ";
	for (auto nbr : rev_gr[node]) {
		if (!visited[nbr]) {
			dfs2(visited, nbr);
		}
	}
}


void solve(int n) {
	bool visited[n] = {0};

	vector<int>stack;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(visited, stack, i);
		}
	}

	memset(visited, 0, sizeof(visited));

	char component = 'A';
	for (int x = stack.size() - 1; x >= 0; x--) {
		int node = stack[x];
		if (!visited[node]) {
			cout << "Component " << component << " ";
			dfs2(visited, node);
			cout << endl;
			component++;
		}
	}
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
		rev_gr[y].push_back(x);
	}

	solve(n);

	return 0;
}
