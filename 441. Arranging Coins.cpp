#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int arrangeCoins(int n) {
		if (n <= 0) return 0;
		long long l = 1;
		long long r = n;
		while (l <= r) {
			long long mid = (r - l) / 2 + l;
			if (((mid - 1) * mid) / 2 <= n && n <= (mid * (mid + 1)) / 2) {
				if (n != (mid * (mid + 1)) / 2) return mid - 1;
				return mid;
			}
			if (n < (mid * (mid + 1)) / 2)
				r = mid - 1;
			else
				l = mid + 1;
		}
		return r;
	}
};
int main() {
	Solution s;
	cout << s.arrangeCoins((1 << 31) - 1);
}