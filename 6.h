#pragma once
#include <string>
#include <vector>
using namespace std;
class Solution6 {
public:
    string convert(string s, int numRows) {
        string ans;
        int group, remain, numColumns;
        int length = s.length();
        if (numRows == 1) {
            return s;
        }
        group = length / (2 * (numRows - 1));
        numColumns = group * (numRows - 1);
        remain = length % (2 * (numRows - 1));
        if (remain != 0) {
            if (remain <= numRows) {
                numColumns++;
            }
            else {
                numColumns += remain - numRows + 1;
            }
        }
        vector<vector<int>> zMatrix(numRows, vector<int>(numColumns));

        int count = 1;
        int i, j, k;
        for (i = 0; i < group; i++) {
			for (j = 0; j < numRows; j++) {
				zMatrix[j][i * (numRows - 1)] = count++;
			}
			for (j = numRows - 2, k = 1; j > 0; j--, k++) {
                zMatrix[j][i * (numRows - 1) + k] = count++;
			}
        }
        if (remain != 0) {
            if (remain <= numRows) {
                for (i = 0; i < remain; i++) {
                    zMatrix[i][numColumns - 1] = count++;
                }
            }
            else {
                for (i = 0; i < numRows; i++) {
                    zMatrix[i][group * (numRows - 1)] = count++;
                }
                for (i = numRows - 2,j = group * (numRows - 1)+1; j < numColumns; i--,j++) {
                    zMatrix[i][j] = count++;
                }
            }
        }
        for (i = 0; i < numRows; i++) {
            for (j = 0; j < numColumns; j++) {
                if (zMatrix[i][j] != 0) {
                    ans.push_back(s[zMatrix[i][j] - 1]);
                }
            }
        }

        return ans;
    }
};

void solution6();