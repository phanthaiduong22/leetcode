#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if ((n & (n - 1)) == 0)
			return true;
		return false;
	}
};

int main() {
	Solution s;
	cout << s.isPowerOfTwo(218);
}