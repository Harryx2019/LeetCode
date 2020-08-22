#include <iostream>
#include "5480.h"

void solution5480() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges = vector<vector<int>>(m, vector<int>(2));
	int num;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> num;
			edges[i][j] = num;
		}
	}
	Solution5480 s;
	vector<int> result = s.findSmallestSetOfVertices(n, edges);
}