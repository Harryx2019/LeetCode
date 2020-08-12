#include "130.h"
#include <iostream>

void solution130() {
	int m, n;
	cin >> m >> n;
	vector<vector<char>> board(m, vector<char>(n));
	char ch;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	Solution130 s;
	s.solve(board);
}