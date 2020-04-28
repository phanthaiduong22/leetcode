#include <iostream>
#include <vector>
#include <map>;
#include <queue>;
using namespace std;

class FirstUnique {
public:
	map<int, int>d;
	queue<int>q;
	FirstUnique(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (d[nums[i]] == 0) {
				q.push(nums[i]);
				d[nums[i]]++;
			}
			else if (d[nums[i]] == 1) {
				d[nums[i]]++;
			}
			else {
				if (!q.empty()) {
					int u = q.front();
					if (u == nums[i])
						q.pop();

				}
			}
		}
	}

	int showFirstUnique() {
		int u;
		if (!q.empty())
			u = q.front();
		while (d[u] == 2) {
			q.pop();
			if (!q.empty())
				u = q.front();
			else break;
		}
		if (q.empty()) return -1;
		else return u;
	}

	void add(int value) {
		if (d[value] == 0) {
			q.push(value);
			d[value]++;
		}
		else if (d[value] == 1) {
			d[value]++;
		}
		else {
			if (!q.empty()) {
				int u = q.front();
				if (u == value)
					q.pop();
			}
		}
	}
};

int main() {
	vector<int> v = { 809 };

	FirstUnique firstUnique = FirstUnique(v);
	cout << firstUnique.showFirstUnique(); // return 809
	firstUnique.add(809);          // the queue is now [809,809]
	cout << firstUnique.showFirstUnique(); // return -1

}
