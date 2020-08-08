#include <iostream>
#include "11.h"

void solution11() {
	vector<int> height;
	int num;
	do {
		cin >> num;
		height.push_back(num);
	} while (cin.get() != '\n');
	Solution11 s;
	cout << s.maxArea(height);
}