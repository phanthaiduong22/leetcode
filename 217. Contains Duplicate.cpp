#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int>d;
        for (int i = 0; i < nums.size(); i++) {
            d[nums[i]]++;
            if (d[nums[i]] >= 2)
                return true;
        }
        return false;
    }
};

int main() {
        
}