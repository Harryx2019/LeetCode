#include <iostream>
#include "35.h"
using namespace std;

void solution35() {
	vector<int> a;
	int num;
	do {
		cin >> num;
		a.push_back(num);
	} while (cin.get() != '\n');
	int target;
	cin >> target;
	Solution35 s;
	cout<<s.searchInsert(a, target)<<endl;
}