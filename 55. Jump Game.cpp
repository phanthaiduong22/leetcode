#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int ans = 0;
	void backtracking(vector<int> a, int n, int pos, vector<int>& visited) {
		visited[pos] = true;
		if (pos == n - 1) {
			ans = 1;
			return;
		}
		for (int i = 1; i <= a[pos]; i++) {
			if (ans == 1) {
				return;
			}
			if (visited[pos + i] == false) {
				backtracking(a, n, pos + i, visited);
			}
		}
	}
	bool canJump(vector<int>& nums) {
		vector<int> visited(nums.size());
		backtracking(nums, nums.size(), 0, visited);
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> v = { 1,1,1,1 };
	cout << s.canJump(v) << endl;
}