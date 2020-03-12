#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

	class Solution {
	public:
		int binarySearchFindMax(vector<int>nums, int left, int right) {
			if (right < left)
				return 0;
			if (left == right)
				return left;
			int mid = left + (right - left) / 2;
			if (mid < right && nums[mid]>nums[mid + 1])
				return mid;
			if (mid > left && nums[mid] < nums[mid - 1])
				return mid - 1;
			if (nums[mid] > nums[left])
				return binarySearchFindMax(nums, mid + 1, right);
			else
				return binarySearchFindMax(nums, left, mid - 1);
		}
		int binarySearch(vector<int>nums, int left, int right, int target) {
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (nums[mid] == target)
					return mid;
				else if (nums[mid] > target) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			return -1;
		}
		int search(vector<int>& nums, int target) {
			if (nums.size() == 0) {
				return -1;
			}
			else if (nums.size() == 1) {
				return (nums[0] == target) - 1;
			}
			int indexMax = binarySearchFindMax(nums, 0, nums.size() - 1);
			cout << indexMax << endl;
			int a = binarySearch(nums, 0, indexMax, target);
			int b = binarySearch(nums, indexMax + 1, nums.size() - 1, target);
			if (a == -1 && b == -1) {
				return -1;
			}
			else {
				return max(a, b);
			}
		}
	};

int main() {
	Solution a;
	vector<int> v = { 4,5,6,7,0,1,2 };
	cout << a.search(v, 0);
}