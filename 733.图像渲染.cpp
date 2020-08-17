#include <iostream>
#include "773.h"

void solution773()
{
	int m, n;
	cin >> m >> n;
	vector<vector<int>> image(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		int num;
		for (int j = 0; j < n; j++) {
			cin >> num;
			image[i][j] = num;
		}
	}
	Solution773 s;
	int sr, sc, newColor;
	cout << "sr=";
	cin >> sr;
	cout << "sc=";
	cin >> sc;
	cout << "newColor=";
	cin >> newColor;
	s.floodFill(image, sr, sc, newColor);
}
