#include <iostream>
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1 << 31))
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long dd = abs((long long)dividend);
        long long d = abs((long long)divisor);
        int sign;
        if (((long long)dividend * divisor) > 0)
            sign = 1;
        else
            sign = -1;
        long long q = 0;
        while (dd >= d)
        {
            int qb = 0;
            while (d * (1 << (qb + 1)) <= dd)
            {
                qb++;
                if (qb == 30)
                    break;
            }
            q += (1 << qb);
            dd -= (d * (1 << qb));
        }
        if (sign * q <= INT_MAX && sign * q >= INT_MIN)
            return sign * q;
        return INT_MAX;
    }
};

int main()
{
    Solution a;
    cout << a.divide(2147483647, 1);
    cout << a.divide(10, 3);
}