#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num <= 0) return false;
		long long l = 0, r = num;
		while (l <= r) {
			long long m = l + (r - l) / 2;
			if (m * m == num) return true;
			if (m * m < num)
				l = m + 1;
			else
				r = m - 1;
		}
		return false;
	}
};

int main() {
	Solution s;
	cout << s.isPerfectSquare(169);
}