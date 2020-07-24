#pragma once
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct point {
	int x, y, pre;
	point(int x, int y, int pre) :x(x), y(y), pre(pre) { }
};

struct point2 {
	int x, y, prex, prey;
	point2(int x, int y, int prex, int prey) :x(x), y(y), prex(prex), prey(prey) { }
};

class Solution64 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		//深度优先搜索
		int m = grid.size();
		int n = grid[0].size();
		if (m == 1 && n == 1) {
			return grid[0][0];
		}
		vector<vector<int>> visit(m, vector<int>(n));
		visit[0][0] = grid[0][0];

		int i, j, k;
		int fx[2] = { 1,0 };
		int fy[2] = { 0,1 };
		stack<point2> s;

		point2 a(0, 0, -1, -1);
		s.push(a);
		while (!s.empty()) {
			point2 pre = s.top();
			s.pop();
			for (k = 0; k < 2; k++) {
				i = pre.x + fx[k];
				j = pre.y + fy[k];
				if (i < 0 || i == m || j < 0 || j == n) {
					continue;
				}
				int value = visit[pre.x][pre.y] + grid[i][j];
				if (visit[i][j] == 0 || (visit[i][j] != 0 && value < visit[i][j])) {
					point2 b(i, j, pre.x, pre.y);
					s.push(b);
					visit[i][j] = value;
				}
				else {
					continue;
				}
			}
		}
		return visit[m - 1][n - 1];

		//广度优先搜索
		/*int m = grid.size();
		int n = grid[0].size();
		if (m == 1 && n == 1) {
			return grid[0][0];
		}
		int fx[2] = { 0,1 };
		int fy[2] = { 1,0 };
		vector<point> queue;
		int qh = -1, qe = 0;
		point a(0, 0, -1);
		queue.push_back(a);

		vector<vector<int>> visit(m, vector<int>(n));
		visit[0][0] = grid[0][0];

		int i, j, k;
		while (qh != qe) {
			qh++;
			for (k = 0; k < 2; k++) {
				i = queue[qh].x + fx[k];
				j = queue[qh].y + fy[k];

				if (i < 0 || i == m || j < 0 || j == n) {
					continue;
				}
				int value = visit[queue[qh].x][queue[qh].y] + grid[i][j];
				if (visit[i][j] == 0 || (visit[i][j] != 0 && value < visit[i][j])) {
					qe++;
					point b(i, j, qh);
					queue.push_back(b);
					visit[i][j] = value;
				}
				else {
					continue;
				}
			}
		}
		return visit[m-1][n-1];*/
		
		/*动态规划
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp;
		for (int i = 0; i < m; i++) {
			dp.push_back(vector<int>(n));
		}
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < n; i++) {
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[m-1][n-1];*/
	}
};

void solution64();