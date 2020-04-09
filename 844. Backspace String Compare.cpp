#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool backspaceCompare(string S, string T) {
		vector<char>a, b;
		for (int i = 0; i < S.size(); i++) {
			if (S[i] == '#' && a.size() > 0)
				a.pop_back();
			else if (S[i] != '#')
				a.push_back(S[i]);
		}
		for (int i = 0; i < T.size(); i++) {
			if (T[i] == '#' && b.size() > 0)
				b.pop_back();
			else if (T[i] != '#')
				b.push_back(T[i]);
		}
		return a == b;
	}
};

int main() {
	string S = "", T = "";
	Solution s;
	cout << s.backspaceCompare(S, T);
}