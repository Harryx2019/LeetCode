#include <iostream>
#include "696.h"

void solution696() {
	string s;
	getline(cin, s);
	Solution696 solu;
	cout << solu.countBinarySubstrings(s);
}