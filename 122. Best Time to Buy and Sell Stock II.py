from typing import List
import math


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        min = prices[0]
        max = 0
        ans = 0
        for i in range(1, len(prices)):
            if(prices[i] > prices[i-1]):
                if(prices[i] < min):
                    min = prices[i]
                if(prices[i] > max):
                    max = prices[i]
            else:
                ans += (max - min) if max - min > 0 else 0
                min = prices[i]
                max = 0
        ans += (max - min) if max - min > 0 else 0
        return ans
