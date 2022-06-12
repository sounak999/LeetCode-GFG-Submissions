class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, curSum = 0, ans = 0;
        unordered_set<int> st;
        while(r < n)
        {
            while(st.find(nums[r]) != st.end())
            {
                curSum -= nums[l];
                st.erase(nums[l++]);
            }
            
            curSum += nums[r];
            st.insert(nums[r++]);
            ans = max(curSum, ans);
        }
        
        return ans;
    }
};