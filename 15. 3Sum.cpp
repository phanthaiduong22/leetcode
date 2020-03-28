#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>ans;
		sort(nums.begin(), nums.end());
		int s = nums.size();
		for (int i = 0; i < s - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1;
			int r = s - 1;
			while (l < r) {
				if (nums[i] + nums[l] + nums[r] == 0) {
					ans.push_back(vector<int> {nums[i], nums[l], nums[r]});
					while (l < s - 1 && nums[l] == nums[l + 1])
						l++;
					while (r > i + 1 && nums[r - 1] == nums[r])
						r--;
					l++;
					r--;
				}
				else if (nums[i] + nums[l] + nums[r] > 0) {
					while (r > i + 1 && nums[r - 1] == nums[r])
						r--;
					r--;
				}
				else {
					while (l < s - 1 && nums[l] == nums[l + 1])
						l++;
					l++;
				}
			}
		}
		return ans;
	}
};
int main() {
	vector<int> v = { 0,0,0,1,-1 };
	Solution s;
	s.threeSum(v);
}