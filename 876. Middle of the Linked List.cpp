#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		int size = 0;
		ListNode* temp = head;
		while (temp) {
			size++;
			temp = temp->next;
		}
		size = size / 2;
		while (size) {
			head = head->next;
			size--;
		}
		return head;
	}
};

int main() {
	ListNode* root = new ListNode(1);
	Solution s;
	ListNode* ans = s.middleNode(NULL);

}