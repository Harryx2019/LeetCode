#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution93 {
private:
	vector<string> results;
	int point[3];
	int n;
public:
	void findIpAddresses(string s, int i, int m) {
		if (m == 3) {
			if (n - i > 3) {
				return;
			}
			int sum = 0;
			int num = 0;
			int j;
			for (j = i; j < n; j++) {
				num = s[j] - '0';
				sum = sum * 10 + num;
				if (s[i] == '0') {
					j++;
					break;
				}
			}
			if (j != n) {
				return;
			}
			if (sum > 255) {
				return;
			}
			string result;
			for (int j = 0; j < n; j++) {
				if (j == point[0] || j == point[1] || j == point[2]) {
					result.push_back('.');
				}
				result.push_back(s[j]);
			}
			results.push_back(result);
		}
		else {
			int sum = 0;
			int num = 0;
			for (int j = i; j < n - 3 + m && (j - i) < 3; j++) {
				num = s[j] - '0';
				sum = sum * 10 + num;
				if (sum > 255) {
					break;
				}
				point[m] = j + 1;
				findIpAddresses(s, j + 1, m + 1);
				if (s[i] == '0') {
					break;
				}
			}
		}
	}
	vector<string> restoreIpAddresses(string s) {
		n = s.length();
		findIpAddresses(s, 0, 0);
		return results;
	}
};

void solution93();