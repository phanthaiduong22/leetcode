#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		map<char, int>d;
		for (int i = 0; i < s.size(); i++)
			d[s[i]]++;
		for (int i = 0; i < s.size(); i++)
			if (d[s[i]] == 1) return i;
		return -1;
	}
};


int main() {
	string s = "";
	Solution a;
	cout << a.firstUniqChar(s);
}