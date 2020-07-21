#include "167.h"

void solution167() {
	vector<int> numbers;
	int num;
	do {
		cin >> num;
		numbers.push_back(num);
	} while (cin.get() != '\n');
	Solution167 s;
	int target;
	cin >> target;
	numbers=s.twoSum(numbers, target);
	for (int i=0; i < numbers.size(); i++)
		cout << numbers[i] <<" ";
}