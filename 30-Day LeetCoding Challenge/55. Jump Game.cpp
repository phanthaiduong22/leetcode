#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1) return true;
		int m = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (i > m) return false;
			m = max(m, i + nums[i]);
			if (m >= nums.size() - 1)
				return true;
		}
		return false;
	}
};

int main() {
	vector<int> v = { 0,1 };
	Solution s;
	cout << s.canJump(v);
}