#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    long long reverse(long long x)
    {
        long long temp1 = abs(x);
        long long len = 0;
        while (temp1)
        {
            len++;
            temp1 /= 10;
        }
        long long temp = abs(x);
        long long product = pow(10, len - 1);
        long long ans = 0;
        while (temp > 0)
        {
            ans += (temp % 10) * product;
            product /= 10;
            temp = temp / 10;
        }
        if (ans > 2147483647 || ans < -2147483647)
            return 0;
        if (x > 0)
            return ans;
        else
        {
            return -ans;
        }
    }
};

int main()
{
    Solution a;
    cout << a.reverse(1534236469);
}