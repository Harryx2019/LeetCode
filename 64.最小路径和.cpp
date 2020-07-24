#include <iostream>
#include "64.h"

void solution64() {
	vector<vector<int>> grid;
	int m, n;
	cin >> m >> n;
	int i, j;
	for (i = 0; i < m; i++) {
		grid.push_back(vector<int>());
	}
	int num;
	for (int i = 0; i < m; i++) {
		cin.get();
		for (int j = 0; j < n; j++) {
			cin >> num;
			grid[i].push_back(num);
		}
	}
	Solution64 s;
	cout<<s.minPathSum(grid);
}