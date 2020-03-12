#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> fAns;
	void backtracking(vector<int>a, vector<int>result, int n, vector<bool>visited) {
		if (result.size() == n) {
			fAns.push_back(result);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				result.push_back(a[i]);
				visited[i] = true;
				backtracking(a, result, n, visited);
				result.pop_back();
				visited[i] = false;
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> visited(nums.size() + 1);
		vector<int>result;
		backtracking(nums, result, nums.size(), visited);
		return fAns;
	}
};

int main() {
	vector<int> v = { 1,2,3 };
	Solution s;
	vector<vector<int>>test = s.permute(v);
	for (int i = 0; i < test.size(); i++) {
		for (int j = 0; j < test[i].size(); j++) {
			cout << test[i][j] << " ";
		}
		cout << endl;
	}
}