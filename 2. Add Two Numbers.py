# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        a = ""
        b = ""
        while l1:
            a = str(l1.val) + a
            l1 = l1.next
        while l2:
            b = str(l2.val) + b
            l2 = l2.next
        sum = int(a)+int(b)
        #
        ans = ListNode(sum % 10)
        sum = sum//10
        # remember the head
        remember = ans
        if(sum > 0):
            for i in range(len(str(sum)), 0, -1):
                ans.next = ListNode(sum % 10)
                sum = sum//10
                ans = ans.next
        return remember


a = ListNode(1)
a.next = ListNode(8)

b = ListNode(0)
# b.next = ListNode(6)
# b.next.next = ListNode(4)

s = Solution().addTwoNumbers(a, b)
