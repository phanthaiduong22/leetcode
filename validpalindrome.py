import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        pattern = '[ -/ :-@ [-` ~]'
        replace = ''
        new_string = re.sub(pattern, replace, s).lower()
        print(new_string)
        print(new_string[::-1])
        return new_string == new_string[::-1]


s = Solution()
print(s.isPalindrome("0P"))
