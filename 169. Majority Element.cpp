#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int>d;
		int times = nums.size() / 2;
		for (int i = 0; i < nums.size(); i++) {
			d[nums[i]]++;
			if (d[nums[i]] > times) {
				return nums[i];
			}
		}
		return 0;
	}
};

int main() {
	vector<int> v = { 2,2,1,1,1,2,2 };
	Solution s;
	cout << s.majorityElement(v);
}