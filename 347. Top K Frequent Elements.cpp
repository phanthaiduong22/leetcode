#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int>m;
		vector<int> ans;
		map<int, int> ::iterator it;
		priority_queue<pair<int, int>>pq;
		for (int i = 0; i < nums.size(); i++)
			m[nums[i]]++;
		for (it = m.begin(); it != m.end(); it++)
			pq.push(make_pair(it->second, it->first));
		for (int i = 0; i < k; i++) {
			ans.push_back(pq.top().second);
			pq.pop();
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		return ans;
	}
};

int main() {
	vector<int> v = { 1 };
	Solution s;
	s.topKFrequent(v, 1);
}