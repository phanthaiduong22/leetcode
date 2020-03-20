class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>d1, d2;
        for (int i = 0; i < nums1.size(); i++)
            d1[nums1[i]]++;
        vector<int>ans;
        for (int i = 0; i < nums2.size(); i++)
            if (d1[nums2[i]] > 0 && d2[nums2[i]] == 0) {
                ans.push_back(nums2[i]);
                d2[nums2[i]]++;
            }
        return ans;
    }
};