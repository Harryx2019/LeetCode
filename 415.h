#pragma once
#include <string>
using namespace std;

class Solution415 {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int a, b, sum, d = 0;
        int l1 = num1.length();
        int l2 = num2.length();
        int i = l1 - 1, j = l2 - 1;
        while (i >= 0 && j >= 0) {
            a = num1[i] - '0';
            b = num2[j] - '0';
            sum = a + b + d;
            d = sum / 10;
            ans.push_back(sum % 10 + '0');
            i--;
            j--;
        }
        while (i >= 0) {
            a = num1[i] - '0';
            sum = a + d;
            d = sum / 10;
            ans.push_back(sum % 10 + '0');
            i--;
        }
        while (j >= 0) {
            a = num2[j] - '0';
            sum = a + d;
            d = sum / 10;
            ans.push_back(sum % 10 + '0');
            j--;
        }
        if (d != 0) {
            ans.push_back(d + '0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

void solution415();