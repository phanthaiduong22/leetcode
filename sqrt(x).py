import math
class Solution:
    def mySqrt(self, x: int) -> int:
        return math.trunc(math.sqrt(x))
s = Solution()
print(s.mySqrt(4))