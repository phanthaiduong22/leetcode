class Solution:
    def titleToNumber(self, s: str) -> int:
        ans = 0
        for i in range(len(s)-1, -1, -1):
            print(ord(s[i])-64)
            ans = ans+(ord(s[i])-64)*(26**(len(s)-i-1))
        return ans


s = Solution()
print(s.titleToNumber("A"))
