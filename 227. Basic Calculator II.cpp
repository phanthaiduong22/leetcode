#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		//
		int i = 0;
		vector<string> d;
		string temp = "";
		while (i < s.size()) {
			if (s[i] == '+' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				d.push_back(temp);
				temp = s[i];
				d.push_back(temp);
				temp = "";
			}
			else if (s[i] != ' ') {
				temp += s[i];
			}
			i++;
		}
		d.push_back(temp);

		//
		int temp1 = 1;
		//bool nhanchia = 0;
		vector<string> A;
		A.push_back(d[0]);
		for (int i = 1; i < d.size(); i += 2) {
			if (d[i] == "+" || d[i] == "-") {
				A.push_back(d[i]);
				A.push_back(d[i + 1]);
			}

			else if (d[i] == "*") {
				temp1 = stoi(A[A.size() - 1]) * stoi(d[i + 1]);
				A[A.size() - 1] = to_string(temp1);
			}
			else if (d[i] == "/") {
				temp1 = stoi(A[A.size() - 1]) / stoi(d[i + 1]);
				A[A.size() - 1] = to_string(temp1);
			}
			else
				A.push_back(d[i]);
		}

		string ans = A[0];
		for (int i = 1; i < A.size(); i += 2) {
			if (A[i] == "+") {
				temp1 = stoi(ans) + stoi(A[i + 1]);
				ans = to_string(temp1);
			}
			else {
				temp1 = stoi(ans) - stoi(A[i + 1]);
				ans = to_string(temp1);
			}
		}
		return stoi(ans);
	}
};

int main() {
	string a = " 2/5  ";
	Solution s;
	cout << s.calculate(a);
}