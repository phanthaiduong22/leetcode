#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int i = 0;
		int j = 0;
		map<char, string>d;
		map<string, char>d2;
		str += " ";
		string temp;
		while (j < str.size()) {
			if (str[j] != ' ') {
				temp += str[j];
			}
			else {
				if (d[pattern[i]] == "" && d2[temp] == '\0') {
					d[pattern[i]] = temp;
					d2[temp] = pattern[i];
					temp = "";
					i++;
				}
				else if (d[pattern[i]] != temp || d2[temp] != pattern[i])
					return false;
				else if (d[pattern[i]] == temp) {
					temp = "";
					i++;
				}
				else
					return false;
			}
			j++;
		}
		return i == pattern.size();
	}
};

int main() {
	Solution s;
	cout << s.wordPattern("abba", "dog cat cat dog");
}