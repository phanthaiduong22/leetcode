class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for i in s:
            if(len(st)>0):
                if (i == ")" and st[len(st)-1] == "("):
                    st.pop()
                elif (i == "}" and st[len(st)-1] == "{"):
                    st.pop()
                elif (i == "]" and st[len(st)-1] == "["):
                    st.pop()
                else:
                    st.append(i)
            else:
                st.append(i)
        return len(st) == 0
solution = Solution()
print(solution.isValid(s = "([)"))