#pragma once
#include <string>
using namespace std;

class Solution647 {
public:
	int countSubstrings(string s) {
		// 方法一 双指针 解答错误
		/*int count = 0;
		int n = s.length();
		if (n == 0 || n == 1) {
			return s.length();
		}
		else {
			count += n;
		}

		int i, j, k, p;
		for (i = 0; i < n - 1; i++) {
			k = i;
			j = n - 1;
			while (k < j) {
				while (s[k] != s[j] && k < j) {
					j--;
				}
				if (k == j) {
					continue;
				}

				p = j;
				while (k < j) {
					if (s[k] == s[j]) {
						k++;
						j--;
					}
					else {
						k = i;
						break;
					}
				}

				if (k == j || k == j + 1) {
					count++;
					k = i;
					j = p - 1;
				}
			}
		}
		return count;*/

		// 方法二 中心扩展法
		int n = s.size(), ans = 0;
		for (int i = 0; i < 2 * n - 1; ++i) {
			int l = i / 2, r = i / 2 + i % 2;
			while (l >= 0 && r < n && s[l] == s[r]) {
				--l;
				++r;
				++ans;
			}
		}
		return ans;
	}
};

void solution647();