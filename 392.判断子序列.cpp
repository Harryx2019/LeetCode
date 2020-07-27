#include <iostream>
#include "392.h"

void solution392() {
	string s, t;
	getline(cin, s);
	getline(cin, t);
	Solution392 sol;
	cout<< sol.isSubsequence(s, t);
}