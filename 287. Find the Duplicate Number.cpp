#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int i = 0;
		while (1) {
			if (nums[i] < 0)
				return -nums[i];
			else
			{
				int j = nums[nums[i] - 1];
				nums[nums[i] - 1] = -nums[i];
				i = j;
			}
x		}
	}
};

int main() {
	vector<int> v = { 1,3,4,2,2 };
	Solution s;
	cout << s.findDuplicate(v);
}