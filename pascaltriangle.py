from typing import List
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        a = [[1 for x in range(y+1)] for y in range(0,numRows)] 
        for i in range(0,numRows):
            for j in range(i):
                if j != 0 and j != numRows-1:
                    a[i][j] = a[i-1][j-1] + a[i-1][j]
        return a 

s = Solution()
print(s.generate(5))
