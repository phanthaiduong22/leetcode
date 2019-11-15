class Solution:
    def addBinary(self, a: str, b: str) -> str:
        sum =""
        if(len(a)<len(b)):
           for i in range(len(b)-len(a)):
               a = "0" + a
        else:
            for i in range(len(a)-len(b)):
                b = "0" + b
        cnt = 0        
        for i in range(max(len(a),len(b))-1,-1,-1):
            if(a[i]=="1" and b[i]=="1"):
                if cnt == 1:
                    sum+="1"
                else:
                    sum+="0"
                    cnt = 1
            elif(a[i]=="1" or b[i]=="1"):
                if cnt == 1:
                    sum+="0"
                    cnt = 1
                else:
                    sum+="1"
            else:
                if cnt == 1:
                    sum+="1"
                    cnt = 0
                else:
                    sum+="0"
        if(cnt==1):
            sum+="1"
        return sum[::-1]
s = Solution()
print(s.addBinary("1010", "1011"))