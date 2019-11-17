#include <iostream>
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))
using namespace std;
class Solution
{
public:
    double myPow(double x, long n)
    {
        double ans = 1.0;
        if (n < 0)
        {
            x = 1 / x;
            n = abs(n);
        }
        while (n)
        {
            if (n & 1)
                ans *= x;
            x *= x;
            n = (n >> 1);
        }
        return ans;
    }
};

int main()
{
    Solution a;
    cout << a.myPow(2.00000, -2);
}