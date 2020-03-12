#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}
};

int main() {
	vector<int>v = { 3,2,3,1,2,4,5,5,6 };
	Solution s;
	cout << s.findKthLargest(v, 4);
}