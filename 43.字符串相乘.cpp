#include <iostream>
#include "43.h"

void solution43() {
	string num1, num2;
	getline(cin, num1);
	getline(cin, num2);
	Solution43 s;
	cout << s.multiply(num1, num2);
}