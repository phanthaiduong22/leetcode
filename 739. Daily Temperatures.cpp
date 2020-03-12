#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		if (T.size() == 0) return T;
		vector<int>ans(T.size());
		stack<pair<int, int>>s;
		s.push({ T[T.size() - 1],T.size() - 1 });
		for (int i = T.size() - 2; i >= 0; i--) {
			while (!s.empty()) {
				int u = s.top().first;
				if (T[i] >= u)
					s.pop();
				else
					break;
			}
			if (s.empty()) 
				ans[i] = 0;
			else
				ans[i] = s.top().second - i;
			s.push({ T[i], i });
		}
		return ans;
	}
};

int main() {
	vector<int> v = { 89,62,70,58,47,47,46,76,100,70 };
	Solution s;
	s.dailyTemperatures(v);
}