#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct option
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
	{
		return  a.first > b.first || (a.first == b.first && a.second > b.second)
			;
	}
};
class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		vector<vector<int>>ans(people.size());
		priority_queue<pair<int, int>, vector<pair<int, int>>, option>pq;
		for (int i = 0; i < people.size(); i++) {
			pq.push({ people[i][0], people[i][1] });
		}
		while (!pq.empty()) {
			int u = pq.top().first;
			int v = pq.top().second;
			int temp = pq.top().second;
			pq.pop();
			//cout << pq.top().first << " " << pq.top().second << endl;
			int j = 0;
			while (j < people.size()) {
				if (ans[j].empty() || ans[j][0] >= u) {
					temp--;
				}
				j++;
				if (temp <= 0) break;
			}
			if (temp == -1) j = 0;
			//cout << j << endl;
			while (!ans[j].empty()) {
				j++;
			}
			ans[j].push_back(u);
			ans[j].push_back(v);
		}
		return ans;
	}
};

int main() {
	vector<vector<int>> v = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	Solution s;

	s.reconstructQueue(v);
}