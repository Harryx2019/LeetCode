#pragma once
#include <vector>
#include <queue>
using namespace std;

class Solution207 {
public:
    vector<int> canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> indegree(numCourses, 0);
        for (auto vertex : prerequisites) {
            graph[vertex[1]].push_back(vertex[0]);
            indegree[vertex[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            for (auto vertex : graph[course]) {
                indegree[vertex]--;
                if (indegree[vertex] == 0) {
                    q.push(vertex);
                }
            }
            result.push_back(course);
        }
        if (result.size() != numCourses) {
            result.clear();
        }
        return result;
    }
};

void solution207();