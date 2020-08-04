#include <iostream>
#include "415.h"

void solution415() {
	string num1, num2;
	getline(cin, num1);
	getline(cin, num2);
	Solution415 s;
	cout << s.addStrings(num1, num2);
}