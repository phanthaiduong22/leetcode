class Solution:
    def countAndSay(self, n: int) -> str:
        s = str(n)
        ans = ["1"]
        for i in range(1, n):
            temp = ans[i-1][0]
            sum = ""
            for j in range(1,len(ans[i-1])):
                if(ans[i-1][j]==ans[i-1][j-1]):
                    temp+=ans[i-1][j]
                else:
                    sum += str(len(temp))
                    sum += temp[0]
                    temp = ans[i-1][j]
            if temp:
                sum+=str(len(temp))
                sum+=temp[0]
            ans.append(sum)
        return ans[n-1]

solution = Solution()
print(solution.countAndSay(6))


