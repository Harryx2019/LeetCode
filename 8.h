#pragma once
#include <string>
using namespace std;
class Solution8 {
public:
	int myAtoi(string str) {
		int i = 0;
		int ans = 0;
		int flag = 1;
		char ch = str[i];
		if (ch != ' ' && ch != '-' && ch != '+' && (ch < '0' || ch>'9')) {
			return 0;
		}
		while (ch == ' ') {
			ch = str[++i];
		}
		if (ch == '-') {
			flag = -1;
			ch = str[++i];
		}
		else if (ch == '+') {
			ch = str[++i];
		}
		int num = 0;
		while (ch >= '0' && ch <= '9') {
			num = (ch - '0') * flag;
			if (ans > INT_MAX / 10 || (ans == INT_MAX/10 && num > 7))return INT_MAX;
			if (ans < INT_MIN / 10 || (ans == INT_MIN/10 && num < -8))return INT_MIN;
			ans = ans * 10 + num;
			ch = str[++i];
		}
		return ans;
	}
};

void solution8();