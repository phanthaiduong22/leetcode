#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numTrees(int n) {
		int ans = 1;
		//ans = 2nCn / n+1
		for (int i = 1; i <= n; i++) {
			ans *= (n + i);
			ans /= i;
		}
		return ans/ (n+1);
	}
};

int main() {
	Solution s;
	cout << s.numTrees(3);
}