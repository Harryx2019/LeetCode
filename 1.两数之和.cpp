#include <iostream>
#include "1.h"
using namespace std;

void solution1() {
    Solution1 s;
    vector<int> nums;
    int num;
    do {
        cin >> num;
        nums.push_back(num);
    } while (cin.get() != '\n');
    int target;
    cin >> target;
    vector<int> ans = s.twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}