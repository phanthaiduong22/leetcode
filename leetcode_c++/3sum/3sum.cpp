#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, pair<int, int>> d;
        vector<vector<int>> result;
        int len = nums.size();
        int nomorezero = 0;
        for (int i = 1; i < len; i++)
            for (int j = 0; j < i; j++)
            {
                vector<int> ans;
                int x = nums[i];
                int y = nums[j];
                int z = 0 - x - y;
                if (d.find(x) != d.end())
                {
                    if (d[x].first == y)
                    {
                        if (d[x].first == 0 && d[x].second == 0 && x == 0)
                        {
                            if (nomorezero == 0)
                            {
                                ans.push_back(d[x].first);
                                ans.push_back(d[x].second);
                                ans.push_back(x);
                                result.push_back(ans);
                                nomorezero = 1;
                            }
                        }
                        else
                        {
                            ans.push_back(d[x].first);
                            ans.push_back(d[x].second);
                            ans.push_back(x);
                            result.push_back(ans);
                        }
                    }
                }
                else
                {
                    d[z] = {y, x};
                }
            }
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> c = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = a.threeSum(c);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j];
        cout << endl;
    }
}