from typing import List
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if(nums[i]>=target):
                return i
        return len(nums)

solution = Solution()
print(solution.searchInsert([1,3,5,6], 0))
