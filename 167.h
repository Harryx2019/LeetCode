#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Solution167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] > target)
                j--;
            else if (numbers[i] + numbers[j] < target)
                i++;
            else 
                break;
        }
        vector<int> ans;
        if (i < j) {
            ans.push_back(i + 1);
            ans.push_back(j + 1);
        }
        return ans;
    }
};

void solution167();