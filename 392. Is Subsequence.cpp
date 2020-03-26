#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s == "") return 1;
		int i = 0;
		int j = 0;
		while (j < t.size()) {
			if (s[i] == t[j]) {
				i++;
				j++;
				if (i == s.size())
					return 1;
			}
			else {
				j++;
			}
		}
		return 0;
	}
};

int main() {
	string a = "a";
	string b = "";
	Solution s;
	cout << s.isSubsequence(a, b);
}