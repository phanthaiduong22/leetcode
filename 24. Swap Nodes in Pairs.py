# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if(head==None):
            return None
        remember = head
        while(head.next != None):
            temp = head.next.val
            head.next.val = head.val
            head.val = temp
            head = head.next.next
            if(head == None):
                return remember
        return remember

s = Solution().swapPairs(None)
print(s)
