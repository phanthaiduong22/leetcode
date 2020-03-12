#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		else if (nums.size() == 1) return nums[0];
		else if (nums.size() == 2) return max(nums[0], nums[1]);
		else {
			vector<int>sum(nums.size());
			sum[0] = nums[0];
			sum[1] = max(nums[0], nums[1]);
			for (int i = 2; i < nums.size(); i++) {
				sum[i] = max(sum[i - 1], sum[i - 2] + nums[i]);
			}
			return sum[nums.size() - 1];
		}
	}
};

int main() {
	vector<int>v = { 2,7,9,3,1 };
	Solution s;
	cout << s.rob(v);
}