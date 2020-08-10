#pragma once
#include <string>
using namespace std;
class Solution696 {
public:
	int countBinarySubstrings(string s) {
		// 穷举遍历 超时！
		/*int n = s.length();
		int i, j;
		int count = 0, num1, num0;
		int flag;
		string str;
		for (i = 0; i < n - 1; i++) {
			str.clear();
			str.push_back(s[i]);
			if (s[i] == '0') {
				num0 = 1;
				num1 = 0;
				flag = 0;
			}
			else {
				num0 = 0;
				num1 = 1;
				flag = 1;
			}
			for (j = i + 1; j < n; j++) {
				if (flag == 0) {
					if (s[j] == '0') {
						num0++;
					}
					else {
						flag = 2;
						num1++;
					}
					str.push_back(s[j]);
				}
				else if (flag == 1) {
					if (s[j] == '1') {
						num1++;
					}
					else {
						flag = 3;
						num0++;
					}
					str.push_back(s[j]);
				}
				else if (flag == 2) {
					if (s[j] == '1') {
						str.push_back(s[j]);
						if (num0 == num1) {
							count++;
						}
						num1++;
					}
					else {
						break;
					}
				}
				else {
					if (s[j] == '0') {
						str.push_back(s[j]);
						if (num0 == num1) {
							count++;
						}
						num0++;
					}
					else {
						break;
					}
				}
			}
			if (num0 == num1) {
				count++;
			}
		}
		return count;*/
		// 计算相邻数组大小
		int n = s.length();
		int i = 0;
		int result = 0;
		int count=0, last = 0;
		while (i < n) {
			char ch = s[i++];
			count = 1;
			while (i < n && s[i] == ch) {
				count++;
				i++;
			}
			result += min(last, count);
			last = count;
		}
		return result;
	}
};

void solution696();