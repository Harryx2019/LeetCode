#pragma once
#include <vector>
#include <string>
using namespace std;

class Solution17 {
private:
    int n;
    string Digits;
    vector<string> result;
    vector<vector<char>> teleNum = { {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'} };
    string temp;
public:
    void Try(int k) {
        if (k == n) {
            result.push_back(temp);
        }
        else {
            int t = Digits[k] - '0' - 2;
            for (int i = 0; i < teleNum[t].size(); i++) {
                temp.push_back(teleNum[t][i]);
                Try(k + 1);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        Digits = digits;
        n = Digits.length();
        if (n == 0) {
            return result;
        }
        Try(0);
        return result;
    }
};

void solution17();