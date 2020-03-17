#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 1) return nums[0];
		int ans = nums[0];
		int max_positive = 0, max_negative = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0 && max_positive == 0) {
				max_positive = nums[i];
			}
			else if (nums[i] < 0 && max_negative == 0) {
				max_negative = nums[i];
			}
			else if (nums[i] == 0) {
				max_negative = 0;
				max_positive = 0;
			}
			else {
				max_positive *= nums[i];
				max_negative *= nums[i];
			}
			ans = max(max_positive, max_negative);
		}
		return ans;
	}
};


int main() {
	vector<int> v = { 2,3,-2,4 };
	Solution s;
	cout << s.maxProduct(v);
}