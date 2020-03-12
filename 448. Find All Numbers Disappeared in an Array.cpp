#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int max = nums.size();
		vector<int>ans;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] <= max && nums[nums[i] - 1] <= max)
				nums[nums[i] - 1] += max;
			else if (nums[i] - max - 1 >= 0 && nums[nums[i] - max - 1] <= max)
				nums[nums[i] - max - 1] += max;
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] <= max)
				ans.push_back(i + 1);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		return ans;
	}
};

int main() {
	vector<int> v = { 4,3,2,7,7,2,3,1 };
	Solution s;
	s.findDisappearedNumbers(v);

}