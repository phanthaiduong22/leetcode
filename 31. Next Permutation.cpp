#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1;
		for (; i > 0; i--) {
			if (nums[i] > nums[i - 1]) {
				swap(nums[i], nums[i - 1]);
				break;
			}
		}
		if (i == 0) {
			reverse(nums.begin(), nums.end());
		}
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i];
		}
	}
};

int main() {
	Solution a;
	vector<int>v = { 1,5,5 };
	a.nextPermutation(v);
}