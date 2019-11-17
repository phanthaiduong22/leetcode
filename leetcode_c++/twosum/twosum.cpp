#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> s;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
            {
                ans.push_back(s[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else
            {
                s[target - nums[i]] = i;
            }
        }
        return ans;
    }
};