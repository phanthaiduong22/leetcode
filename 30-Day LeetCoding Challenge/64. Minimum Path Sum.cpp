#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>>d(m, vector<int>(n));
		d[0][0] = grid[0][0];
		for (int i = 1; i < m; i++) {
			d[i][0] = d[i - 1][0] + grid[i][0];
		}
		for (int j = 1; j < n; j++) {
			d[0][j] = d[0][j - 1] + grid[0][j];
		}
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				d[i][j] = min(d[i - 1][j], d[i][j - 1]) + grid[i][j];
			}
		}
		return d[m - 1][n - 1];
	}
};

int main() {
	vector<vector<int>> d = { {1,3,1} , {1,5,1} };
	Solution s;
	cout << s.minPathSum(d);
}