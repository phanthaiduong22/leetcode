#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* ans;
	ListNode* remember;
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}
		if (head->next != NULL) {
			reverseList(head->next);
			ans->next = new ListNode(head->val);
			ans = ans->next;
		}
		else {
			ans = new ListNode(head->val);
			remember = ans;
		}
		return remember;
	}
};

int main() {
	ListNode* v = new ListNode(1);
	v->next = new ListNode(2);
	v->next->next = new ListNode(3);
	v->next->next->next = new ListNode(4);
	v->next->next->next->next = new ListNode(5);

	Solution s;
	ListNode* ans = s.reverseList(v);
}