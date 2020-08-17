#pragma once
#include <vector>
#include <queue>
using namespace std;

struct Point
{
    int x, y;
    Point(int x,int y):x(x),y(y){ }
};

class Solution773 {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //vector<vector<int>> result = image;

        queue<Point> queue;
        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];
        vector<vector<int>> visit(m, vector<int>(n, 0));
        queue.push(Point(sr, sc));
        visit[sr][sc] = 1;
        image[sr][sc] = newColor;

        vector<int> fx = { -1,1,0,0 };
        vector<int> fy = { 0,0,-1,1 };

        while (!queue.empty()) {
            Point p = queue.front();
            queue.pop();

            for (int i = 0; i < 4; i++) {
                int x = p.x + fx[i];
                int y = p.y + fy[i];
                if (x < 0 || x == m || y < 0 || y == n) {
                    continue;
                }
                if (image[x][y] == oldColor && visit[x][y] == 0) {
                    image[x][y] = newColor;
                    visit[x][y] = 1;
                    queue.push(Point(x, y));
                }
            }
        }
        return image;
    }
};

void solution773();