#pragma once
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

class Solution5 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int** c = new  int*[n];
        for (int i = 0; i < n; i++) {
            c[i] = new int[n];
            c[i][i] = 1;
        }
        int max = 1;
        int begin = 0;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] != s[j]) {
                    c[i][j] = 0;
                }
                else {
                    if (j - i < 3) {
                        c[i][j] = 1;
                    }
                    else {
                        c[i][j] = c[i + 1][j - 1];
                    }
                }
                if (c[i][j] == 1 && j - i + 1 >= max) {
                    begin = i;
                    max = j - i + 1;
                }
            }
        }
        return s.substr(begin, max);
    }
};

void solution5();