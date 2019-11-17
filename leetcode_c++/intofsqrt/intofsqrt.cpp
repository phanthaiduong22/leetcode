#include <iostream>

using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    int left = 0;
    int right = n;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid * mid == n)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < n)
        {
            left = mid+1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (ans == 0)
        cout << left-1;
    else
        cout << ans;
}