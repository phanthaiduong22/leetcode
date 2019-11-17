# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode(-1)
        head = ans
        while(l1 or l2):
            if(l1 and l2):
                if(l1.val < l2.val):
                    ans.next = ListNode(l1.val)
                    ans = ans.next
                    l1 = l1.next
                else:
                    ans.next = ListNode(l2.val)
                    ans = ans.next
                    l2 = l2.next
            elif(l1):
                ans.next = ListNode(l1.val)
                ans = ans.next
                l1 = l1.next
            elif(l2):
                ans.next = ListNode(l2.val)
                ans = ans.next
                l2 = l2.next
        return head.next


l2 = ListNode(1)
l2.next = ListNode(2)
l2.next.next = ListNode(4)
l1 = ListNode(1)
l1.next = ListNode(3)
l1.next.next = ListNode(4)
s = Solution()
s.mergeTwoLists(l1, l2)
