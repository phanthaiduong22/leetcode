#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;
        while (l <= r)
        {
            ans = max(ans, min(height[r], height[l]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<int> c = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << a.maxArea(c);
}