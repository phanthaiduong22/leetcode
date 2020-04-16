#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool checkValidString(string s) {
		int i = 0;
		stack<int>st;
		while (i < s.size()) {
			if (s[i] == '(')
				st.push(0);
			else if (s[i] == '*') {
				if (st.size() != 0 && st.top() != 0) {
					int u = st.top() + 1;
					st.pop();
					st.push(u);
				}
				else
					st.push(1);
			}
			else {
				if (st.size() == 0) return false;
				int u = st.top();
				st.pop();
				if (u != 0) {
					if (st.size() == 0) {
						if (u != 1) {
							st.push(u - 1);
						}
					}
					else {
						st.pop();
						if (st.size() > 0 && st.top() != 0) {
							int k = st.top();
							st.pop();
							st.push(u + k);
						}
						else
							st.push(u);
					}
				}
			}
			i++;
		}
		int cnt = 0;
		while (st.size() > 0) {
			int u = st.top();
			st.pop();
			if (u != 0)
				cnt += u;
			else
				cnt--;
			if (cnt < 0)
				return false;
		}
		return true;
	}
};

int main() {
	string v = "(";
	Solution s;
	cout << s.checkValidString(v);
}