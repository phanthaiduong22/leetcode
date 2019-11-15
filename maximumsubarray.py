from typing import List
class Solution:
    def maxSubArray(self, nums: List[int])->int :
        if(len(nums)==0):
            return 0
        min = 0
        max = nums[0]
        sum = 0
        for i in range(1,len(nums)):
            if(sum + nums[i]< min):
                min = sum + nums[i]x
            if(sum + nums[i]> max):
                max = sum + nums[i]
            sum +=nums[i]
        return max - min

s = Solution()
print(s.maxSubArray([5,6]))