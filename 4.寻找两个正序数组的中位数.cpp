#include <iostream>
#include <vector>
#include "4.h"
using namespace std;

void solution4() {
	vector<int> nums1, nums2;
	int num;
	do {
		cin >> num;
		nums1.push_back(num);
	} while (cin.get() != '\n');
	do {
		cin >> num;
		nums2.push_back(num);
	} while (cin.get() != '\n');
	Solution4 s;
	cout << s.findMedianSortedArrays(nums1, nums2);
}