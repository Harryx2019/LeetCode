#pragma once
#include <vector>
#include <math.h>
using namespace std;
class Solution7 {
public:
    int reverse(int x) {
        //主要是整数溢出的问题
		if (x > -10 && x < 10) {
			return x;
		}
        int sum = 0;
        while (x != 0) {
            int pop = x % 10;
            x = x / 10;
            if (sum > INT_MAX / 10 || (sum == INT_MAX && pop > 7))return 0;
            if (sum < INT_MIN / 10 || (sum == INT_MIN && pop < -8))return 0;
            sum = sum * 10 + pop;
        }
        return sum;
    }
};

void solution7();