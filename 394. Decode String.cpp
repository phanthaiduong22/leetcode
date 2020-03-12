#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<string>st;
		int i = 0;
		while (i < s.size()) {
			string num = "";
			while (s[i] >= '0' && s[i] <= '9') {
				num += s[i];
				i++;
			}
			if (num != "")st.push(num);
			string text = "";
			while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				text += s[i];
				i++;
			}
			if (text != "")st.push(text);
			if (s[i] == '[') {
				st.push("[");
				i++;
			}
			else if (s[i] == ']') {
				string temp = "";
				while (st.top() != "[") {
					temp = st.top() + temp;
					st.pop();
				}
				st.pop();
				string temp1 = "";
				for (int i = 0; i < stoi(st.top()); i++) {
					temp1 += temp;
				}
				st.pop();
				st.push(temp1);
				i++;
			}

		}
		string ans = "";
		while (!st.empty()) {
			ans = st.top() + ans;
			st.pop();
		}
		return ans;
	}
};

int main() {
	string v = "12[abc]";
	Solution s;
	cout << s.decodeString(v);
}