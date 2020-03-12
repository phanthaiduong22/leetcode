#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>>F_ans;
		int n = nums.size();
		for (int i = 0; i < (1 << n); i++) {
			vector<int>sub;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sub.push_back(nums[j]);
				}
			}
			F_ans.push_back(sub);
		}
		return F_ans;
	}
};

int main() {
	vector<int> v = { 1,2,3 };
	Solution s;
	s.subsets(v);
}