#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount <= 0) return 0;
		sort(coins.begin(), coins.end());
		vector<int>ans(amount + 1, 999999999);
		for (int j = 0; j < coins.size(); j++) {
			for (int i = coins[j]; i <= amount; i++) {
				if (i == coins[j])ans[i] = 1;
				else if (ans[i - coins[j]] != 0)
					ans[i] = min(ans[i], ans[i - coins[j]] + 1);
			}
		}
		if (ans[amount] == 0 || ans[amount] == 999999999) return -1;
		return ans[amount];
	}
};

int main() {
	vector<int> v = { 186,419,83,408 };
	Solution s;
	cout << s.coinChange(v, 6249);
}