#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
	vector<int>a;
	vector<int>sum;
	NumArray(vector<int>& nums) {
		a = nums;
		sum.push_back(0);
		int s = 0;
		for (int i = 0; i < nums.size(); i++) {
			s += nums[i];
			sum.push_back(s);
		}
	}
	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
};


int main() {
	vector<int> v = { -2, 0, 3, -5, 2, -1 };
	NumArray a(v);
	cout << a.sumRange(0, 2);
	cout << a.sumRange(2, 5);
	cout << a.sumRange(0, 5);
}