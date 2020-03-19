#include <iostream>
#include <string>

using namespace std;

#define MAX 26

struct Node {
	Node* child[MAX];
	int countWord;
	Node() {
		for (int i = 0; i < MAX; i++) {
			child[i] = NULL;
		}
		countWord = 0;
	}
};

class Trie {
public:
	/** Initialize your data structure here. */
	Node* root = new Node();
	Trie() {
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		int ch;
		Node* temp = root;
		for (int i = 0; i < word.size(); i++) {
			ch = word[i] - 'a';
			if (temp->child[ch] == NULL) {
				temp->child[ch] = new Node();
			}
			temp = temp->child[ch];
		}
		temp->countWord++;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		int ch;
		Node* temp = root;
		for (int i = 0; i < word.size(); i++) {
			ch = word[i] - 'a';
			if (temp->child[ch] == NULL)
				return false;
			temp = temp->child[ch];
		}
		return temp->countWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		int ch;
		Node* temp = root;
		for (int i = 0; i < prefix.size(); i++) {
			ch = prefix[i] - 'a';
			if (temp->child[ch] == NULL)
				return false;
			temp = temp->child[ch];
		}
		return true;
	}
};

int main() {
	Trie trie = Trie();

	trie.insert("appale");
	cout << trie.search("appale");   // returns true
	cout << trie.search("appa");     // returns false
	cout << trie.startsWith("app"); // returns true
	trie.insert("app");
	trie.search("app");
}