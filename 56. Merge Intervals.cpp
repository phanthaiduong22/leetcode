#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct option
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		return a.first < b.first || (a.first == b.first && a.second < b.second);
	}
};
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//convert vector to pair
		vector<vector<int>>ans;
		if (intervals.size() == 0) return ans;
		vector<pair<int, int>>a;
		for (int i = 0; i < intervals.size(); i++) 
			a.push_back(make_pair(intervals[i][0], intervals[i][1]));
		sort(a.begin(), a.end(), option());
		int left = a[0].first, right = a[0].second;
		for (int i = 1; i < a.size(); i++) {
			if (a[i].second <= right)
				continue;
			else if (a[i].first <= right)
				right = a[i].second;
			else {
				ans.push_back(vector<int>{left, right});
				left = a[i].first;
				right = a[i].second;
			}
		}
		ans.push_back(vector<int>{left, right});
		for (int i = 0; i < ans.size(); i++) 
			cout << ans[i][0] << " " << ans[i][1] << endl;
		return ans;
	}
};

int main() {
	vector<vector<int>> v = { {1, 4}, {4, 5} };
	Solution s;
	s.merge(v);
}