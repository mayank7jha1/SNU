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

	void bfs(T scr) {
		map<T, bool>visited;
		queue<T>q;
		q.push(scr);
		visited[scr] = true;
		while (!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
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
	g.addEdge(1, 2);
	g.addEdge(2, 1);
	g.addEdge(3, 1);
	// g.addEdge(3, 1);
	// g.addEdge(3, 5);
	// g.addEdge(4, 2);
	// g.addEdge(4, 3);
	// g.addEdge(5, 5);

	g.bfs(1);


	return 0;
}