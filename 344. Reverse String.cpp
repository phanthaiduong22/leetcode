#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int i = 0; i < s.size() / 2; i++) {
			swap(s[i], s[s.size() - i - 1]);
		}
	}
};

int main() {
	vector<char> v = {  };
	Solution s;
	s.reverseString(v);

}