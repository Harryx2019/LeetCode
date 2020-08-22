#pragma once
#include <vector>
using namespace std;

class Solution5480 {
private:
    vector<vector<int>> vertexs;
    vector<int> begins;
    vector<int> visit;
    vector<int> select;
public:
    bool Try(int k,int i) {
        if (k == 0) {
            for (int j = 0; j < begins.size(); j++) {
                if (select[j] == 1) {
                    for (int p = 0; p < vertexs[begins[j]].size(); p++) {
                        if (visit[vertexs[begins[j]][p]] == 0) {
                            visit[vertexs[begins[j]][p]] = 1;
                        }
                    }
                }
            }
            for (int j = 0; j < visit.size(); j++) {
                if (visit[j] == 0) {
                    visit.assign(visit.size(), 0);
                    return false;
                }
            }
            return true;
        }
        for (int j = i; j < begins.size(); j++) {
            select[j] = 1;
            if (Try(k - 1, j + 1)) {
                return true;
            }

            select[j] = 0;
            if (Try(k, j + 1)) {
                return true;
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vertexs = vector<vector<int>>(n);
        vector<int> ingree = vector<int>(n);
        for (int i = 0; i < edges.size(); i++) {
            vertexs[edges[i][0]].push_back(edges[i][1]);
            ingree[edges[i][1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (ingree[i] == 0) {
                begins.push_back(i);
            }
        }

        visit = vector<int>(n);
        select = vector<int>(begins.size());
        for (int k = 1; k <= begins.size(); k++) {
            if (Try(k, 0)) {
                vector<int> result;
                for (int i = 0; i < select.size(); i++) {
                    if (select[i] == 1) {
                        result.push_back(begins[i]);
                    }
                }
                return result;
            }
        }
    }
};

void solution5480();