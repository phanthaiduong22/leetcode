#include <iostream>
#include <queue>

using namespace std;


class MyStack {
public:
	/** Initialize your data structure here. */
	queue<int>q;
	int size = 0;
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q.push(x);
		size++;
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int i = 0;
		while (i < size - 1) {
			q.push(q.front());
			q.pop();
			i++;
		}
		int u = q.front();
		q.pop();
		size--;
		return u;
	}

	/** Get the top element. */
	int top() {
		int i = 0;
		while (i < size - 1) {
			q.push(q.front());
			q.pop();
			i++;
		}
		int u = q.front();
		q.push(u);
		q.pop();
		return u;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return size == 0;
	}
};

int main() {
	MyStack stack = MyStack();

	stack.push(1);
	stack.push(2);
	cout << stack.top();   // returns 2
	cout << stack.pop();   // returns 2
	cout << stack.empty(); // returns false
}