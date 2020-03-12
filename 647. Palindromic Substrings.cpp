#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int countSubstrings(string s) {
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			ans++;
			int j = i - 1, k = i + 1;
			while (j >= 0 && k < s.size()) {
				if (s[j] == s[k])
					ans++;
				else break;
				j--;
				k++;
			}
			if (i < s.size() - 1 && s[i] == s[i + 1]) {
				ans++;
				j = i - 1, k = i + 2	;
				while (j >= 0 && k < s.size()) {
					if (s[j] == s[k])
						ans++;
					else break;
					j--;
					k++;
				}
			}
		}
		return ans;
	}
};

int main() {
	string v = "leetcode";
	Solution s;
	cout << s.countSubstrings(v);
}