from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        a = [[1 for x in range(y+1)] for y in range(0, rowIndex + 1)]
        for i in range(0, rowIndex + 1):
            for j in range(i):
                if j != 0 and j != rowIndex:
                    a[i][j] = a[i-1][j-1] + a[i-1][j]
        return a[rowIndex]


s = Solution()
print(s.getRow(3))
