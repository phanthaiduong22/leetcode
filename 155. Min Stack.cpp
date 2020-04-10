#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	stack<pair<int, int>>a;
	int minNow;
	MinStack() {
		minNow = 2147483647;
	}

	void push(int x) {
		if (x < minNow) minNow = x;
		a.push({ x,minNow });
	}

	void pop() {
		if (a.size() != 0) 
			a.pop();
		if (a.size() != 0)
			minNow = a.top().second;
		else
			minNow = 2147483647;
	}

	int top() {
		return a.top().first;
	}

	int getMin() {
		return a.top().second;
	}
};


int main() {
	MinStack minStack = MinStack();
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin();  // -- > Returns - 3.
	minStack.pop();
	cout << minStack.top();     // -- > Returns 0.
	cout << minStack.getMin();  // -- > Returns - 2.
}