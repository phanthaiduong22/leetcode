# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        remember = head
        while(head):
            if n == 0:
                temp = remember
            elif n < 0:
                temp = temp.next
            head = head.next
            n -= 1
        if(n == 0):
            return remember.next
        else:
            temp.next = temp.next.next
            return remember


x = ListNode(1)
x.next = ListNode(2)
s = Solution().removeNthFromEnd(x, 2)
print(s)
