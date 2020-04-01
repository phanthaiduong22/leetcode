#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			ans = (ans ^ nums[i]);
		}
		return ans;
	}
};

int main() {
	vector<int> v = { 2 };
	Solution s;
	cout << s.singleNumber(v);
}