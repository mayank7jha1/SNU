// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

class Graph {
	map<string, list<pair<string, int>>>l;
public:
	void addEdge(string x, string y, bool bidirectional, int w) {
		l[x].push_back(make_pair(y, w));
		if (bidirectional) {
			l[y].push_back({x, w});
		}
	}

	void printlist() {
		for (auto x : l) {
			string s = x.first;
			list<pair<string, int>>nbr = x.second;
			cout << s << " ";
			for (auto l : nbr) {
				string destination = l.first;
				int weight = l.second;
				cout << destination << "->" << weight << ",";
			}
			cout << endl;
		}

	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Graph g;
	g.addEdge("A", "B", 1, 20);
	g.addEdge("B", "D", 1, 40);
	g.addEdge("A", "C", 1, 20);
	g.addEdge("C", "D", 1, 20);
	g.addEdge("A", "D", 1, 20);

	g.printlist();


	return 0;
}