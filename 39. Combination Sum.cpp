#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>>fResult;
	//vector<int> coinChangeProblem(int total, vector<int>coins, int n) {
	//	vector<int> result(total + 1);
	//	result[0] = 1;
	//	for (int i = 0; i < n; i++) {
	//		for (int j = coins[i]; j <= total; j++) {
	//			result[j] += result[j - coins[i]];
	//		}
	//	}
	//	return result;
	//}
	void printSolution(vector<int>& result, int total, vector<int>coins, int n, int pos) {
		if (total == 0) {
			fResult.push_back(result);
		}
		for (int i = pos; i < n; i++) {
			if (total >= coins[i]) {
				result.push_back(coins[i]);
				printSolution(result, total - coins[i], coins, n, i);
				result.pop_back();
			}
		}
	}
	vector<vector<int>>  combinationSum(vector<int>& candidates, int target) {
		//vector<int>result = coinChangeProblem(target, candidates, candidates.size());
		//for (int i = 0; i < result.size(); i++) {
		//	cout << result[i] << " ";
		//}
		vector<int>result;
		printSolution(result, target, candidates, candidates.size(), 0);
		return fResult;
	}
};

int main() {
	vector<int>v = { 2,3,6,7 };
	Solution s;
	vector<vector<int>>test = s.combinationSum(v, 7);
}