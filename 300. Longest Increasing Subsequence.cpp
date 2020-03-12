#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int lowerBound(vector<int> a, vector<int>result, int n, int x) {
		int left = 0;
		int right = n;
		int pos = right;
		while (left < right) {
			int mid = left + (right - left) / 2;
			int index = result[mid];
			if (a[index] >= x) {
				pos = mid;
				right = mid;
			}
			else
				left = mid + 1;
		}
		return pos;
	}
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int length = 1;
		vector<int> result;
		result.push_back(0);
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < nums[result[0]]) {
				result[0] = i;
			}
			else if (nums[i] > nums[result[result.size() - 1]]) {
				result.push_back(i);
			}
			else {
				int pos = lowerBound(nums, result, result.size(), nums[i]);
				result[pos] = i;
			}
		}
		return result.size();
	}
};

int main() {
	vector<int> v = { 10,9,2,5,3,4 };
	Solution s;
	cout << s.lengthOfLIS(v);
}