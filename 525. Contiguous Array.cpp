#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		map<int, int>d;
		int cnt = 0;
		int max = 0;
		d[0] = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0)
				cnt -= 1;
			else
				cnt += 1;
			map<int, int>::iterator it;
			it = d.find(cnt);
			if (it == d.end())
				d[cnt] = i + 1;
			else {
				int temp = i - d[cnt] + 1;
				if (temp > max)
					max = temp;
			}
		}
		return max;
	}
};

int main() {
	vector<int>v = {};
	Solution s;
	cout << s.findMaxLength(v);
}