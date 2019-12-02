import math


class Solution:
    def trailingZeroes(self, n: int) -> int:
        if n<5:
            return 0 
        ans = 0
        for i in range(1, math.floor(math.log(n)/math.log(5))+1):
            ans += math.floor(n/(5**i))
        return int(ans)


print(Solution().trailingZeroes(92))
