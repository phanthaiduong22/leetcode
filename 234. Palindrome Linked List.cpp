#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int ans = 1;
	queue<int> q;
	void recursionNode(ListNode* head) {
		if (head != NULL) {
			q.push(head->val);
			recursionNode(head->next);
			if (ans == 0) return;
			if (head->val != q.front()) {
				ans = 0;
				return;
			}
			else q.pop();
		}
	}
	bool isPalindrome(ListNode* head) {
		recursionNode(head);
		return ans;
	}
};

int main() {
	Solution s;
	ListNode* v = NULL;
	cout << s.isPalindrome(v);
}