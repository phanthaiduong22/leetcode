#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string>fAns;
	char str[2] = { '(',')' };
	void backtracking(string ans, int cnt, stack<char> s, int n) {
		if (cnt == 2 * n) {
			if (s.empty()) {
				fAns.push_back(ans);
			}
			return;
		}
		for (int i = 0; i < 2; i++) {
			if (!s.empty()) {
				if (s.top() == '(' && str[i] == ')') {
					s.pop();
				}
				else {
					s.push(str[i]);
				}
			}
			else {
				s.push(str[i]);
			}
			backtracking(ans + str[i], cnt + 1, s, n);
			if (!s.empty())
				s.pop();
		}
	}
	vector<string> generateParenthesis(int n) {
		if (n == 0)
			return fAns;
		stack<char> st;
		backtracking("", 0, st, n);
		return fAns;
	}
};

int main() {
	Solution test;
	vector<string>ans = test.generateParenthesis(0);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}