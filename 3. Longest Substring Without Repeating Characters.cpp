#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int i = 0, j = 0, l = s.size(), ans = 0;
//		map<char, int>d;
//		while (i < l) {
//			d[s[i]]++;
//			while (d[s[i]] > 1) {
//				d[s[j]]--;
//				j++;
//			}
//			i++;
//			ans = max(ans, i - j);
//		}
//		return ans;
//	}
//};

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int i = 0, j = 0, l = s.size(), ans = 0;
//		map<char, int>d;
//		while (i < l) {
//			if (d[s[i]] == 0) {
//				d[s[i]] = i + 1;
//			}
//			else {
//				j = max(j, d[s[i]]);
//				d[s[i]] = i + 1;
//			}
//			ans = max(ans, i - j + 1);
//			i++;
//		}
//		return ans;
//	}
//};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i = 0, j = 0, l = s.size(), ans = 0;
		map<char, int>d;
		while (i < l) {
			j = max(j, d[s[i]]);
			d[s[i]] = i + 1;
			ans = max(ans, i - j + 1);
			i++;
		}
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.lengthOfLongestSubstring("tmmzuxt");
}