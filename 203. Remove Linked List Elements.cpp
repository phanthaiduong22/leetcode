#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL) return head;
		ListNode* remember = head;
		while (head->val == val) {
			remember = head->next;
			head = head->next;
			if (head == NULL)
				return NULL;
		}
		while (head->next != NULL) {
			if (head->next->val == val)
				head->next = head->next->next;
			else
				head = head->next;
			if (head == NULL)
				break;
		}
		return remember;
	}
};

int main() {
	Solution s;
	ListNode* v = new ListNode(6);
	ListNode* ans = s.removeElements(v, 7);
}