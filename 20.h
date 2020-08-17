#pragma once
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution20 {
public:
	bool isValid(string s) {
		// {}{}[]≤‚ ‘”√¿˝ ß∞‹ ∑Ω∑®¥ÌŒÛ£°
		/*if (s.length() == 0) {
			return true;
		}
		if (s.length() == 1) {
			return false;
		}
		int i = 0, j = s.length() - 1, k;
		char left[3] = { '(','[','{' };
		char right[3] = { ')',']','}' };
		while (i < j) {
			int index;
			char ch;
			for (index = 0; index < 3; index++) {
				if (s[i] == left[index]) {
					ch = right[index];
					break;
				}
			}

			if (s[j] == ch) {
				i++;
				j--;
			}
			else {
				k = j;
				j--;
				while (i < j) {
					if (s[j] == ch) {
						if (isValid(s.substr(j + 1, k - j))) {
							i++;
							j--;
							break;
						}
						else {
							return false;
						}
					}
					else {
						j--;
					}
				}
				if (i == j) {
					return false;
				}
			}
		}
		return i == j + 1;*/

		// ”√’ª¥Ê¥¢◊Û¿®∫≈ “¿¥Œ”Î”–¿®∫≈∆•≈‰
		if (s.length() == 0) {
			return true;
		}
		if (s.length() % 2 != 0) {
			return false;
		}
		stack<char> stack;
		unordered_map<char, char> pairs = {
			{')','('},
			{'}','{'},
			{']','['}
		};

		for (auto ch : s) {
			if (pairs.count(ch)) {
				if (stack.empty() || stack.top() != pairs[ch]) {
					return false;
				}
				stack.pop();
			}
			else {
				stack.push(ch);
			}
		}

		return stack.empty();
	}
};

void solution20();