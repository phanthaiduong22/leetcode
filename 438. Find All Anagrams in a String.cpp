#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		map<char, int>a, b;
		//khoi tao
		for (int i = 0; i < 26; i++) {
			a[i + 'a'];
			b[i + 'a'];
		}
		for (int i = 0; i < p.size(); i++) {
			b[p[i]]++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (i < p.size())
				a[s[i]]++;
			else {
				a[s[i]]++;
				a[s[i - p.size()]]--;
			}
			if (a == b)
				ans.push_back(i - p.size() + 1);
		}
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		return ans;
	}
};

int main() {
	string t = "af", p = "be";
	Solution s;
	s.findAnagrams(t, p);
}