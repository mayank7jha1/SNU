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
		//map<T, bool>visited;
		map<T, int>distance;
		for (auto x : l) {
			distance[x.first] = INT_MAX;
		}
		queue<T>q;
		q.push(scr);
		//visited[scr] = true;
		distance[scr] = 0;
		while (!q.empty()) {
			T node = q.front();
			//cout << node << " ";
			q.pop();
			for (auto nbr : l[node]) {
				if (distance[nbr] == INT_MAX) {
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
				}
			}
		}
		for (auto x : l) {
			cout << x.first << "->" << distance[x.first] << endl;
		}
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
	g.addEdge(3, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.bfs(2);


	return 0;
}