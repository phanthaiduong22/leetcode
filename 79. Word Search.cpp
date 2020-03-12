#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int ans = 0;
	void backtracking(vector<vector<char>>& board, int i, int j, int cnt, string word, vector<vector<bool>>visited) {
		visited[i][j] = true;
		if (cnt == word.size() - 1) {
			ans = 1;
			return;
		}
		if (ans == 1) {
			return;
		}

		if (i + 1 < board.size() && visited[i + 1][j] == false && board[i + 1][j] == word[cnt + 1]) {
			backtracking(board, i + 1, j, cnt + 1, word, visited);
		}
		if (j + 1 < board[0].size() && visited[i][j + 1] == false && board[i][j + 1] == word[cnt + 1]) {
			backtracking(board, i, j + 1, cnt + 1, word, visited);
		}
		if (i - 1 >= 0 && visited[i - 1][j] == false && board[i - 1][j] == word[cnt + 1]) {
			backtracking(board, i - 1, j, cnt + 1, word, visited);
		}
		if (j - 1 >= 0 && visited[i][j - 1] == false && board[i][j - 1] == word[cnt + 1]) {
			backtracking(board, i, j - 1, cnt + 1, word, visited);
		}
		if (ans == 1) {
			return;
		}

	}
	bool exist(vector<vector<char>>& board, string word) {
		int n = board.size(), m = board[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == word[0]) {
					vector<vector<bool>>visited(n, vector<bool>(m));
					backtracking(board, i, j, 0, word, visited);
					if (ans == 1) return true;
				}
			}
		}
		return false;
	}
};

int main() {
	vector<vector<char>> v = {
	{'A','B','C','E'} ,
	{'S','F','C','S'} ,
	{'A','D','E','E' }
	};
	Solution s;
	cout << s.exist(v, "ABCB");

}