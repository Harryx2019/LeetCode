#include <iostream>
#include "6.h"

void solution6() {
	string s;
	cin >> s;
	int numRows;
	cin.get();
	cin >> numRows;
	Solution6 sol;
	cout << sol.convert(s, numRows);
}