#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int bsFirst(vector<int>& a, int left, int right, int x)//timphantudautien	
	{
		if (left <= right)
		{
			int mid = left + (right - left) / 2;
			if ((mid == left || x > a[mid - 1]) && a[mid] == x)
				return mid;
			else if (x > a[mid])
				return bsFirst(a, mid + 1, right, x);
			else
				return bsFirst(a, left, mid - 1, x);
		}
		return -1;
	}
	int bsLast(vector<int>& a, int left, int right, int x)//timphantucuoicung	
	{
		if (left <= right)
		{
			int mid = left + (right - left) / 2;
			if ((mid == right || x < a[mid + 1]) && a[mid] == x)
				return mid;
			else if (x >= a[mid])
				return bsLast(a, mid + 1, right, x);
			else
				return bsLast(a, left, mid - 1, x);
		}
		return -1;
	}
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int>ans;
		ans.push_back(bsFirst(nums, 0, nums.size() - 1, target));
		ans.push_back(bsLast(nums, 0, nums.size() - 1, target));
		return ans;
	}
};
int main() {
	Solution a;
	vector<int>v = { 2,2 };
	vector<int> ans = a.searchRange(v, 2);
	cout << ans[0] << " " << ans[1];

}