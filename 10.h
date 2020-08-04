#pragma once
#include <string>
using namespace std;
class Solution10 {
public:
	bool isMatch(string s, string p) {
		if (s == "") {
			if (p == "" || p[1] == '*') {
				return true;
			}
			return false;
		}
		if (p == "") {
			if (s == "") {
				return true;
			}
			return false;
		}
		int ls = s.length();
		int lp = p.length();
		int i = 0, j = 0;
		while (j < lp) {
			if (i == ls)
				break;
			if (p[j] == s[i] || p[j] == '.') {
				i++;
				j++;
				continue;
			}
			if (p[j] == '*') {
				if (p[j - 1] == s[i] || p[j - 1] == '.') {
					i++;
					continue;
				}
				j++;
				continue;
			}
			if (p[j] != s[i]) {
				if (p[j + 1] == '*') {
					j++;
					continue;
				}
			}
			return false;
		}
		if (i == ls) {
			if (j == lp)
				return true;
			if (j == lp - 1 && p[j] == '*')
				return true;
			if (j == lp - 2 && p[j + 1] == s[i - 1])
				return true;
		}
		return false;
	}
};

void solution10();