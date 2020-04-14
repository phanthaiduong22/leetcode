#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	string stringShift(string s, vector<vector<int>>& shift) {
		int cnt = 0;
		for (int i = 0; i < shift.size(); i++) {
			if (shift[i][0] == 1)
				cnt += shift[i][1];
			else
				cnt -= shift[i][1];
		}
		int l = s.size();
		if (cnt > 0)
			l = s.size() - (cnt % l);
		else if (cnt < 0)
			l = abs(cnt) % s.size();
		else return s;
		string ans = "";
		for (int i = l; i < s.size(); i++)
			ans += s[i];
		for (int i = 0; i < l; i++)
			ans += s[i];
		return ans;
	}
};

int main() {
	string v = "abcdefg";
	vector<vector<int>>shift = { {0,1},{0,1},{0,1} };
	Solution s;
	cout << s.stringShift(v, shift);

}