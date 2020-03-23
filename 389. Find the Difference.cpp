#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		map<char, int>d;
		for (int i = 0; i < s.size(); i++)
			d[s[i]]++;
		for (int i = 0; i < t.size(); i++) {
			d[t[i]]--;
			if (d[t[i]] < 0)
				return t[i];
		}
		return ' ';

	}
};

int main() {
	string s = "abcd";
	string t = "abcde";
	Solution a;
	cout << a.findTheDifference(s, t);
}