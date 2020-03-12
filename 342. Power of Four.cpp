class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && 42949667296 % num == 0;
	}
};