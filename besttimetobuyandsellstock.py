from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min = 99999
        max = 0
        for i in range(0, len(prices)):
            if prices[i] < min:
                min = prices[i]
            else:
                if(prices[i]-min > max):
                    max = prices[i] - min
        return max


s = Solution()
print(s.maxProfit([1,2]))
