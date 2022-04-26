class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        for(int i=0; i<nums1.size(); i++)
            if(find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
                ans.insert(nums1[i]);
               
        vector<int> ans2(ans.begin(), ans.end());
        return ans2;
    }
};