#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution410 {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (m == 1) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
            }
            return sum;
        }
        vector<int> max;
        for (int i = 0; i <= n-m; i++) {
            int sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += nums[j];
            }
            vector<int> remain(nums.begin() + i + 1, nums.end());
            int remainMax = splitArray(remain, m - 1);
            if (sum > remainMax) {
                max.push_back(sum);
            }
            else {
                max.push_back(remainMax);
            }
        }
        return *min_element(max.begin(),max.end());
    }
};

void solution410();