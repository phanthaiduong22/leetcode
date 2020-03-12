#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		map<int, int>d;
		for (int i = 0; i < s.size(); i++) {
			d[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++) {
			d[t[i] - 'a']--;
		}
		map<int, int>::iterator it;
		for (it = d.begin(); it != d.end(); it++) {
			if (it->second > 0)
				return false;
		}
		return true;
	}
};
int main() {

}