#include <iostream>
#include "410.h"
void solution410() {
	vector<int> nums;
	int num;
	do {
		cin >> num;
		nums.push_back(num);
	} while (cin.get() != '\n');
	int m;
	cin >> m;
	Solution410 s;
	cout << s.splitArray(nums, m);
}