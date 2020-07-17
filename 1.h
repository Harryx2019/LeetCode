#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> myhash;

        for (int i = 0; i < nums.size(); i++) {
            myhash[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (myhash[target - nums[i]] && (myhash[target - nums[i]] != i)) {
                ans.push_back(i);
                ans.push_back(myhash[target - nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};

void solution1();