#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) return 0;
		vector<vector<int>>graph(matrix.size(), vector<int>(matrix[0].size()));
		int ans = 0;
		if (matrix[0][0] == '0') ans = 0; else ans = 1;
		for (int i = 0; i < matrix.size(); i++)
			if (matrix[i][0] == '1') {
				graph[i][0] = 1;
				ans = 1;
			}
		for (int j = 0; j < matrix[0].size(); j++)
			if (matrix[0][j] == '1') {
				graph[0][j] = 1;
				ans = 1;
			}
		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 1; j < matrix[0].size(); j++) {
				if (matrix[i][j] == '0' || matrix[i - 1][j] == '0' || matrix[i][j - 1] == '0')
				{
					graph[i][j] = matrix[i][j] - '0';
				}
				else {
					if (graph[i - 1][j - 1] == graph[i][j - 1] && graph[i][j - 1] == graph[i - 1][j])
						graph[i][j] = graph[i - 1][j - 1] + 1;
					else
						graph[i][j] = max(max(graph[i - 1][j - 1], graph[i][j - 1]), graph[i - 1][j]);
				}
				if (graph[i][j] > ans)
					ans = graph[i][j];
			}
		}
		return ans * ans;
	}
};
int main() {
	vector<vector<char>> v = { {'1','1'},{'1','1'} };
	Solution s;
	cout << s.maximalSquare(v);
}