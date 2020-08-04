#include <iostream>
#include "207.h"

void solution207() {
	int numCourses;
	cin >> numCourses;
	vector<vector<int>> prerequisites;
	vector<int> v;
	int a, b, i = 0;
	do {
		v.clear();
		cin >> a;
		v.push_back(a);
		cin >> b;
		v.push_back(b);
		prerequisites.push_back(v);
	} while (cin.get() != '\n');
	Solution207 s;
	for (auto i : s.canFinish(numCourses, prerequisites)) {
		cout << i << " ";
	}
}