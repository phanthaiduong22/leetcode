#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numSquares(int n) {
		int ans = 0;
		while (n) {
			ans++;
			int k = log10(n) / log10(2);
			cout << n << " " << k << endl;
			n -= pow(k, 2);
		}
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.numSquares(12);
}