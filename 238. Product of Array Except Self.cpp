#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> result(n, 1);
		if (n == 0) return result;
		result[0] = nums[0];
		for (int i = 1; i < n; i++) {
			result[i] = result[i - 1] * nums[i];
		}

		int multi = 1;
		for (int i = n - 1; i >= 1; i--) {
			result[i] = result[i - 1] * multi;
			multi *= nums[i];
		}
		result[0] = multi;
		for (int i = 0; i < n; i++) cout << result[i] << " ";
		return result;
	}
};

int main() {
	vector<int> v = {  };
	Solution s;
	s.productExceptSelf(v);
}