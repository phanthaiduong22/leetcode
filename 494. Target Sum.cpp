#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int ans = 0;
	void backtracking(vector<int>& nums, int j, int sum, int S) {
		if (j == nums.size() - 1) {
			if (sum == S)
				ans++;
			return;
		}
		for (int i = 0; i < 2; i++) {
			if (i == 0)
				backtracking(nums, j + 1, sum + nums[j + 1], S);
			else
				backtracking(nums, j + 1, sum - nums[j + 1], S);
		}
	}
	int findTargetSumWays(vector<int>& nums, int S) {
		backtracking(nums, -1, 0, S);
		return ans;
	}
};

int main() {
	vector<int> v = { 1,1,1,1,1 };
	Solution s;
	cout << s.findTargetSumWays(v, 3);
}