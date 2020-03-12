#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	void BFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int n, int m) {
		for (int k = 0; k < 4; k++) {
			if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m && visited[i + dx[k]][j + dy[k]] == 0 && grid[i + dx[k]][j + dy[k]] == '1') {
				visited[i + dx[k]][j + dy[k]] = 1;
				BFS(grid, visited, i + dx[k], j + dy[k], n, m);
			}
		}
		return;
	}
	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		int n = grid.size();
		if (n == 0) return 0;
		int m = grid[0].size();
		vector<vector<bool>>visited(n, vector<bool>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1' && visited[i][j] == 0) {
					visited[i][j] = 1;
					BFS(grid, visited, i, j, n, m);
					ans++;
				}
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<char>> v = { };
	Solution s;
	cout << s.numIslands(v);
}