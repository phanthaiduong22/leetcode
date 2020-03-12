#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		if (amount == 0) return 0;
		vector<int> ans(amount + 1);
		ans[0] = 0;
		for (int i = 0; i < coins.size(); i++) {
			int j, k;
			if (i == coins.size() - 1) k = amount + 1;
			else k = coins[i + 1];
			j = coins[i];
			for (j; j < k, j <= amount; j++) {

				if (j == coins[i])
					ans[j] = 1;
				else if (ans[j - coins[i]] == 0)
					ans[j] = 0;
				else if (j - coins[i] <= amount)
					ans[j] = 1 + ans[j - coins[i]];
			}
		}
		if (ans[amount] == 0) return -1;
		return ans[amount];
	}
};

int main() {
	vector<int> v = { 186,419,83,408 };
	Solution s;
	cout << s.coinChange(v, 6249);
}