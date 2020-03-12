#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrime(n, true);
		int ans = 0;
		if (n <= 2) return 0;
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i < n; i++) {
			if (isPrime[i] == true) {
				for (int j = i * i; j < n; j += i) {
					isPrime[j] = false;
				}
			}
		}
		for (int i = 2; i < n; i++)
			if (isPrime[i] == true)
				ans++;
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.countPrimes(3);
}