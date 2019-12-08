from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        result = []
        n = len(nums)
        for i in range(len(nums)):
            if(nums[i] <= n):
                index = nums[i] - 1
            else:
                index = nums[i] - n - 1
            if(nums[index] > n):
                result.append(index+1)
            else:
                nums[index] += n
        return result


s = print(Solution().findDuplicates([10, 2, 5, 10, 9, 1, 1, 4, 3, 7]))
