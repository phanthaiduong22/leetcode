#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int v) {
		val = v;
		next = NULL;
	}
};

class LRUCache {
public:
	map<int, int> m;
	Node* H = NULL;
	Node* T = NULL;
	int c = 0;
	int s = 0;
	LRUCache(int capacity) {
		this->c = capacity;
	}

	int get(int key) {
		map<int, int>::iterator it;
		it = m.find(key);
		if (it == m.end()) return -1;
		if (m[key] == -1) return m[key];
		//cout << m[key] << endl;
		Node* temp = new Node(H->val);
		T->next = temp;
		T = T->next;
		H = H->next;
		return m[key];
	}

	void put(int key, int value) {
		if (s < c) {
			s++;
			m[key] = value;
			if (H == NULL) {
				H = new Node(key);
				T = H;
			}
			else {
				T->next = new Node(key);
				T = T->next;
			}
		}
		else {
			map<int, int>::iterator it;
			it = m.find(key);
			if (it != m.end() && m[key] != -1) {
				m[key] = value;

			}
			else {
				m[H->val] = -1;
				m[key] = value;
				T->next = new Node(key);
				H = H->next;
				T = T->next;
			}
		}
	}
};


int main() {
	LRUCache cache(2);

	cache.get(2);
	cache.put(2, 6);
	cache.get(1);
	cache.put(1, 5);
	cache.put(1, 2);
	cache.get(1);
	cache.get(2);

}