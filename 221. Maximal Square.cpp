#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		vector<vector<int>> d(matrix.size(), vector<int>(matrix[0].size()));
		int r = matrix.size(), c = matrix[0].size();
		int ans = 0;
		for (int i = 0; i < r; i++) {
			d[i][0] = matrix[i][0] - '0';
			if (d[i][0] == 1)ans = 1;
		}
		for (int i = 0; i < c; i++) {
			d[0][i] = matrix[0][i] - '0';
			if (d[0][i] == 1)ans = 1;
		}
		for (int i = 1; i < r; i++) {
			for (int j = 1; j < c; j++) {
				if (matrix[i][j] == '0') d[i][j] = 0;
				else
					d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + 1;
				if (d[i][j] > ans)
					ans = d[i][j];
			}
		}
		return ans * ans;
	}
};

int main() {
	vector<vector<char>> v = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
	Solution s;
	cout << s.maximalSquare(v);
}