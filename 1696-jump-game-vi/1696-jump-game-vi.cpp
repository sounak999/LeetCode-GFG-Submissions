class Solution {
public:
    int maxResult(vector<int>& nums, int k) 
    {
	    vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        multiset<int> s;
        s.insert(dp[0]);
        
	    for(int i = 1; i < size(nums); i++) 
        {
            if(i > k) 
            {
                auto it = s.find(dp[i-1-k]);
                s.erase(it);
            }
            
            dp[i] = *rbegin(s) + nums[i];
            s.insert(dp[i]);
        }
        
	    return dp.back();
    }
};