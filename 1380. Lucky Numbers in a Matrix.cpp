#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int>minrow, maxcol;
		for (int i = 0; i < matrix.size(); i++) {
			int min = 100005;
			for (int j = 0; j < matrix[i].size(); j++) {
				if (matrix[i][j] < min)
					min = matrix[i][j];
			}
			minrow.push_back(min);
		}
		for (int i = 0; i < matrix[0].size(); i++) {
			int max = 0;
			for (int j = 0; j < matrix.size(); j++) {
				if (matrix[j][i] > max)
					max = matrix[j][i];
			}
			maxcol.push_back(max);
		}
		vector<int>ans;
		for (int i = 0; i < minrow.size(); i++) {
			for (int j = 0; j < maxcol.size(); j++) {
				if (minrow[i] == maxcol[j]) {
					ans.push_back(minrow[i]);
				}
			}
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		return ans;
	}


};

int main() {
	vector<vector<int>>v = { {1} };
	Solution s;
	s.luckyNumbers(v);
}