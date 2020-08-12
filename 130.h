#pragma once
#include <vector>
#include <queue>
using namespace std;

struct Point
{
	int x, y;
	Point(int x, int y) :x(x), y(y) { }
};
class Solution130 {
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();

		vector<vector<char>> temp = board;
		board= vector<vector<char>>(m, vector<char>(n, 'X'));

		vector<vector<int>> visit(m, vector<int>(n));
		queue<Point> queue;
		int i, j;
		for (i = 0, j = 0; j < n; j++) {
			if (temp[i][j] == 'O') {
				Point p(i, j);
				queue.push(p);
				visit[i][j] = 1;
			}
		}
		for (j = 0, i = 1; i < m - 1; i++) {
			if (temp[i][j] == 'O') {
				Point p(i, j);
				queue.push(p);
				visit[i][j] = 1;
			}
		}
		for (i = m - 1, j = 0; j < n; j++) {
			if (temp[i][j] == 'O') {
				Point p(i, j);
				queue.push(p);
				visit[i][j] = 1;
			}
		}
		for (j = n - 1, i = 1; i < m - 1; i++) {
			if (temp[i][j] == 'O') {
				Point p(i, j);
				queue.push(p);
				visit[i][j] = 1;
			}
		}

		vector<int> fx = { 1,0,-1,0 };
		vector<int> fy = { 0,1,0,-1 };
		while (!queue.empty()) {
			Point p = queue.front();
			queue.pop();
			board[p.x][p.y] = 'O';
			for (int k = 0; k < 4; k++) {
				i = p.x + fx[k];
				j = p.y + fy[k];
				if (i < 0 || i == m || j < 0 || j == n) {
					continue;
				}
				if (temp[i][j] == 'O' && visit[i][j] == 0) {
					queue.push(Point(i, j));
					visit[i][j] = 1;
				}
			}
		}
	}
};

void solution130();