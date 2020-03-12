#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		while (n > 1) {
			string s = to_string(n);
			long long temp = 0;
			for (int i = 0; i < s.size(); i++) {
				temp += ((s[i] - '0') * (s[i] - '0'));
			}
			n = temp;
		}
		return n == 1;
		//return (n - 1) % 9 == 0;
	}
};

int main() {
	Solution s;
	for (int i = 0; i < 200; i++) {
		cout << i << " " << s.isHappy(i) << endl;
	}
}