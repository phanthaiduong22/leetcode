#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> ans(num + 1);
		ans[0] = 0;
		if (num == 0) return ans;
		ans[1] = 1;
		if (num == 1)return ans;
		ans[2] = 1;
		if (num == 2) return ans;
		int j = 2; int k = 1;
		for (int i = 3; i <= num; i++, k--) {
			if (k == 0) {
				ans[i] = 1;
				k = i;
				j = i;
			}
			else {
				ans[i] = ans[j] + ans[i - j];
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.countBits(3);
}