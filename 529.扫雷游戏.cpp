#include <iostream>
#include "529.h"

void solution529() {
	int m, n;
	cin >> m >> n;
	char ch;
	vector<vector<char>> board(m, vector<char>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			board[i][j] = ch;
		}
	}
	vector<int> click;
	cout << "Click:";
	cin >> m >> n;
	click.push_back(m);
	click.push_back(n);

	Solution529 s;
	s.updateBoard(board, click);
}