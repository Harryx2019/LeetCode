#pragma once
#include <string>
using namespace std;
class Solution392 {
public:
    bool isSubsequence(string s, string t) {
        int s_length = s.length();
        if (s_length == 0) {
            return true;
        }
        int i;
        int index1 = t.find(s[0]);
        if (index1 == -1) {
            return false;
        }
        int index2 = -1;
        for (i = 1; i < s_length; i++) {
            index2 = t.find(s[i], index1+1);
            if (index2 != -1) {
                if (index1 < index2) {
                    index1 = index2;
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};

void solution392();