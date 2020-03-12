#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		vector<int>d(200);
		for (int i = 0; i < s.size(); i++) {
			if (d[s[i]] == 0)
				d[s[i]] = t[i];
			else if (d[s[i]] != t[i])
				return false;
		}
		vector<int>c(200);
		for (int i = 0; i < t.size(); i++) {
			if (c[t[i]] == 0)
				c[t[i]] = s[i];
			else if (c[t[i]] != s[i])
				return false;
		}
		return true;
	}
};

int main() {
	Solution s;
	cout << s.isIsomorphic("ab", "aa");
}