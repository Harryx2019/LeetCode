#pragma once
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

class Solution5 {
public:
    string longestPalindrome(string s) {
        string b = s;
        reverse(b.begin(), b.end());
        const int n=s.length();
        int** c = new int*[n+1];
        for (int i = 0; i <= n; i++)
            c[i] = new int[n+1];
        int i, j;
        for (i = 0; i <= n; i++) {
            c[i][0] = 0;
            c[0][i] = 0;
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (s[i - 1] == b[j - 1])
                    c[i][j] = c[i - 1][j - 1] + 1;
                else if (c[i - 1][j] >= c[i][j - 1])
                    c[i][j] = c[i - 1][j];
                else
                    c[i][j] = c[i][j - 1];
            }
        }
        int k = c[n][n];
        b[k] = '\0';
        i = j = n;
        while (k > 0) {
            if (c[i][j] == c[i - 1][j])
                i--;
            else if (c[i][j] == c[i][j - 1])
                j--;
            else
            {
                k--;
                b[k] = s[i - 1];
                i--;
                j--;
            }
        }
        k = c[n][n];
        return b.substr(0,k);
    }
};

void solution5();