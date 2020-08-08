#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution11 {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int i = 0, j = n - 1;
		int maxArea = 0;
		while (i <= j) {
			maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
			if (height[i] > height[j]) {
				j--;
			}
			else {
				i++;
			}
		}
		return maxArea;
	}
};
void solution11();