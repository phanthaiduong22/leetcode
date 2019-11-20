class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.a = []
        

    def push(self, x: int) -> None:
        new_min = x
        if self.a:
            current_min = self.getMin()
            new_min = x if(x<current_min) else current_min
        self.a.append((x,new_min))

    def pop(self) -> None:
        self.a.pop()

    def top(self) -> int:
        return self.a[-1][0]

    def getMin(self) -> int:
        return self.a[-1][1]
        
        
#Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
print(obj.getMin())
obj.pop()
print(obj.top())
print(obj.getMin())