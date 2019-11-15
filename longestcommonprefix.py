from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        s = ""
        pump = 1
        if(len(strs) == 0):
            return ""
        for i in range(len(strs[0])):
            ans = 1
            for j in strs:
                if(i < len(j)):
                    if(j[i] != strs[0][i]):
                        ans = 0
                        pump = 0
                        break
                else:
                    ans = 0
                    pump = 0
                    break
            if ans == 1:
                s += strs[0][i]
            if pump == 0:
                break
        return s


solution = Solution()
print(solution.longestCommonPrefix([]))
