    #include <iostream>
    #include <vector>
    #include <unordered_map>
    #include <string>

    using namespace std;
    class Solution
    {
    public:
        string longestPalindrome(string s)
        {
            int max = 1, left = 0, right = 0;
            int n = s.length();
            string ans2 = s[0];
            for (int i = 0; i < s.length(); i++)
            {
                int j = i - 1, k = i + 1;
                int ans = 1;
                while (j >= 0 && k <= n - 1)
                {
                    if (s[j] == s[k])
                        ans += 2;
                    else
                    {
                        break;
                    }
                    j--;
                    k++;
                }
                if (ans > max)
                {
                    max = ans;
                    left = j;
                    right = k;
                }
                if (i >= 1)
                    if (s[i] == s[i - 1])
                    {
                        ans = 2;
                        int j = i - 2, k = i + 1;
                        while (j >= 0 && k <= n - 1)
                        {

                            if (s[j] == s[k])
                                ans += 2;
                            else
                            {
                                break;
                            }
                            j--;
                            k++;
                        }
                        if (ans > max)
                        {
                            max = ans;
                            left = j;
                            right = k;
                        }
                    }
            }
            if (max == 1)
                return ans2;
            else
            {
                string s_ans = "";
                for (int i = left + 1; i <= right - 1; i++)
                {
                    s_ans += s[i];
                }
                return s_ans;
            }
        }
    };

    int main()
    {
        Solution a;
        cout << a.longestPalindrome("babad");
    }