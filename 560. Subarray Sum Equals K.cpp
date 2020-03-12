#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int, int>a;
		int sum = 0;
		int ans = 0;
		a[k] = 1;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (a[sum] > 0)
				ans += a[sum];
			a[k + sum]++;
		}
		return ans;
	}
};

int main() {
	vector<int> v = { 2,-1,3,1,-2 };
	Solution s;
	cout << s.subarraySum(v, 1);
}