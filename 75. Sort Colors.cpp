#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int cnt_0 = 0, cnt_1 = 0, cnt_2 = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0)
				cnt_0++;
			else if (nums[i] == 1)
				cnt_1++;
			else if (nums[i] == 2)
				cnt_2++;
		}
		for (int i = 0; i < cnt_0; i++)
			nums[i] = 0;
		for (int i = cnt_0; i < cnt_0 + cnt_1; i++)
			nums[i] = 1;
		for (int i = cnt_0 + cnt_1; i < cnt_0 + cnt_1 + cnt_2; i++)
			nums[i] = 2;
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
	}
};

int main() {
	Solution s;
	vector<int>v = { 2,0,2,1,1,0 };
	s.sortColors(v);
}