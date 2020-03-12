#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> a = nums;
		sort(a.begin(), a.end());
		int i, j;
		for (i = 0; i < a.size(); i++) {
			if (a[i] != nums[i]) {
				break;
			}
		}
		for (j = a.size() - 1; j >= 0; j--) {
			if (a[j] != nums[j]) {
				break;
			}
		}
		return max(0, j - i + 1);
	}
};

int main() {
	vector<int>v = { 2, 2, 5, 4 ,9 };
	Solution s;
	cout << s.findUnsortedSubarray(v);
}