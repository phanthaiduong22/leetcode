from typing import List
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        return 2*(sum(nums))

s = Solution()
print(s.singleNumber([4,1,2,1,2]))