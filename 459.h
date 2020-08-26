#pragma once
#include <string>
using namespace std;

class Solution459 {
public:
    bool repeatedSubstringPattern(string s) {
        //穷举
        int length = s.length() / 2;
        string substring;
        for (int i = 0; i < length; i++) {
            substring.push_back(s[i]);
            int subLength = i + 1;
            string repeatedSubstring = substring;
            while (subLength < s.length()) {
                repeatedSubstring.append(substring);
                subLength += i + 1;
            }
            if (subLength == s.length()) {
                if (repeatedSubstring == s) {
                    return true;
                }
            }
        }
        return false;

        //KMP 模式子串
    }
};

void solution459();