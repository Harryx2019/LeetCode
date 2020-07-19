#pragma once
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> a;
        int rk = -1, ans;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                a.erase(s[i - 1]);
            }
            while (rk + 1 < n && !a.count(s[rk + 1])) {
                a.insert(s[rk + 1]);
                rk++;
            }
            ans = max(rk-i+1, ans);
        }
        return ans;
    }
};

void solution3();