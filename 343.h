#pragma once
#include <iostream>
using namespace std;
class Solution343 {
private:
    int num = 0;
    int max = 1;
public:
    void DFS(int sum, int k, int prio,int now) {
        if (sum > num) {
            return;
        }
        else if (sum == num) {
            if (k == 1)
                return;
            if (now > max) {
                max = now;
            }
        }
        else {
            for (int j = prio; j > 0; j--) {
                sum += j;
                if (sum > num) {
                    sum -= j;
                    continue;
                }
                DFS(sum, k + 1, j, now * j);
                sum -= j;
            }
        }
    }
    int integerBreak(int n) {
        num = n;
        DFS(0, 0, n, 1);
        return max;
    }
};

void solution343();