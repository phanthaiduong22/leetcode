#include <iostream>
#include <vector>

using namespace std;

vector<string>s = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

class Solution {
public:
	vector<string>fAns;
	void backtracking(string n, int cnt, string ans) {
		if (cnt == n.size()) {
			fAns.push_back(ans);
			return;
		}

		for (int i = 0; i < s[n[cnt] - '0'].size(); i++) {
			ans += s[n[cnt] - '0'][i];
			backtracking(n, cnt + 1, ans);
			ans.erase(ans.begin() + ans.size() - 1);
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits == "") {
			return fAns;
		}
		backtracking(digits, 0, "");
		return fAns;
	}
};

int main() {
	Solution a;
	vector<string> test = a.letterCombinations("2");
	for (int i = 0; i < test.size(); i++) {
		cout << test[i] << endl;
	}
}