#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int, int>s;
		int sum = 0, ans = 0;
		s[0] = 1;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (s[sum - k] > 0)
				ans += s[sum - k];
			s[sum]++;
		}
		return ans;
	}
};

int main() {
	vector<int> v = { 1,1,1 };
	Solution s;
	cout << s.subarraySum(v, 2);
}