class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        cnt = 1
        ans = []
        for i in range(len(digits)-1,-1,-1):
            if(digits[i]+cnt>9):
                ans.append(0)
            else:
                ans.append(digits[i]+cnt)
                cnt = 0
        if(cnt>0):
            ans.append(1)
        ans.reverse()
        return ans          