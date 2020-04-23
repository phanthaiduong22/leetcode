class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() == 0) return;
		int i = 0, j = 0;
		while (j <= nums.size() - 1) {
			if (i == j) j++;
			else if (nums[i] == 0 && nums[j] != 0)
				swap(nums[i], nums[j]);
			else if (nums[i] == 0 && nums[j] == 0)
				j++;
			else if (nums[i] != 0 && nums[j] == 0)
				i++;
			else {
				i++;
				j++;
			}
		}
	}
};