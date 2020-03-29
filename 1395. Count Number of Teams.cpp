#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
	int numTeams(vector<int>& rating) {
		int s = rating.size();
		int ans = 0;
		for (int i = 0; i < s - 2; i++) {
			for (int j = i + 1; j < s - 1; j++) {
				for (int k = j + 1; k < s; k++) {
					if (rating[i] < rating[j] && rating[j] < rating[k])
						ans++;
					if (rating[i] > rating[j] && rating[j] > rating[k])
						ans++;
				}
			}
		}
		return ans;
	}
};

int main() {
	vector<int> rating = {  };
	Solution s;
	cout << s.numTeams(rating);
}