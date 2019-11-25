from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = {}
        ans = []
        for i in range(len(numbers)):
            if(numbers[i] in d):
                ans.append(d[numbers[i]]+1)
                ans.append(i +1)
                return ans
            else:
                d.update({target - numbers[i]: i})
        return []


s = Solution()
print(s.twoSum([2, 7, 11, 15], 9))

sum
