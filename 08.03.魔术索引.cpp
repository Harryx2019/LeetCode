#include <iostream>
#include "08.03.h"

void solution0803() {
	vector<int> nums;
	int num;
	do {
		cin >> num;
		nums.push_back(num);
	} while (cin.get() != '\n');
	Solution0803 s;
	cout << s.findMagicIndex(nums);
}