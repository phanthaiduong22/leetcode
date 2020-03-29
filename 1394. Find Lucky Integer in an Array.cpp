#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	int findLucky(vector<int>& arr) {
		map<int, int>d;
		for (int i = 0; i < arr.size(); i++) {
			d[arr[i]] ++;
		}
		int max = -1;
		map<int, int>::iterator it;
		for (it = d.begin(); it != d.end(); it++) {
			if (it->first == it->second && it->first > max)
				max = it->first;
		}
		return max;
	}
};

int main() {
	vector<int> v = { };
	Solution s;
	cout << s.findLucky(v);
}