#pragma once
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution133 {
private:
    vector<Node*> graph;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->neighbors.size() == 0) {
            return new Node(node->val);
        }

        graph.push_back(new Node(0));
        graph.push_back(new Node(1));

        queue<Node*> queue;
        queue.push(node);

        int n = 1;
        vector<int> visit;
        visit.push_back(0);
        visit.push_back(1);

        while (!queue.empty()) {
            Node* p = queue.front();
            queue.pop();
            int val = p->val;

            vector<Node*> pNeighbors;
            int neighborsNum = p->neighbors.size();
            for (int i = 0; i < neighborsNum; i++) {
                int val = p->neighbors[i]->val;

                if (val > n) {
                    for (int i = n + 1; i <= val; i++) {
                        graph.push_back(new Node(i));
                        visit.push_back(0);
                    }
                    n = val;
                }

                pNeighbors.push_back(graph[val]);

                if (visit[val] == 0) {
                    queue.push(p->neighbors[i]);
                    visit[val] = 1;
                }
            }

            graph[val]->neighbors = pNeighbors;
        }

        return graph[1];
    }
};

void solution133();