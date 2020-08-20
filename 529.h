#pragma once
#include <vector>
#include <queue>
using namespace std;

class Solution529 {
private:
    int m, n;
    vector<int> fx = { -1,-1,0,1,1,1,0,-1 };
    vector<int> fy = { 0,1,1,1,0,-1,-1,-1 };
public:
    int findMine(vector<vector<char>> board, vector<int> click) {
        int num = 0;
        for (int i = 0; i < 8; i++) {
            int newi = click[0] + fx[i];
            int newj = click[1] + fy[i];

            if (newi < 0 || newi == m || newj < 0 || newj == n) {
                continue;
            }

            if (board[newi][newj] == 'M') {
                num++;
            }
        }
        return num;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();

        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        vector<vector<int>> visit(m, vector<int>(n, 0));

        queue<vector<int>> queue;
        queue.push(click);
        visit[click[0]][click[1]] = 1;

        while (!queue.empty()) {
            vector<int> p = queue.front();
            queue.pop();

            int mine = findMine(board, p);
            if (mine == 0) {
                board[p[0]][p[1]] = 'B';

                for (int i = 0; i < 8; i++) {
                    int newi = p[0] + fx[i];
                    int newj = p[1] + fy[i];

                    if (newi < 0 || newi == m || newj < 0 || newj == n) {
                        continue;
                    }

                    if (board[newi][newj]=='E' && visit[newi][newj] == 0) {
                        vector<int> q;
                        q.push_back(newi);
                        q.push_back(newj);
                        queue.push(q);

                        visit[newi][newj] = 1;
                    }
                }
            }
            else {
                board[p[0]][p[1]] = mine + '0';
            }
        }
        return board;
    }
};

void solution529();