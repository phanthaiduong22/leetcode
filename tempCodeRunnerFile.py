                temp = remember
            elif n < 0:
                temp = temp.next
            head = head.next
            n -= 1
        if(n == 0):
            return head.next
        else:
            temp.next = temp.next.next
            return remember