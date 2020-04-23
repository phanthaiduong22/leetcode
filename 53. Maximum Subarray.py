from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = nums[0]
        for i in range(1, len(nums)):
            if(nums[i-1] > 0):
                nums[i] = nums[i-1]+nums[i]
            ans = max(nums[i], ans)
        return ans
