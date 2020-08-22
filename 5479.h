#pragma once
#include <string>
#include <algorithm>
using namespace std;
class Solution5479 {
public:
    string thousandSeparator(int n) {
        if (n == 0) {
            return "0";
        }
        string result;
        int d;
        int count = 0;
        while (n != 0) {
            if (count == 3) {
                result.push_back('.');
                count = 0;
            }
            d = n % 10;
            n = n / 10;
            result.push_back(d + '0');
            count++;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

void solution5479();