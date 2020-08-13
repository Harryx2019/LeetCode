#pragma once
#include <string>
#include <algorithm>
using namespace std;

class Solution43 {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		int length1 = num1.length();
		int length2 = num2.length();
		int length = length1 + length2;

		string result(length, '0');
		int i, j, k, r;

		int num, sum, product, d;
		for (i = length2 - 1; i >= 0; i--) {
			r = length2 - 1 - i;
			num = num2[i] - '0';
			for (j = length1 - 1; j >= 0; j--) {
				product = num * (num1[j] - '0');

				sum = product % 10 + (result[r] - '0');
				result[r] = sum % 10 + '0';

				k = r + 1;
				d = sum / 10 + product / 10;
				while (d != 0) {
					sum = result[k] - '0' + d;
					result[k] = sum % 10 + '0';
					d = sum / 10;
					k++;
				}

				r++;
			}
		}

		reverse(result.begin(),result.end());
		int n = length;
		for (i = 0; i < length; i++) {
			if (result[i] != '0') {
				break;
			}
			n--;
		}
		return result.substr(i,n);
	}
};

void solution43();