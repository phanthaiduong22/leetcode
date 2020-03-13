#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
		if (sum % 2 != 0) return false;
		sum = sum / 2;
		vector<int> total(sum + 1);
		total[0] = 1;
		for (int j = 0; j < nums.size(); j++) {
			for (int i = sum; i >= 1; i--) {
				if (i - nums[j] >= 0 && total[i - nums[j]] == 1)
					total[i] = 1;
			}
		}
		return total[sum];
	}
};

int main() {
	vector<int> v = { 1, 5, 11, 5 };
	Solution s;
	cout << s.canPartition(v);
}