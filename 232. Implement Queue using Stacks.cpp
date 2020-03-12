#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	stack<int>s;
	int size = 0;
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s.push(x);
		size++;
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int i = 0;
		stack<int>temp;
		while (i < size - 1) {
			temp.push(s.top());
			s.pop();
			i++;
		}
		int u = s.top();
		s.pop();
		size--;
		while (!temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}
		return u;
	}

	/** Get the front element. */
	int peek() {
		int i = 0;
		stack<int>temp;
		while (i < size - 1) {
			temp.push(s.top());
			s.pop();
			i++;
		}
		int u = s.top();
		while (!temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}
		return u;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return size == 0;
	}
};

int main() {
	MyQueue queue = MyQueue();

	queue.push(1);
	queue.push(2);
	cout << queue.peek();  // returns 1
	cout << queue.pop();   // returns 1
	cout << queue.empty(); // returns false
}