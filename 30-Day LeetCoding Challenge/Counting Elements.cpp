#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	int countElements(vector<int>& arr) {
		//sort(arr.begin(), arr.end(), greater<int>());
		int ans = 0;
		map<int, int> d;
		for (int i = 0; i < arr.size(); i++)
			d[arr[i]]++;
		for (int i = 0; i < arr.size(); i++) {
			if (d[arr[i] + 1] > 0)
				ans++;
		}
		return ans;
	}
};

int main() {
	vector<int> v = { 1,1,3,3,5,5,7,7 };
	Solution s;
	cout << s.countElements(v);
}