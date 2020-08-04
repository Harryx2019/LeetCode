#include <iostream>
#include "10.h"

void solution10() {
	string s, p;
	getline(cin, s);
	getline(cin, p);
	Solution10 sol;
	cout << sol.isMatch(s, p);
}