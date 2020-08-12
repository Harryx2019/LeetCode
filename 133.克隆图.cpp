#include "133.h"
#include <iostream>

void solution133() {
	int n;
	cin >> n;
	vector<Node*> graph;
	for (int i = 0; i <= n; i++) {
		graph.push_back(new Node(i));
	}
	for (int i = 1; i <= n; i++) {
		int val;
		vector<Node*> pNeighbors;
		do {
			cin >> val;
			pNeighbors.push_back(graph[val]);
		} while (cin.get() != '\n');

		graph[i]->neighbors = pNeighbors;
	}
	Solution133 s;
	Node* clone = s.cloneGraph(graph[1]);
}