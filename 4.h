#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution4 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size()+nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
        int n = merged.size();
        int mid = n / 2;
        double ans = 0;
        if (n % 2 == 0) {
            ans = 1.0 * (merged[mid - 1] + merged[mid]) / 2;
        }
        else {
            ans = merged[mid];
        }
        return ans;
    }
};

void solution4();