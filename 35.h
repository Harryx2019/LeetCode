#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*int low = 0;
        int high = nums.size() - 1;
        if (target < nums[low])
            return 0;
        else if (target > nums[high])
            return nums.size();
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (target < nums[i])
                return i;
        }*/
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

void solution35();