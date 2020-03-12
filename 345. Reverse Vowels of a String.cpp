#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int i = 0;
		int j = s.size() - 1;
		while (i < j) {
			if ((s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I') && (s[j] == 'u' || s[j] == 'e' || s[j] == 'o' || s[j] == 'a' || s[j] == 'i' || s[j] == 'U' || s[j] == 'E' || s[j] == 'O' || s[j] == 'A' || s[j] == 'I')) {
				char temp = s[i];
				s[i] = s[j];
				s[j] = temp;
				i++;
				j--;
			}
			else if ((s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'a' || s[i] == 'i' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I') && (s[j] != 'u' && s[j] != 'e' && s[j] != 'o' && s[j] != 'a' && s[j] != 'i' && s[j] != 'U' && s[j] != 'E' && s[j] != 'O' && s[j] != 'A' && s[j] != 'I'))
				j--;
			else
				i++;
		}
		return s;
	}
};

int main() {
	Solution s;
	cout << s.reverseVowels("leetcode");
}