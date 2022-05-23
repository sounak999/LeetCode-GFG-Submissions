class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(auto x: nums1)
            s.insert(x);
            
        vector<int> ans;
        
        unordered_set<int> s2;
        for(auto x: nums2)
            s2.insert(x);
        
        for(auto x: s2)
        {
            if(s.find(x) != s.end())
                ans.push_back(x);
        }
        
        return ans;
    }
};