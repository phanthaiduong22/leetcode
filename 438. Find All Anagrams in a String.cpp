#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		if (s.size() < p.size()) return  ans;
		int sum = 0, sum1 = 0;
		for (int i = 0; i < p.size(); i++)
			sum += (p[i] - 'a');
		for (int i = 0; i < p.size(); i++) {
			sum1 += (s[i] - 'a');
		}
		if (sum == sum1) ans.push_back(0);
		for (int i = 0; i < s.size() - p.size(); i++) {
			sum1 = sum1 - s[i] + s[i + p.size()];
			if (sum1 == sum) ans.push_back(i + 1);
		}
		return ans;
	}
};

int main() {
	Solution s;
	string v = "af";
	string p = "be";
	s.findAnagrams(v, p);
}