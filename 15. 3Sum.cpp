#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	void sort3(int& a, int& b, int& c) {
		if (a > c)
			swap(a, c);
		if (a > b)
			swap(a, b);
		if (b > c)
			swap(b, c);
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>ans;
		if (nums.size() < 3) return ans;
		map<int, int>d;
		map<pair<int, int>, int>checkDuplicate;
		//map<string, bool>checkDuplicate;
		for (int i = 0; i < nums.size(); i++)
			d[nums[i]]++;

		for (int i = 0; i < nums.size() - 2; i++) {
			for (int j = i + 1; j < nums.size() - 1; j++) {
				int a = nums[i];
				int b = nums[j];
				int c = -a - b;
				d[a]--;
				d[b]--;
				d[c]--;
				if (d[a] >= 0 && d[b] >= 0 && d[c] >= 0) {
					sort3(a, b, c);
					//string s_temp = to_string(a) + to_string(b) + to_string(c);
					//cout << s_temp << endl;
					map<pair<int, int>, int>::iterator it;
					it = checkDuplicate.find(make_pair(a, b));
					if (it == checkDuplicate.end()) {
						vector<int> temp;
						temp.push_back(a);
						temp.push_back(b);
						temp.push_back(c);
						ans.push_back(temp);
						checkDuplicate[make_pair(a, b)] = c;
					}
				}
				d[a]++;
				d[b]++;
				d[c]++;
			}
		}
		cout << endl;
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
	vector<int> v = { 0,0,0 };
	Solution s;
	s.threeSum(v);
}