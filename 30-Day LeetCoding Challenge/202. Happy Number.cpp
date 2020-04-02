#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		if (n <= 0) return false;
		map<int, int>d;
		while (d[n] == 0) {
			d[n]++;
			if (n == 1) return true;
			else {
				string temp = to_string(n);
				int temp_num = 0;
				for (int i = 0; i < temp.size(); i++)
					temp_num += ((temp[i] - '0') * (temp[i] - '0'));
				n = temp_num;
			}
		}
		return false;

	}
};

int main() {
	Solution s;
	cout << s.isHappy(7);
}