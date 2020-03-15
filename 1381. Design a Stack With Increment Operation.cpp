#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class CustomStack {
public:
	vector<int>a;
	int capacity = 0;
	int s = 0;
	CustomStack(int maxSize) {
		capacity = maxSize;
	}

	void push(int x) {
		if (s < capacity) {
			s++;
			a.push_back(x);
		}
	}

	int pop() {
		if (!a.empty()) {
			int ans = a[a.size() - 1];
			s--;
			a.pop_back();
			return ans;
		}
		else
			return -1;
	}

	void increment(int k, int val) {
		for (int i = 0; i < k; i++) {
			if (i >= a.size())
				break;
			a[i] += val;
		}
	}
};

int main() {
	CustomStack customStack = CustomStack(1); // Stack is Empty []
	customStack.push(1);                          // stack becomes [1]
	customStack.push(2);                          // stack becomes [1, 2]
	customStack.increment(2, 100);
	cout << customStack.pop() << endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]
	cout << customStack.pop() << endl;                            // return 2 --> Return top of the stack 2, stack becomes [1]
}