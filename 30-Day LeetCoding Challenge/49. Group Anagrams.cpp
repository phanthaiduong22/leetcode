#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>>groupAnagrams(vector<string>& strs) {
		vector<vector<string>>ans;
		map<string, vector<string>>d;
		for (int i = 0; i < strs.size(); i++) {
			string temp = strs[i];
			sort(strs[i].begin(), strs[i].end());
			cout << strs[i] << endl;
			d[strs[i]].push_back(temp);
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
	vector<string> v = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution s;
	s.groupAnagrams(v);
}