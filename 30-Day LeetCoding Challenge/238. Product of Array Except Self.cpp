#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int>ans;
		int l = nums.size();
		if (l == 0) return ans;
		ans.push_back(nums[0]);
		for (int i = 1; i < l; i++) {
			ans.push_back(ans[i - 1] * nums[i]);
		}
		ans[l - 1] = ans[l - 2];
		int temp = nums[l - 1];
		for (int i = l - 2; i > 0; i--) {
			ans[i] = temp * ans[i - 1];
			temp *= nums[i];
		}
		ans[0] = temp;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		return ans;
	}
};

int main() {
	vector<int> v = { 1,2,3,4 };
	Solution s;
	s.productExceptSelf(v);
}