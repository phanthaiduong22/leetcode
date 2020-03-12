#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int>d;
		for (int i = 0; i < nums.size(); i++) {
			if (d[nums[i]] == 0) {
				d[nums[i]] = i + 1;
			}
			else {
				if (i + 1 - d[nums[i]] <= k)
					return true;
				else
					d[nums[i]] = i + 1;
			}

		}
		return false;
	}
};

int main() {
	vector<int> v = { 1,2,3,1,2,3 };
	Solution s;
	cout << s.containsNearbyDuplicate(v, 2);
}