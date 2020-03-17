#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int s = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > s) {
				if (nums[nums[i] - s - 1] > s) {
					return nums[i] - s;
				}
				else {
					nums[nums[i] - s - 1] += s;
				}
			}
			else {
				if (nums[nums[i] - 1] > s)
					return nums[i];
				else
					nums[nums[i] - 1] += s;
			}
		}
	}
};

int main() {
	Solution s;
	vector<int> v = { 1,1};
	cout << s.findDuplicate(v);
}