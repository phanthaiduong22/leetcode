#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		int ans = 0;
		map<char, int>d;
		for (int i = 0; i < s.size(); i++)
			d[s[i]]++;
		map<char, int>::iterator it;
		int t = 0;
		for (it = d.begin(); it != d.end(); it++) {
			if (it->second % 2 == 0) {
				ans += it->second;
				it->second = 0;
			}
			else {
				if (t == 0) {
					ans += it->second;
					t = 1;
				}
				else
					ans += (it->second - 1);
			}
		}
		return ans;
	}
};

int main() {
	string v = "";
	Solution s;
	cout << s.longestPalindrome(v);
}