#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		vector<vector<int>>L(m + 1, vector<int>(n + 1));
		for (long long i = 0; i <= m; i++)
			for (long long j = 0; j <= n; j++)
				if (i == 0 || j == 0)
					L[i][j] = 0;
				else if (text1[i - 1] == text2[j - 1])
					L[i][j] = L[i - 1][j - 1] + 1;
				else
				{
					L[i][j] = max(L[i - 1][j], L[i][j - 1]);
				}
		return L[m][n];
	}
};

int main() {
	Solution s;
	cout << s.longestCommonSubsequence("abcde", "ace");
}