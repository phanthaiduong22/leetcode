#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        int i = 0;
        int j = 1;
        int step = numRows * 2 - 2;
        int step1 = 0;
        string ans = "";
        if (s.size() == 1 || numRows)
            return s;
        while (ans.size() < s.size())
        {
            if (step > 0 && i < s.size())
            {
                ans += s[i];
                i += step;
            }
            if (step1 > 0 && i < s.size())
            {
                ans += s[i];
                i += step1;
            }
            if (i >= s.size())
            {
                i = j;
                j++;
                step -= 2;
                step1 += 2;
            }
        }
        return ans;
    }
};

int main()
{
    Solution a;
    cout << a.convert("AB", 1);
}