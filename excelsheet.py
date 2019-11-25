class Solution:
    def convertToTitle(self, n: int) -> str:
        ans = ""
        while n:
            temp = n % 26
            if temp != 0:
                ans = str(chr(64+temp))+ans
                n = n // 26
            else:
                ans = "Z"+ans
                n = n//26-1
        return ans


s = Solution()
print(s.convertToTitle(28))
