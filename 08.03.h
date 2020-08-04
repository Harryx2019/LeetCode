#pragma once
#include <vector>
using namespace std;

class Solution0803 {
public:
    int findMagicIndex(vector<int>& nums) {
        int i = 0;
        for (auto num : nums) {
            if (num == i)
                return i;
            i++;
        }
        return -1;
    }
};

void solution0803();