#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    long long myAtoi(string str)
    {
        long long product = 1;
        long long ans = 0;
        long long isPositive = 1;
        bool nomore = false;
        for (long long i = 0; i < str.size(); i++)
        {
            if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
            {
                ans = product * ans + (str[i] - '0');
                if (product == 1)
                    product *= 10;
                nomore = true;
            }
            else if (str[i] == '-' && nomore == false)
            {
                isPositive = -1;
                nomore = true;
            }
            else if (str[i] == '+' && nomore == false)
            {
                isPositive == 1;
                nomore = true;
            }
            else if (str[i] == ' ' && nomore == false)
            {
                continue;
            }
            else
            {
                break;
            }
            if (ans < -(1LL << 31) || ans > (1LL << 31) - 1)
            {
                if (isPositive == 1)
                    return (1LL << 31) - 1;
                else
                {
                    return -(1LL << 31);
                }
            }
        }
        return isPositive * ans;
    }
};
int main()
{
    Solution a;
    cout << a.myAtoi("+-2");
}