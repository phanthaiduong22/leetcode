#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>>d;
		vector<vector<string>>ans;
		for (int i = 0; i < strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			d[temp].push_back(strs[i]);
		}
		map<string, vector<string>>::iterator it;
		for (it = d.begin(); it != d.end(); it++) {
			ans.push_back(it->second);
		}
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
		return ans;
	}
};

int main() {
	vector<string> v = { "eat", "tea", "tan", "ate", "nat", "bat","eatd" };
	Solution s;
	s.groupAnagrams(v);
}