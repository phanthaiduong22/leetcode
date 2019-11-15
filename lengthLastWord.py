class Solution:

    def lengthOfLastWord(self, s: str) -> int:
        ans = 0
        size = len(s)
        if(size==0):
            return 0
        while(s[size-1]==" " ):
            size -=1
            if(size==0):
                return 0
        if(size==0):
            return 0
        for i in range(size):
            if(s[i]==" "):
                ans = 0
            else:
                ans+=1
        return ans

s = Solution()
print(s.lengthOfLastWord("hello worl"))