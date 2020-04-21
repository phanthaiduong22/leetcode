#include <iostream>
#include <vector>

using namespace std;

class BinaryMatrix {
public:
	vector<vector<int>> v = {
		{1}
	};
	int get(int x, int y) {
		return v[x][y];
	}
	vector<int> dimensions() {
		return vector<int>{1, 1};
	}
};


class Solution {
public:
	int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
		vector<int> temp = binaryMatrix.dimensions();
		int n = temp[0], m = temp[1];
		int min = m;
		for (int i = 0; i < n; i++) {
			int l = 0, r = m - 1;
			while (l <= r) {
				int mid = r + (l - r) / 2;
				if (binaryMatrix.get(i, mid) == 1)
					r = mid - 1;
				else
					l = mid + 1;
			}
			if (l < min)
				min = l;
		}
		if (min == m) return -1;
		return min;
	}
};

int main() {
	Solution s;
	BinaryMatrix v;
	cout << s.leftMostColumnWithOne(v);
}

